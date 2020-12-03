import random #importing random module
import time #import time module
import sys #import sys module
from threading import Timer #importing Timer from threading

def speedCalculation(sen,initial,final): #This function is used to calculate the speed of the words typed the 
    words=sen.count(" ")+1 #words calculates the total number of words by counting the number of spaces
    timediff=final-initial #timediff calculates the time taken for typing the sentance
    return (words/timediff) #prints the speed of typing


def accuracyCalculation(sen,written):#This function calculates the accuracy of words
    if(len(sen)==len(written)):#This "if" checks if both typed and generated lengths are matching
        count=0 #initialization of count to 0
        for i in range(0,len(sen)):#this loop iterates over all the letters of both typed and generated
            if(sen[i]==written[i]):#checks if both charcaters or same or not
                count=count+1 #increment the count by 1 if they are matched
        return (count/len(sen)) #this return statement returns accuracy(returns 1 if all the characters are matched)

    elif(len(sen)>len(written)):    #condition to check the written sentence is equal to actual sentence 
        #print("You haven't entered the complete text")
        return 0

    elif(len(sen)<len(written)):
        #print("You have written extra text")
        return 0


def collectSentence():#file handling
    sentenceslist=[]#initialization of empty list to store the sentances
    with open ('D:\Documents/sentences.txt', 'rt') as myfile:
        for myline in myfile:
            sentenceslist.append(myline.rstrip())#appending all the sentences to the sentenceslist
            #print(myline) 
            #print(sentenceslist)
    return sentenceslist            #return the list


def playGame():    #This functions interacts with the user
    sentenceslist=collectSentence() 
    sentenceindex=random.randrange(0,len(sentenceslist),2)#generation of a random number which contains the index
    sen=sentenceslist[sentenceindex] #the random sentence genrated is stored in sen
    print(sen) #print the sen for the user 
    starttime=time.time() #This calculates the initial time when the user has started typing
    st=input() #reads the input from the user
    endtime=time.time() #This calculates the end time when the user has submitted the sentance for evaluation
    #print(starttime,endtime)
    if(round(accuracyCalculation(sen,st)>=0.9)):#if the accuracy is high(>=0.9)
       print("You have good typing skills")
       print("Your accuracy is "+str(round(accuracyCalculation(sen,st)*100,2)))#prints the accuracy
       print(str(round(speedCalculation(sen,starttime,endtime)*60,2))+" words/minute")#prints the typing speed
    elif(round(accuracyCalculation(sen,st)<0.9) and round(accuracyCalculation(sen,st)>0)):
       print("Your accuracy is "+str(round(accuracyCalculation(sen,st)*100,2)))
       print(str(round(speedCalculation(sen,starttime,endtime)*60,2))+" words/minute")
    else:
       print("Accuracy will be calculated if both the lengths are matching only")#The accuracy and speed are calculated only if both the lengths are matching
    




while(1):
    print("Test your typing skills here")
    print("Choose your option")
    print("1.Start the test")
    print("2.Exit")
    #print("The system closes automatically if you choose nothing")
    n=(input())
    if(n.isdigit()):
        if(int(n)<0 and int(n)>2):#if the user input is not within the options given
            print("Invalid Option")
            sys.exit()
        elif(n=='1'):
            playGame()#calls the playGame function
        elif(n=='2'):
            sys.exit() #exits from the program
        else:
            print("You selected an invalid option")
            sys.exit() #exits from the program
    else:#if you entered an invalid option other than digit
      print("You entered invalid option")
      print("Try again")
