import math


def wilsonTheorem(number):
    """
    Check if number is prime 
    """        
    return (math.factorial(number - 1) + 1) % number == 0
    