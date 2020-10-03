#!/usr/bin/env python3
import string, random

words = 'cuffs cuing culls cults cumin cupel cupid curbs curds cures panel pangs panic pansy pants papas papal papaw paper parch pards pared pares paris parks parka parry parse parts parte party pasha salaam salads salami salary saline saliva sallow salmon salons saloon salted saluki salute salved salver salves salvia salvos samara sambas samoan sampan sample sancta sanded sander sandal sanest sanity sansei santas  scabby scaled scales scalar scalds scalps scamps scampi scants scanty scared scares bigamy bigger bights bigots bigwig bijoux bikers biking bikini bilged bilges bilked billed billet billow binary binder binges bingos biomes biopsy biotic biotas biotin bipeds birdie births bisect bishop bisque melodies melodeon meltable meltdown membrane mementos memories memorial memoriam memorize menacing menhaden meninges meniscal meniscus mentally menthols mentions mephitic mephitis merchant merciful mercuric meridian tenanting tendering tenderize tenements tenebrous tennessee tenseness tensility tentacles tentative tentmaker tenuously teriyakis termagant terminals terminate terracing terrapins terrarium terrazzos redeposits redescribe redesigned redevelops redigested redirected rediscover redissolve redistrict'

wordlist = words.split()


def choose_word(wordlist):
    """
    wordlist (list): list of words (strings)

    Returns a word from wordlist at random
    """
    return random.choice(wordlist)

def isWordGuessed(secretWord, lettersGuessed):
    for char in range (len(secretWord)):
        if (secretWord[char] in lettersGuessed) :
            guessed = False
            break
        else:
            guessed = True

    return guessed


def getGuessedWord(secretWord, lettersGuessed):
    a = list(secretWord)
    b = " "
    for i in range(len(a)):
        if (a[i] not in lettersGuessed):
            a[i] = '_'
    b = b.join(a)
    return (b)


def getAvailableLetters(lettersGuessed):
    '''
    lettersGuessed: list, what letters have been guessed so far
    returns: string, comprised of letters that represents what letters have not
      yet been guessed.
    '''
    # FILL IN YOUR CODE HERE...
    a = 'abcdefghijklmnopqrstuvwxyz'
    for i in range(len(lettersGuessed)):
        a = a.replace(lettersGuessed[i], "")
    return (a)


def hangman(secretWord):

    # FILL IN YOUR CODE HERE...
    z = 8
    a = 'abcdefghijklmnopqrstuvwxyz'
    lettersGuessed = []
    print("welcome to hangman")
    print("I am thinking of a word that is " + str(len(secretWord)) + " letters long.")
    print("!_________!")
    print("You have " + str(z) + " guess left.")
    print("Available letters: " + a + "")
    left = len(secretWord)
    print(left)
    while (z != 0):


        y = input("please enter a letter :")
        lettersGuessed.append(y)


        #g = isWordGuessed(secretWord, lettersGuessed)
        if isWordGuessed(secretWord, y) == False:

            print("good guess!!!")




        else:
            print("opps!!wrong guess")
            z=z-1

        print (getGuessedWord(secretWord, lettersGuessed))

        print("You have " + str(z) + " guess left.")

        ge =getGuessedWord(secretWord, lettersGuessed)
        lef=0
        for i in range(len(ge)):
            if ge[i]=='_':
                lef+=1
        left=lef
        print("you have to guess " + str(left) + " words")
        a=getAvailableLetters(lettersGuessed)
        print("Available letters: " + a + "")
        if left==0:
            print(secretWord)
            print("congratulation!!!! you win")
            break

        if (z == 0):
            print("you are ran out of guesses the ans is " + secretWord)
            break

quit='r'
secretWord = choose_word(wordlist)
hangman(secretWord)
while(quit !='q'):
    quit=input("enter q  to exit:")

    #import sys
    #sys.exit(0)
