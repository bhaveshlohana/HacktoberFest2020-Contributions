# This Python 3 environment comes with many helpful analytics libraries installed

# First Let us import all the required modules.

# For linear algebra
import numpy as np 

# For data processing, CSV file I/O (e.g. pd.read_csv)
import pandas as pd 

# For plotting the Curves
import matplotlib.pyplot as pt

# For Statistcal Graphics
import seaborn as sns

# For Optimiztion and Integration 
from sklearn import preprocessing
from scipy.integrate import odeint
import time
from datetime import datetime
from scipy import integrate, optimize
import warnings
warnings.filterwarnings('ignore')

#Now,Let us import some ML libraries
import lightgbm as lgb
import xgboost as xgb
from xgboost import plot_importance, plot_tree
from sklearn.model_selection import RandomizedSearchCV, GridSearchCV
from sklearn import linear_model
from sklearn.metrics import mean_squared_error

# Taking the input file
train = pd.read_csv("../input/traincsv/train.csv")

# Creating the dataframes from the input file.
population = float(10617423)
country_df = pd.DataFrame()
country_df['ConfirmedCases'] = train.loc[train['Country_Region']=='Georgia'].ConfirmedCases.diff().fillna(0)
country_df = country_df[41:]
country_df['day_count'] = list(range(1,len(country_df)+1))

# Storing the data in required entities
ydata = [i for i in country_df.ConfirmedCases]
xdata = country_df.day_count
ydata = np.array(ydata, dtype=float)
xdata = np.array(xdata, dtype=float)


# Initialising the Data
N = population
inf0 = ydata[0]
sus0 = N - inf0
rec0 = 0.0

# Defining the basic ODE's of SIR Model
def sir_model(y, x, beta, gamma):
    sus = -beta * y[0] * y[1] / N
    rec = gamma * y[1]
    inf = -(sus + rec)
    return sus, inf, rec

# Defining the Function to integrate ODE's
def fit_odeint(x, beta, gamma):
    return integrate.odeint(sir_model, (sus0, inf0, rec0), x, args=(beta, gamma))[:,1]

# Storing the values of the OPtimized parameters.
Opt, pcov = optimize.curve_fit(fit_odeint, xdata, ydata)
fitted = fit_odeint(xdata, *Opt)

# Plotting the fitting of curve into data points.
print("Fitting a SECOND order equation into Infectives data yields:-")
pt.plot(xdata, ydata, 'o')
pt.plot(xdata, fitted)
pt.title("Fit of SIR model for Georgia infected cases")
pt.ylabel("Population infected")
pt.xlabel("Days")
pt.show()


# Total population
N = population
# Initialization of infected and recovered individuals, I0 and R0.
I0, R0 = 2, 0
# S0 be the susceptible to infection initially.
S0 = N - I0 - R0
# Contact rate(beta) and mean recovery rate(gamma).
beta, gamma = Opt[0],Opt[1] 
# A grid of time points (in days)
t = np.linspace(0, 200, 200)


# The SIR model definition in differential equations.
def der(y, t, N, beta, gamma):
    S, I, R = y
    dSdt = -beta * S * I / N
    dIdt = beta * S * I / N - gamma * I
    dRdt = gamma * I
    return dSdt, dIdt, dRdt


# Initialization
y0 = S0, I0, R0
# Integrating the SIR equations over the time grid, t.
ret = odeint(der, y0, t, args=(N, beta, gamma))
S, I, R = ret.T

# Plotting the data on three separate curves for S(t), I(t) and R(t)
fig = pt.figure(facecolor='y')
ax = fig.add_subplot(111, facecolor='#dddddd', axisbelow=True)
ax.plot(t, S/(1.25*N), 'b', label='Susceptible')
ax.plot(t, I/5000, 'r', label='Infected')
ax.plot(t, R/400000, 'g', label='Recovered ')
ax.set_xlabel('Time /days')
ax.set_ylabel('Number (1000s)')
ax.set_ylim(0,1.2)
ax.yaxis.set_tick_params(length=0)
ax.xaxis.set_tick_params(length=0)
ax.grid(b=True, which='major', c='w', lw=2, ls='-')
legend = ax.legend()
legend.get_frame().set_alpha(0.5)
for spine in ('top', 'right', 'bottom', 'left'):
    ax.spines[spine].set_visible(False)
pt.show()


print("1.0. The Model Parameters are:-")
r=Opt[0]/N
a=Opt[1]
print("1.1. Transmissibility(r)          =",Opt[0]/N)
print("1.2. Recovery Rate(a)             =",Opt[1])
print("1.3. Relative Removal Rate (Rho)  =",a/r)
print("1.4. Contact rate(Sigma)          =",r/a)
print("2.0. Basic Reproduction Rate(Ro)  =",(r*(10617421))/a)
print("3.0. Maximum Number of Infectives =",max(I))

#Since Max No of infectives occur ar S~=Rho
temp=[]
for i in range(len(S)):
        if (S[i]-(a/r))>0:
            temp.append([(S[i]-(a/r)),i])
#Since min(temp) is at 85th day,It has max no of Infectives
print("4.0. The time location of maximum infectives is at 85th day from the day of initial infection which means 26-05-2020.")

temp2=[]
for i in range(len(I)):
    if I[i]<1:
        x=i
        break
        
#Since at 179th day from the initial day of infection, Infectives become less than 1, It is duration of epidemic.
print("5.0. The total number of Recovered people is around",R[i])
print("6.0. The Duration of the epidemic is 179 days.So it is expected that epidemic ends on 18-8-2020 in Georgia,US.")
      
print("Hence,The SIR Model is fitted into the COVID 19 data of US state,Georgia. All the model parameters and other required quantities are estimated")




