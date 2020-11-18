
"""@author: Prajwal
"""
import random
from time import sleep
compscore1=0
playerscore1=0
compscore2=0
playerscore2=0
global numbers
numbers=[1,2,3,4,5,6]
c=0
b1=0
b2=0
def game(): 
    global c
    global compscore1
    global playerscore1
    global compscore2
    global playerscore2
    global b1
    global b2
    compscore1=0
    playerscore1=0  
    compscore2=0
    playerscore2=0
    c=0
    b1=0
    b2=0
    try:
        c1=int(input("Start game ? Click 1 \nExit ? Click 2\n"))
    except ValueError:
        print("Enter a valid number")
        sleep(2)
        print("\033[H\033[J")
        game()
        return
    choice1={1: t , 2: lambda: exit()}    
    func1=choice1.get(c1, lambda: invalid())
    func1()
def invalid():
    print("Invalid Input")
    game()
    
def t():
    choice=["odd", "even"]
    global win
    win=True
    toss=input("Odd or Even ?\n").lower()
    if toss in choice:
        try:
            playertoss=int(input("Enter number : "))
        except ValueError:
            print("Please enter a valid number")
            t()
        comptoss=random.choice(range(1,7))
        print("Your choice : ", playertoss)
        print("Computer's choice : ", comptoss)
        if toss=="even":
            if (playertoss+comptoss)%2==0:
                print("You won the toss. Congrats !")
            else:
                print("You lost the toss. Boo !")
                win=False
        elif toss=="odd":
            if (playertoss+comptoss)%2==1:
                print("You won the toss. Congrats !")
            else:
                print("You lost the toss. Boo !")
                win=False
    else:
        print("Choose your options correctly")
        t()
    chooseside()

def chooseside():
    if win==True:
        action=input("Bowling or batting ?\n").lower()
        if action=="bowling":
            print("You chose to bowl") 
            playerbowl1()
        elif action=="batting":
            print("You chose to bat") 
            playerbat2()
        else:
            print("Invalid Action. Try again.")
            chooseside()
    else: 
        print("The computer chooses to bat") 
        playerbowl1()
        
#WHEN PLAYER CHOOSES TO BOWL
def playerbowl1():
    try:
        global compscore1;a=0
        playerrun1=int(input("Enter your number from 1 to 6\n"))
        comprun1=random.choice(numbers)
        if playerrun1 in numbers:
            if playerrun1==comprun1:
                print("Computer chooses : ", comprun1)
                print("Computer is out !")
                print("COMPUTER's SCORE = ", compscore1)
                a=1
            else:
                print("Computer chooses : ", comprun1)
                compscore1=compscore1+comprun1
                print("COMPUTER'S SCORE = ", compscore1)
                playerbowl1()
        else:
            print("Invalid hit ")
            playerbowl1()
        if a==1:
            print("At the end of the first innings, the score to beat is : ", compscore1+1," Now it's player's turn to bat ")
            playerbat1() 
    except ValueError:
        print("Sorry, we encountered an error, did you try to cheat? Anyway please bowl again")
        playerbowl1()
def playerbat1():    
    try:
        global playerscore1;a=0
        while playerscore1<=compscore1+1:
            playerrun1=int(input("Enter your number from 1 to 6\n"))
            comprun1=random.choice(numbers)
            if playerrun1 in numbers:
                if playerrun1==comprun1:
                    print("Computer chooses :", comprun1)
                    print("You are out !")
                    print("YOUR SCORE = ", playerscore1)
                    a=1
                    endmatch1()
                    
                else:
                    print("Computer chooses :", comprun1)
                    playerscore1=playerscore1+playerrun1
                    print("YOUR SCORE = ", playerscore1)
                    playerbat1()
            else:
                print("Invalid hit")
                playerbat1()
            break
        if a!=1:
            endmatch1()
    except ValueError:
        print("Sorry, we encountered an error, did you try to cheat? Anyway please bat again")
        playerbat1()            
b1=0    
def endmatch1():
    global c
    global b1
    if(b1==0):
        print("\nMATCH ENDS ! \nYOUR SCORE = ", playerscore1, "\nCOMP SCORE = ", compscore1)
        if compscore1>playerscore1:
            print("\nCOMPUTER WINS")
        elif compscore1<playerscore1:
            print("\nYOU WIN")
        else :
            print("\nDRAW")
        b1+=1
    if(c==0):
        input("Press Enter to return to main menu")
        c=1
#WHEN PLAYER CHOOSES TO BAT       
def playerbat2():
    try:
        global playerscore2; a=0
        playerrun2=int(input("Enter number from 1 to 6\n"))
        comprun2=random.choice(numbers)
        if playerrun2 in numbers:
            if playerrun2==comprun2:
                print("Computer chooses : ", comprun2)
                print("You are out")
                print("YOUR SCORE = ", playerscore2)
                a=1
            else:
                print("Computer chooses : ", comprun2)
                playerscore2=playerscore2+playerrun2
                print("Your SCORE = ", playerscore2)
                playerbat2()
        else:
            print("Invalid hit")
            playerbat2()
        if a==1:
            print("At the end of the first innings, the score to beat is : ", playerscore2+1," Now it's comp's turn to bat ")
            compbat2()
    except ValueError:
        print("Sorry, we encountered an error, did you try to cheat? Anyway please bat again")
        playerbat2()
def compbat2():
    try:
        global compscore2;a=0
        while compscore2<playerscore2+1:
            playerrun2=int(input("Enter your number from 1 to 6\n"))
            comprun2=random.choice(numbers)
            if playerrun2 in numbers:
                if playerrun2==comprun2:
                    print("Computer chooses :", comprun2)
                    print("COMPUTER IS OUT !")
                    print("COMPUTER'S SCORE = ", compscore2)
                    a=1
                    endmatch2()
                else:
                    print("Computer chooses :", comprun2)
                    compscore2=compscore2+comprun2
                    print("COMPUTER'S SCORE = ", compscore2)
                    compbat2()
            else:
                print("Invalid hit")
                compbat2()
            break
        if a!=1:
            endmatch2()
    except ValueError:
        print("Sorry, we encountered an error, did you try to cheat? Anyway please bowl again")
        compbat2()
b2=0    
def endmatch2():
    global c
    global b2
    if(b2==0):
        print("\nMATCH ENDS ! \nYOUR SCORE = ", playerscore2, "\nCOMPUTER'S SCORE = ", compscore2)
        if compscore2>playerscore2:
            print("\nCOMPUTER WINS")
        elif compscore2<playerscore2:
            print("\nYOU WIN")
        else :
            print("\nDRAW")
        b2+=1
    if(c==0):
        input("Press Enter to return to main menu")
        c=1

if __name__ == "__main__":
    game()