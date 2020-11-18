print ("~~~~~~~~~~~~***********WELCOME TO NUMBER GUESSING GAME***********~~~~~~~~~~~~\n")
name=str(input("\n\tEnter your name:\t"))                                               #user enter his/her name 
print ("\n\t HEYYY  ",name,",  Pleasure to see you here!\n")                            #game welcomes the user
print ("\t Now move as the instructions guide you.\n")
print ("\t\t      *** ENJOY ***\n")
print ("\t !!!AND DON'T FORGET TO RATE THE GAME!!! \n")
import random
def game():
    print ("\t\t PRESS 1 TO PLAY.")                                                     
    print ("\t\t PRESS 2 FOR HELP.\n")
    user=int(input("\tEnter your choice:\t"))                                           #user enter the choice whether to play or take instructions from help
    if (user==1):
        play()                                                                          #play function is called as user gets ready to start the game
    elif (user==2):
        print ("\n         INSTRUCTIONS OF THIS GAME IS AS FOLLOWS:\n")                 #instructions of game is displayed
        print ("\t 1. Number to be choosen between 0 to 100.")
        print ("\t 2. The computer will randomly choose a number.")
        print ("\t 3. You have to guess a number that matches to the Computer's by following the instructions.")
        print ("\t 4. You will get only 5 chances to guess the number.\n")
        game()                                                                          #again game function calls itself so that now user can choose to play the game
    else:
        print ("\n\t\tOops!!!   WRONG INPUT !!!!\n")
        game()                                                                          #as the user enters input other than as mentioned game function again calls itself
def play():
    number=random.randint(0,100)                                                          #computer randomly chooses any number between 0 to 9
    chance=0
    for i in range(5):                                                                  #for loop runs for 5 times as chances mentioned upto 5
        print ("\n\t\t\t CHANCE :\t",i+1)
        guess=int(input("\n\tEnter number of your choice:\t"))       
        if (guess==number):                                                             
            print ("\n\t Hurray (^o^)!!! \n\n\t\t\tYOU WON THE GAME!!!\n")              #as the user guesses the correct number message is displayed
            break
        elif (guess<number):
            print ("\t Too Low :( \n\tCHOOSE HIGH NUMBER!!!\n") 
            chance=chance+1
        elif (guess>number):
            print ("\t Too High :( \n\tCHOOSE LOW NUMBER!!!\n")
            chance=chance+1
    if (chance==5):                                                                     
        print ("\n\t Sorry ( -_- )!!! , Your chances are over!!\n\n\t\t\tYOU LOOSE!!!\n")#as the chances gets over and user fails to guess a number a message is displayed
    repeat()                                                                             
def repeat():
    print ("\t\t PRESS 1 TO CONTINUE AGAIN WITH GAME.")
    print ("\t\t PRESS 2 TO EXIT THE GAME.\n")
    choice=int(input("\tEnter you choice:\t"))                                          #user enters his/her choice whether to continue the game or not
    if (choice==1):
        play()                                                                          #if user wants to continue the game play function is again called
    elif (choice==2):
        print ("\n\t PLEASE RATE US FROM 0 TO 5 (^o^) IT WILL HELP US TO IMPROVE.\n")   #otherwise before exiting rating is done by user
        print ("\t 0 => For No Rating")
        print ("\t 1 => For Very Unsatisfied!! (-_-)")
        print ("\t 2 => For Unsatisfied!! (-.-)")
        print ("\t 3 => For Moderate!! (^-^)")
        print ("\t 4 => For Interesting!! (^o^)")
        print ("\t 5 => For Fully Enjoyed!! (*O*)")
        rate=int(input("\n\tEnter your rating:\t"))
        print ("\n\t You Rated us",rate,"\n\n\t\t\t THANKS FOR RATING US!!\n")
        print ("~~~~~~~~~~~~~~~~~~******THANK YOU FOR PLAYING THE GAME******~~~~~~~~~~~~~~~~~\n")
    else:
        print ("\n\t Oops!!!   WRONG INPUT !!!!\n")
        repeat()                                                                        #as the user enters input other than as mentioned repeat function again calls itself
game()                                                   
