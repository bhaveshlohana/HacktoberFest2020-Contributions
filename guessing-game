import random
x = random.randint(2,12)
z = random.randint(1,3)
a = random.randint(2,4)
no_of_guesses = 3
while no_of_guesses>0:
    try:
        y = int(input('enter a number:'))
    except:
        print('error! Please type a valid number.')
        continue
    if y!=x:
        no_of_guesses = no_of_guesses - 1
        print('try again')
        print('hint:number lies between', (x-z,x+a))
        continue
    elif y == x:
        if no_of_guesses == 3:
            print('correct')
            print('Your score is 200')
            quit()

        if no_of_guesses == 2:
            print('correct')
            print('Your score is 100')
            quit()
        elif no_of_guesses == 1:
            print('correct')
            print('Your score is 50')
            quit()

print('game over! The number is',x)
