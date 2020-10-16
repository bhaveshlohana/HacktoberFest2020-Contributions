import random

x = random.randint(1,10)

while True:
    user_input = int(input("Guess A Number:"))
    if user_input == x:
        print("Hurray! You Got It Right")
        break
    elif user_input > x:
        print("Too High, Guess A little Lower Number")
    elif user_input < x:
        print("Too Low, Guess A little Higher Number")
