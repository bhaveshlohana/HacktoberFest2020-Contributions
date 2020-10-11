import math
from aps import apc
from gps import gpc
def ui():
    ls = inp_ls()
    if fibonacci(ls):
        print_series(ls, 0)
    elif ap(ls):
        print_series(ls, 1)
    elif gp(ls):
        print_series(ls, 2)
    elif n2_sum(ls):
        print_series(ls, 3)
    elif n3_sum(ls):
        print_series(ls, 4)
    elif n4_sum(ls):
        print_series(ls, 5)
    elif n5_sum(ls):
        print_series(ls, 6)
    else:
        print('The entered sequence might not be a series,\n\
OR maybe you should consider going to wolfram :wink:')

def inp_ls():
    ls=[]
    print("You'll be prompted to enter the terms in the series.")
    print('Press Q or some alphabets to quit.')
    while True:
        inp= input('Enter term of series: ')
        if inp.isdigit():
            ls.append(int(inp))
        else:
            break
    return ls

def fibonacci(ls):
    #ls=[1,1,2,3,5,8,13,21]
    for i in range(len(ls)-2):
        j = i+1
        k=i+2
        if (ls[k]!=ls[i]+ls[j]):
            return False
        else:
            continue
    return True

def ap(ls):
    #ls=[1,2,3,4,5]
    for i in range(len(ls)-2):
        if ls[i+1]-ls[i]== ls[i+2]-ls[i+1]:
            continue
        else:
            return False
    return True

def gp(ls):
    #ls=[3,9,27,81,243,729]
    for i in range(len(ls)-2):
        if (ls[i+1]/ls[i]==ls[i+2]/ls[i+1]):
            continue
        else:
            return False
    return True

def n2_sum(ls):
    #ls=[1,4,9,16]
    for i in range(len(ls)-1):
        if math.sqrt(ls[i])+1==math.sqrt(ls[i+1]):
            continue
        else:
            return False
    return True

def n3_sum(ls):
    #ls=[1,8,27]
    for i in range(len(ls)-1):
        if (ls[i])**(1/3)+1==(ls[i+1])**(1/3):
            continue
        else:
            return False
    return True

def n4_sum(ls):
    #ls=[1,16,81]
    for i in range(len(ls)-1):
        if (ls[i])**(1/4)+1==(ls[i+1])**(1/4):
            continue
        else:
            return False
    return True

def n5_sum(ls):
    #ls=[1,32,243]
    for i in range(len(ls)-1):
        if (ls[i])**(1/5)+1==(ls[i+1])**(1/5):
            continue
        else:
            return False
    return True

def n6_sum(ls):
    #ls=[1,64,729]
    for i in range(len(ls)-1):
        if (ls[i])**(1/6)+1==(ls[i+1])**(1/6):
            continue
        else:
            return False
    return True

def print_series(ls, t):
    type= ["Fibbonaci","AP","GP","Sum of square","Sum of Cubes","Sum of N to 4th power","Sum of N to 5th power"]
    type=type[t]
    print(f'The type of this series is: "{type}"')
    n = int(input('Enter no.of terms in series that you want to print: '))
    if t==0:
        m,n= None,None
    elif t==1:
        m,n= apc(ls[0],ls[1]-ls[0],n)
    elif t==2:
        m,n= gpc(ls[0],ls[1]//ls[0],n)
    else:
        m,n= None,None
    print(f'The series is given by:\n{m}...\nThe sum of the "{type}" is:\n{n}')

ui()


