import os
import random
import sys
from random import randint

with open("countries.txt") as f:
    content = f.readlines()
content = [x.strip() for x in content]

alpha = list(map(chr, range(97, 123)))

input("Press enter to see instructions: ")

instruction = """\
Instructions:


    1. You start by typing in a letter

    2. The computer then types another letter and the cycle repeats
    Example:
       You type: z
       Computer types: a

    3. You know that zambia and zaire start with "za".
    4. So the next letter you type must me "m" or "i". But, you must type
       "m" because the last letter of zambia will end on the computer.
       On the other hand, last letter of zaire will end on you.

    5. The person on which the last letter ends, loses.
    Example:
       Computer loses on sweden
       You lose on dubai

    6. If you don't know any place you can type in "Challenge".
       The computer will give you the answer and you will lose.

    7. If the computer doesn't know the answer, he will say "Challenge"
       Then two things can happen:
           1) You know the right answer and the moderator says it is correct
              and you win.

           or

           2) You don't know the right answer and you type in gibberish and the
              moderator marks it as wrong and you lose

    8. Whenever you think the computer has typed in the last letter of a place,
       press enter.

"""
print(instruction)

x = ""
life = 1
my_life = 1
toggle = 0
zup = ""
blah = 1
my_list = [""]
toggle2 = 0
while life > 0 and my_life > 0:
    while True:
        user = str(input("Enter your letter: "))
        while user not in alpha and user != "Challenge" and user != "":
            print("Please input only one character and/or alphabets")
            user = str(input("Enter your letter: "))
        while user == "":
            for item in content:
                if (item.find(x) == 0) and item != x:
                    print(x + " is not a place")
                    user = str(input("Enter your letter: "))
                    break
                elif item == x:
                    x = ""
                    user = ""
                    my_life = my_life - 1
                    n = 1  # I want to iterate over every fifth element
                    print("You win")
                    input(" \n Press enter to exit")
                    sys.exit()
                else:
                    pass

        x = x + user
        toggle2 = 0
        if user == "Challenge":
            x = x.strip("Challenge")
            x = zup
            toggle = 1
        for item in content:
            if (toggle == 1):
                if (item.find(x) == 0):
                    print("The answer is: " + item)
                    print("You lose")
                    x = ""
                    user = ""
                    life = life - 1
                    current = "temp"
                    toggle = 0
                    toggle2 = 1
                    break
                else:
                    pass
            elif item == x:
                if len(item) % 2 == 1:
                    print("You lose")
                    x = ""
                    user = ""
                    life = life - 1
                    break
                else:
                    print("I lose")
                    x = ""
                    user = ""
                    my_life = my_life - 1
                    print("My Life's left: " + str(life))
                    break

            elif (item.find(x) == 0) and (len(item) % 2 == 1):
                my_list.append(item)
            else:
                pass
        # print(my_list)
        if (x != "") and (len(my_list) == 1):
            for item in content:
                if (item.find(x) == 0):
                    my_list.append(item)
                else:
                    pass
        if (x != "") and (len(my_list) == 1):
            print("Challenge!!")
            inner = str(input("Enter your city: "))
            ask = str(input("Moderator, is this challenge valid(y/n): "))
            if ask == "n":
                print("Liar! There is no such place. You lose")
                life = life - 1
                print("Your Life's left: " + str(life))
                x = ""
                n = 1  # I want to iterate over every fifth element
                print("I win as always")
                input("\nPress enter to exit")
                sys.exit()
            else:
                print("You are right I lose!!!")
                my_life = my_life - 1
                print("My Life's left: " + str(my_life))
                with open("countries.txt", "a") as myfile:
                    myfile.write("\n" + (inner.lower()).replace(" ", ""))
                print("I will get you next time !!")
                input("\nPress enter to exit")
                sys.exit()
        elif len(my_list) == 1:
            break
        else:
            x = x + (random.choice(my_list[1:]))[len(x)]
            print(x)
            my_list = [""]
            zup = x
            break

if my_life == 0:
    n = 1  # I want to iterate over every fifth element
    print("I will get you next time!!")
    input("\nPress enter to exit")
    sys.exit(0)
elif life == 0:
    n = 1  # I want to iterate over every fifth element
    print("I win as always")
    input("\nPress enter to exit")
    sys.exit(0)
