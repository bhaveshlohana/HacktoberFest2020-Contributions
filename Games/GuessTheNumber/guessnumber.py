# Author : Daniele Carvalho
# GitHub : daniele-mc
import random
n = random.randint(1,100)
guess = 0
count = 0
while guess != n and guess != "exit":
    guess = input(" Your guess?")    
    if guess == "exit":
        break
    guess = int(guess)
    count += 1
    if guess < n:
        print("Too low!")
    elif guess > n:
        print("Too high!")
    else:
        print("You got it!")
        print("And it only took you",count,"attempts!")
  
