import os
from random import randint

## Number of days you want to make commits
mi = int(input('min contributions per day : '))
ma = int(input('max contributions per day : '))
days = int(input('enter number of days : '))
for i in range(1,days+ 1):
    d = str(i) + ' day ago'
    ## Open a text file and modify it
    r = randint(mi,ma)
    for i in range(0,r):
        with open('bot.txt', 'a') as file:
            print(f'{d}+{i}')
            file.write(f'{d}+{i}\n')
    ## Add bot.txt to staging area
            os.system('git add bot.txt')
    ## Commit it
            print(f'git commit --date=" + {d} + " -m "{d} +{i}"')
            os.system(f'git commit --date=" + {d} + " -m "{d} +{i}"')

## push the commit to github
os.system('git push -u origin main')
