import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser

engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
#print(voices[0].id)
engine.setProperty('voice',voices[0].id)



def speak(audio):
    engine.say(audio)
    engine.runAndWait()


def wishMe():
    hour = int(datetime.datetime.now().hour)
    if hour==0 and hour<12:
        speak('Good morning ! Have a nice day')
    elif hour >= 12 and hour <18:
        speak('good Afternoon')
    else: speak('GOOD eVENING')

    speak(''' HELLO IM JARVIS HOW MAY I HELP YOU SIR? ''' )


def takeCommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        print('Listening . . .  ')
        r.pause_threshold = 1
        audio = r.listen(source)

    try: 
        print('Recognizing...')
        query =r.recognize_google(audio, language = 'en-in')
        print(f'user said :: ,{query} \n')
    except Exception as e:
        print(e)
        print('say that again pls . . ')
        return 'None'
    return query



if __name__ == '__main__':
  
    wishMe()
    jarvis = takeCommand().lower
    if jarvis == 'who are you ? ':
        speak('Im Jarvis You assistant')
    while True:
        if jarvis == 'jarvis!':
            query = takeCommand().lower()

            if 'wikipedia' or 'who is ' in query:
                speak('Searching . . .')
                query = query.replace('wikipedia', "")
                results = wikipedia.summary(query,sentences=3)
                speak('According to wikipedia ')
                print(results)
                speak(results)
            elif 'search' in query:
                query = query.replace('search','')
                webbrowser.open('google.com/query')
           