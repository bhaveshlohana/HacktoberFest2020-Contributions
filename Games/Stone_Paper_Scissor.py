import random

user = None
k = True
while k == True: 
    computer = random.choice(['stone','paper','scissor'])
    
    print("Choose: stone | paper | scissor")
    user = input().lower()
    if user not in ('stone','paper','scissor'):
        print('Invalid Input')
        user = None
    
    if user == computer:
        print('----Game Drawn!---')
        print('Want to play Again? Y/N')
        a = input()
        if a == 'N':
            k = False
    else:
        if computer == 'stone':
            if user == 'paper':
                print('--- Great! You Won ---')
            elif user == 'scissor':
                print('--- Ahmm! Computer Won --')
        elif computer == 'paper':
            if user == 'scissor':
                print('--- Great! You Won ---')
            elif user == 'stone':
                print('--- Ahmm! Computer Won --')
        elif computer == 'scissor':
            if user == 'stone':
                print('--- Great! You Won ---')
            elif user == 'paper':
                print('--- Ahmm! Computer Won --')
        print('Want to play Again? Y/N')
        a = input()
        if a == 'N':
            k = False
