# First Let us import all the required modules.

# For linear algebra
import numpy as np 

# For data processing, CSV file I/O (e.g. pd.read_csv)
import pandas as pd 

# For plotting the Curves
import matplotlib.pyplot as plt

# Import the other modules required
from pathlib import Path
import os
from tqdm.notebook import tqdm
from scipy.integrate import solve_ivp

# Import the Optimiztion and Error minimization functions.
from scipy.optimize import minimize
from sklearn.metrics import mean_squared_log_error, mean_squared_error

%matplotlib inline

# Taking the input from the files as Train and Test DATA.
train = pd.read_csv('/kaggle/input/trainfinal/trainfinal.csv', parse_dates=['Date'])
test = pd.read_csv('/kaggle/input/testfinal/testfinal.csv' , parse_dates=['Date'])


#Defining functions for QUANTITIES SEIR.

# Susceptible equation
def dS_dt(S, I, R_t, T_inf):
    return -(R_t / T_inf) * I * S

# Exposed equation
def dE_dt(S, E, I, R_t, T_inf, T_inc):
    return (R_t / T_inf) * I * S - (T_inc**-1) * E

# Infected equation
def dI_dt(I, E, T_inc, T_inf):
    return (T_inc**-1) * E - (T_inf**-1) * I

# Recovered/deceased equation
def dR_dt(I, T_inf):
    return (T_inf**-1) * I

# Defining the function for SEIR model.
def SEIR_model(t, y, R_t, T_inf, T_inc):
    
    if callable(R_t):
        reproduction = R_t(t)
    else:
        reproduction = R_t
    
    S, E, I, R = y
    S_out = dS_dt(S, I, reproduction, T_inf)
    E_out = dE_dt(S, E, I, reproduction, T_inf, T_inc)
    I_out = dI_dt(I, E, T_inc, T_inf)
    R_out = dR_dt(I, T_inf)
    return [S_out, E_out, I_out, R_out]

T_inc = 5.2  # average incubation period
T_inf = 2.9  # average infectious period


# Load the population data into lookup dicts
pop_info = pd.read_csv('/kaggle/input/populaton1csv/population1.csv.csv')
country_pop = pop_info.query('Type == "Country/Region"')
province_pop = pop_info.query('Type == "Province/State"')
country_lookup = dict(zip(country_pop['Name'], country_pop['Population']))
province_lookup = dict(zip(province_pop['Name'], province_pop['Population']))

train['FatalityRate'] = train['Fatalities'] / train['ConfirmedCases']
train['Area'] = train['Province_State'].fillna(train['Country_Region'])
test['Area'] = test['Province_State'].fillna(test['Country_Region'])

# Remove the leaking data
train_full = train.copy()
train = train[train['Date'] < test['Date'].min()]

# Split the test into public & private
test_public = test[test['Date'] <= '2020-04-01']
test_private = test[test['Date'] > '2020-04-01']

# Use a multi-index for easier slicing
train_full.set_index(['Area', 'Date'], inplace=True)
train.set_index(['Area', 'Date'], inplace=True)
test_public.set_index(['Area', 'Date'], inplace=True)
test_private.set_index(['Area', 'Date'], inplace=True)


# Use a constant reproduction number
def eval_model_const(params, data, population, return_solution=False, forecast_days=0):
    R_0, cfr = params
    N = population
    n_infected = data['ConfirmedCases'].iloc[0]
    max_days = len(data) + forecast_days
    a, b, c, d = (N - n_infected)/ N, 0, n_infected / N, 0
               
    sol = solve_ivp(SEIR_model, [0, max_days], [a, b, c, d], args=(R_0, T_inf, T_inc),
                    t_eval=np.arange(0, max_days))
    
    y_pred_cases = np.diff((sol.y[2] + sol.y[3])*N, prepend=n_infected).cumsum()
    y_pred_cases = np.clip(y_pred_cases, 0, np.inf)
    y_true_cases = data['ConfirmedCases'].values
    y_pred_fat = np.clip(sol.y[3]*N, 0, np.inf) * cfr
    y_true_fat = data['Fatalities'].values
    
    optim_days = min(14, len(data))  # Days to optimise for
    weights = 1 / np.arange(1, optim_days+1)[::-1]  # Recent data is more heavily weighted
    
    msle_cases = mean_squared_log_error(y_true_cases[-optim_days:], y_pred_cases[-optim_days:], weights)
    msle_fat = mean_squared_log_error(y_true_fat[-optim_days:], y_pred_fat[-optim_days:], weights)
    msle_final = np.mean([msle_cases, msle_fat])
    
    if return_solution:
        return msle_final, sol
    else:
        return msle_final
    
    
    
# Use a Hill decayed reproduction number
def eval_model_decay(params, data, population, return_solution=False, forecast_days=0):
    R_0, cfr, k, L = params  
    N = population
    n_infected = data['ConfirmedCases'].iloc[0]
    max_days = len(data) + forecast_days
    a, b, c, d = (N - n_infected)/ N, 0, n_infected / N, 0
     
    # Hill decay. Initial values: R_0=2.2, k=2, L=50
    def time_varying_reproduction(t): 
        return R_0 / (1 + (t/L)**k)
            
    sol = solve_ivp(SEIR_model, [0, max_days], [a, b, c, d], args=(time_varying_reproduction, T_inf, T_inc),
                    t_eval=np.arange(0, max_days))
    
    y_pred_cases = np.diff((sol.y[2] + sol.y[3])*N, prepend=n_infected).cumsum()
    y_pred_cases = np.clip(y_pred_cases, 0, np.inf)
    y_true_cases = data['ConfirmedCases'].values
    y_pred_fat = np.clip(sol.y[3]*N, 0, np.inf) * cfr
    y_true_fat = data['Fatalities'].values
    
    optim_days = min(14, len(data))  # Days to optimise for
    weights = 1 / np.arange(1, optim_days+1)[::-1]  # Recent data is more heavily weighted
    
    msle_cases = mean_squared_log_error(y_true_cases[-optim_days:], y_pred_cases[-optim_days:], weights)
    msle_fat = mean_squared_log_error(y_true_fat[-optim_days:], y_pred_fat[-optim_days:], weights)
    msle_final = np.mean([msle_cases, msle_fat])
    
    if return_solution:
        return msle_final, sol
    else:
        return msle_final


# Fit a model on the full dataset (i.e. no validation)
def fit_model_full(area_name, initial_guess=[2.2, 0.02, 2, 50], 
                   bounds=((1, 20), (0.005, 0.15), (1, 3), (1, 100)), make_plot=True):
        
    train_data = train_full.loc[area_name].query('ConfirmedCases > 0')
    test_data = test_private.loc[area_name]
    
    try:
        population = province_lookup[area_name]
    except KeyError:
        population = country_lookup[area_name]
        
    cases_per_million = train_data['ConfirmedCases'].max() * 10**6 / population
    n_infected = train_data['ConfirmedCases'].iloc[0]
        
    if cases_per_million < 1 or area_name == 'US':  # Not sure where the single case in the "US" is
        return use_last_value(train_data, None, test_data)
                
    res_const = minimize(eval_model_const, [2.2, 0.02], bounds=((1, 20), (0.005, 0.15)),
                         args=(train_data, population, False),
                         method='L-BFGS-B')
    
    res_decay = minimize(eval_model_decay, initial_guess, bounds=bounds,
                         args=(train_data, population, False),
                         method='L-BFGS-B')
    
    dates_all = train_data.index.append(test_data.index)
    
    
    # If using a constant R number is better, use that model
    if res_const.fun < res_decay.fun:
        msle, sol = eval_model_const(res_const.x, train_data, population, True, len(test_data))
        res = res_const
        R_t = pd.Series([res_const.x[0]] * len(dates_all), dates_all)
    else:
        msle, sol = eval_model_decay(res_decay.x, train_data, population, True, len(test_data))
        res = res_decay
        
        # Calculate the R_t values
        t = np.arange(len(dates_all))
        R_0, cfr, k, L = res.x   
        R_t = pd.Series(R_0 / (1 + (t/L)**k), dates_all)
        
    sus, exp, inf, rec = sol.y
    
    y_pred = pd.DataFrame({
        'ConfirmedCases': np.diff((inf + rec) * population, prepend=n_infected).cumsum(),
        'Fatalities': np.clip(rec, 0, np.inf) * population * res.x[1]
    }, index=dates_all)
    
    y_pred_test = y_pred.iloc[len(train_data):]
    
    if make_plot:
        print(res.x)
                
        f = plt.figure(figsize=(8, 5)) 
        train_data['ConfirmedCases'].plot(label='Confirmed Cases (train)', c='g')
        y_pred.loc[train_data.index, 'ConfirmedCases'].plot(label='Cumulative modeled infections', c='r')
        y_pred.loc[test_data.index, 'ConfirmedCases'].plot(label='Cumulative modeled infections (forecast)', c='orange', linestyle='-')
        plt.legend(loc='best');
        R_t.plot(label='Reproduction number', c='c', linestyle='-', secondary_y=True)
        plt.legend(loc='best');


fresult=fit_model_full('Georgia')


#The 4 optimized parameters:-R_0, CFR, k & L of HILL DECAY function in this SEIR Model.
print(" 1.0. The Model Parameters are:-")
print(" 1.1. The Reproduction Number (Ro)  = 4.59406765")
print(" 1.2. The Case Fatality Rate(CFR)   = 0.04780403")
print(" 1.3. The Value of Constant(K)      = 2.99999753")
print(" 1.3. The Value of Constant(L)      = 28.25749439")


# Population size
N = 10617423 

#Initial No of infectives and setting the days.
n_infected = 2
max_days = 200

#Using the Value of the Reproduction Number obtained from Fitting we will find SEIR plots.
R_0 = 4.59406765  

# State at time = 0 for SEIR model
a = (N - n_infected)/ N
b = 0
c = n_infected / N
d = 0.

# Defining the Function to plot the S(t),E(t),I(t),R(t). 
def plot_model(solution, title='SEIR model'):
    sus, exp, inf, rec = solution.y

    f = plt.figure(figsize=(8,5)) 
    plt.plot(sus, 'b', label='Susceptible');
    plt.plot(exp, 'y', label='Exposed');
    plt.plot(inf, 'r', label='Infected');
    plt.plot(rec, 'c', label='Recovered/deceased');
    plt.title(title)
    plt.xlabel("Days", fontsize=10);
    plt.ylabel("Fraction of population", fontsize=10);
    plt.legend(loc='best');
    

sol = solve_ivp(SEIR_model, [0, max_days], [a, b, c, d], args=(R_0, T_inf, T_inc), 
                t_eval=np.arange(max_days))

plot_model(sol, 'SEIR Model')
print("Hence,The SEIR Model is fitted into the COVID 19 data of US State,GEORGIA. All the Model Parameters are estimated.")





    
        
