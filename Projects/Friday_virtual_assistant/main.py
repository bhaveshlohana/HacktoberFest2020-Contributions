import fridayfunctions as FF
from fridayfunctions import playmusic
import speakandrecognizefunctions as SRF
import datetime


WAKE_WORD = "friday"
USER = "shikhar"


def success():
    print("Command executed succesfully :)")


# GREETINGS ON THE START
SRF.speak("Hello !! I am FRIDAY !!")
FF.wishme()
SRF.speak("if u need me to do anything just ask !")

while True:

    # Constantly hearing in the background
    text = SRF.takecommandbackground()

    # Wakes up when it hears the word FRIDAY in the text
    if text.count(WAKE_WORD) > 0:

        SRF.speak("How may i help you ?")
        print("\nListening....")

        # takes the command to do stuff
        text = SRF.takecommand()

        # This is if u greet friday
        WISH_STR = ["hello", "hey", "hai", "hi", "hola"]
        for phrase in WISH_STR:
            if phrase in text:
                SRF.speak("Hello" + USER)
                success()

        # This is for taking notes
        NOTE_STRS = ["take note", "take a note", "make a note",
                     "write this down", "remember this"]
        for phrase in NOTE_STRS:
            if phrase in text:
                SRF.speak("what would you like me write down")
                note_text = SRF.takecommand()
                FF.note(note_text)
                SRF.speak("Ok i Have taken the note")
                success()

        # this is for wikipedia search, command - " search wikipedia for [name] ", "wikipedia search [name]","search on wikipedia for []"
        if 'wikipedia' in text:
            FF.wikipediasearch(text)
            success()

        #    to open files on this computer
        if 'open' in text:
            FF.open_programs_websites(text)
            success()

        # this is for telling the current time
        TIME_STRS = ["whats the time", "tell the time", "the time"]
        for phrase in TIME_STRS:
            if phrase in text:
                hour = datetime.datetime.now().strftime("%I")
                minute = datetime.datetime.now().strftime("%M%p")
                SRF.speak(f"It's  {hour} {minute} ")
                success()

        GOOGLE_STRS = ["search on google",
                       "google search", "search google for"]
        for phrase in GOOGLE_STRS:
            if phrase in text:
                query = text.replace(phrase, "")
                FF.googlesearch(query)
                success()

        MUSIC_STRS = ["play music", "start music"]
        for phrase in MUSIC_STRS:
            if phrase in text:
                playmusic()
                success()

# This is if u want to exit the program
        EXIT_STRS = ["exit", "go away", "bye bye"]
        for phrase in EXIT_STRS:
            if phrase in text:
                SRF.speak("Bye Bye " + USER + "see you later")
                exit()
