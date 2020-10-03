import pyttsx3
import datetime
import speech_recognition as sr
import wikipedia
import webbrowser
import random 
import os
print("FRIDAY")
engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice',voices[1].id)

chrome_path = 'C:/Program Files (x86)/Google/Chrome/Application/chrome.exe %s'

def speak(audio):
    engine.say(audio)
    engine.runAndWait()

def wishme():
    hour = int(datetime.datetime.now().hour)
    if hour >=0 and hour<=12:
        speak("good morning! ")
    elif hour>=12 and hour <18:
        speak("good aftenoon!")
    else:
        speak("good evening! ")
    speak("How may i help you ?")

def takecommand():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source,duration=1)
        #r.pause_threshold = 1
        print("Listening....")
        audio = r.listen(source,phrase_time_limit=4)
        #print("m done ")
    
    try :
        print("Recognizing....")
        query =r.recognize_google(audio,language='en-in')
        #print("user said : ",query)
        #speak(query)
    
    except Exception :
        print("Say that again please !! ")
        return "none"
    return query


if __name__ == "__main__":
    wishme()
    while True:
        query = takecommand().lower()

        #TASKS

        if 'wikipedia' in query :
            try:
                speak ('searching wikipedia.....')
                query = query.replace("wikipedia","")
                results = wikipedia.summary (query,sentences=2)
                speak("according to wikipedia")
                speak(results)
            except :
                speak("i did not get it.Try saying that again")

        elif "open youtube"  in query:
            speak("opening youtube")
            webbrowser. get(chrome_path). open_new_tab("youtube.com")     
        
        elif "study time"  in query:
            speak("starting lofi hiphop")
            webbrowser. get(chrome_path). open_new_tab("https://www.youtube.com/watch?v=hHW1oY26kxQ") 

        elif "github"  in query:
            speak("opening github")
            webbrowser. get(chrome_path). open_new_tab("https://github.com/") 
        
        elif "play music" in query: 
            speak("playing music ")
            music_dir = "C:\\Users\\shikh\\Desktop\\music"
            songs = os.listdir(music_dir)
            
            num = random.randint(0,len(songs))
            os.startfile(os.path.join(music_dir,songs[num-1]))
        
        elif "the time" in query:
            strtime = datetime.datetime.now().strftime("%I%p")
            speak(f"It's  {strtime} ")
        
        elif "open code" in query :
            speak("opening visual studio code")
            codepath = "C:\\Users\\shikh\\AppData\\Local\\Programs\\Microsoft VS Code\\Code.exe"
            os.startfile(codepath)    

        elif "open c plus plus" in query :
            speak("opening codeblocks")
            codepath = "C:\\Program Files (x86)\\CodeBlocks\\codeblocks.exe"
            os.startfile(codepath)    
        
        elif "open word" in query :
            speak("opening microsoft word")
            codepath = "C:\\Program Files (x86)\\Microsoft Office\\root\\Office16\\WINWORD.EXE"
            os.startfile(codepath)  
        
        elif "google" in query:
            query = query.replace("google search","")
            speak ('searching on google.....')
            url = "https://www.google.co.in/search?q=" +(str(query))+ "&oq="+(str(query))+"&gs_l=serp.12..0i71l8.0.0.0.6391.0.0.0.0.0.0.0.0..0.0....0...1c..64.serp..0.0.0.UiQhpfaBsuU"
            webbrowser.open_new_tab(url)
        
        elif "exit" in query:
            speak("see you later")
            exit()
