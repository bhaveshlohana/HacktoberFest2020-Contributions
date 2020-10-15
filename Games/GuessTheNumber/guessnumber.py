# Author : Daniele Carvalho
# GitHub : daniele-mc
import random

# Guess from 100 numbers 
guess = random.randrange(100)
num = int(input("Enter a number (0 to 100): "))
while (guess < 101):
    if (num < guess):
        print("Input a higher number\n")      
    elif (num > guess):
        print("Input a lower number\n")
    else:
        print("You guess the number\n")
        break
    num = int(input("Enter a number (0 to 100): "))   
