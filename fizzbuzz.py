# Welcome to my program. This is a program in which you have to enter a number.
# If the number is divisible by 3, it will print Fizz.
# Else, if the number is  divisible by 5, it will print Buzz.
# Otherwise, if the number is divisible by both 3 and 5, it will print FizzBuzz.
# Rest all the numbers will print in their normal form...


import pyfiglet
print(pyfiglet.figlet_format(" F I Z Z - B U Z Z "))
print("\n\n")
print("WELCOME TO FIZZ-BUZZ")
print("In this program, you have to enter a number.")
print("\n")
print("""If the number is divisible by 3, it will print Fizz.
Else, if the number is  divisible by 5, it will print Buzz.
Otherwise, if the number is divisible by both 3 and 5, it will print FizzBuzz.
Rest all the numbers will print in their normal form...""")
print("\n\n")

user_input = input("Enter your number here: ")
user_input = int(user_input)
for num in range(1,user_input + 1):
    if num % 3 == 0 and num % 5 == 0:
        print("FizzBuzz")
    elif num % 3 == 0:
        print("Fizz")
    elif num % 5 == 0:
        print("Buzz")
    else:
        print(num)