#hangman game
#the secret
import random
words=["pineapple", "apple", "guava","strawberry","banana"]  #list of words
secret= random.choice(words)    #randomlu gives the word to be guessed from the list of words:
print("Welcome to Hangman")
      #to find the length of the word
length = len(secret)
alphabet="abcdefghijklmnopqrstuvwxyz"
print("The length of your word is",length )
print("Begin guessing the word")
turn=1
    
print("your word has ", length," characters")
guess_word=[] #to print the word the player is guessing
letter_storage=[] #variable to prevent repetition of letters
for character in secret:
    guess_word.append("-")  #prints dashes in places of letters in secret word
print(guess_word) 
print("(Hint: it is a fruit)")
while turn<length+1:    #10 turns only
      guess= input("enter letter to guess: ").lower()
      if not guess in alphabet:
          print("enter a alphabet")
      elif guess in letter_storage:
           print("Sorry! You have already entered that letter. Try again")
      else:
           letter_storage.append(guess)
           if guess in secret:
              print("yay! The letter you entered is in the word")
              for x in range(0, length):
                  if secret[x]==guess:
                     guess_word[x]=guess
              print(guess_word)
              if '-'not in guess_word:
                         print("YOU WON!")
                         break;
           else:
                print("sorry letter not found. Try again!")
      turn+=1
if turn>10:
    print("SOrry turns over. the word is ", secret)
#end    
print("Thank You!")
                
    

