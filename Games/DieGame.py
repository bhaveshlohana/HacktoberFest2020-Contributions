import random
import pandas as pd

def menu():
    print('-'*20)
    print("Welcome To DIE Game Menu")
    print("TO play - 1")
    print("TO see Leaderboard -2")
    print("To exit press anything else !")
    print('-'*20)
    choice = input()
    if choice == '1':
        input('Press anything to start the game')
        stage=1
        StartGame(stage)
        if user1.tot_score > user2.tot_score :
            winner = user1.name
        elif user1.tot_score < user2.tot_score :
            winner = user2.name
        else :
            print("Scores are tied so each of you roll a single die until either of you wins ")
            winner = tiegame()
        print(winner," Won!")
        menu()
    elif choice == '2':
        leaderboard()
    else :
        quit()

class Die:
    def roll_die(self):
        self.roll = random.randint(1,7)

class User:
    def __init__(self,name):
        self.name = name
        self.score = [0,0,0,0,0]
        self.tot_score = 0
name1 = "Aditya"
name2 = "Akshay"
user1=User(name1)
user2=User(name2)

def leaderboard():
    data = pd.read_csv('Players.csv')
    data.head()


def StartGame(stage):
    if(stage<=5):
        print(stage," Dice roll of ",user1.name)
        input("Press any key to roll dice")
        die1=Die()
        die2=Die()
        die1.roll_die()
        die2.roll_die()
        sum1 = die1.roll + die2.roll
        print("DIE-1 : ",die1.roll,"\nDIE-2 : ",die2.roll)
        if (sum1 % 2 == 0):
            sum1 = sum1 + 10
            if(die1.roll == die2.roll):
                print("YAAY you rolled doubles.So you get to roll one die again")
                input("Press any key to roll die")
                die1.roll_die()
                sum1 = sum1 + die1.roll
        else:
            sum1 = sum1 - 5
        user1.score[stage-1]=sum1
        user1.tot_score=user1.tot_score+sum1
        if (user1.tot_score < 0 ):
            user1.tot_score = 0
        print(stage,"round score of ",user1.name," is ",sum1)
        print("Total Score of ",user1.name," :",user1.tot_score)
###########################################################################################
        print(stage," Dice roll of ",user2.name)
        input("Press any key to roll die")
        die1 = Die()
        die2 = Die()
        die1.roll_die()
        die2.roll_die()
        sum2 = die1.roll + die2.roll
        print("DIE-1 : ",die1.roll,"\nDIE-2 : ",die2.roll)
        if (sum2 % 2 == 0):
            sum2 = sum2 + 10
            if(die1.roll == die2.roll):
                print("YAAY you rolled doubles.So you get to roll one die again")
                input("Press any key to roll die")
                die1.roll_die()
                sum2 = sum2 + die1.roll
        else:
            sum2 = sum2 - 5
        user2.score[stage - 1] = sum2
        user2.tot_score = user2.tot_score + sum2
        if (user2.tot_score < 0 ):
            user2.tot_score = 0
        print(stage,"round score of ",user2.name," is ",sum2)
        print("Total Score of ",user2.name," :",user2.tot_score)
        print(' '*10,"SCORE BOARD")
        print('-'*20)
        print("PLAYER NAME ",' '*5,"ROUND-1 "," Round-2 "," Round-3 "," Round-4 "," Round-5 "," Total Score")
        print(user1.name,' '*5,user1.score[0],user1.score[1],user1.score[3],user1.score[4],user1.tot_score)
        print(user2.name,' '*5,user2.score[0],user2.score[1],user2.score[3],user2.score[4],user2.tot_score)
        stage = stage + 1
        StartGame(stage)
    else:
        return 0

def tiegame() :
    specialdie = Die()
    specialdie.roll_die()
    sum1 = specialdie.roll
    specialdie.roll_die()
    sum2 = specialdie.roll
    if(sum1 > sum2):
        return user1.name
    elif(sum2 > sum1):
        return user2.name
    else :
        tiegame()

if __name__=="__main__":
    menu()
