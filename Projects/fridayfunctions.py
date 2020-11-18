import wikipedia
import webbrowser
import random
import os
import datetime
import time
import subprocess
import speakandrecognizefunctions as SRF

USER = "sumesh"


def wishme():
    hour = int(datetime.datetime.now().hour)
    if hour >= 0 and hour <= 12:
        SRF.speak("good morning! " + USER)
    elif hour >= 12 and hour < 18:
        SRF.speak("good aftenoon! " + USER)
    else:
        SRF.speak("good evening! " + USER)


def note(text):

    date = datetime.datetime.now()
    filename = str(date).replace(":", "-")+"-note.txt"

    try:
        os.mkdir("notes_folder")
    except FileExistsError:
        pass

    completename = os.path.join("notes_folder", filename)
    with open(completename, "w") as f:
        f.write(text)
        f.close()

    subprocess.Popen(["notepad.exe", completename])


def wikipediasearch(query):
    try:
        #SRF.speak("What do you want to search for ?")
        #wikiquery = SRF.takecommand()
        query = query.replace("wikipedia", "")
        query = query.replace("search", "")
        query = query.replace(" on ", "")
        wikiquery = query.replace("for", "")
        SRF.speak('searching wikipedia.....')
        print("this is the wikipedia query :" + wikiquery)
        results = wikipedia.summary(wikiquery, sentences=2)
        time.sleep(2)
        SRF.speak("according to wikipedia")
        print(results)
        SRF.speak(results)
    except:
        SRF.speak("i did not get that !!")


def open_programs_websites(query):
    #chrome_path = "C:\\Program Files (x86)\\Google\\Chrome\\Application\\chrome.exe %s"
    query = query.replace("open ", "")

    if "youtube" in query:
        SRF.speak("opening youtube")
        #webbrowser.get(chrome_path). open_new_tab("youtube.com")
        webbrowser.open('http://youtube.com', new=2)
        print("opened youtube")

    elif "github" in query:
        SRF.speak("opening github")
        webbrowser. open_new_tab("https://github.com/")

    elif "code" in query:
        SRF.speak("opening visual studio code")
        codepath = "C:\\Users\\Sumesh Pandit\\Desktop\\CPP Code\\main.cpp"
        os.startfile(codepath)


def googlesearch(query):
    SRF.speak('searching on google.....')
    url = "https://www.google.co.in/search?q=" + (str(query)) + "&oq="+(str(
        query))+"&gs_l=serp.12..0i71l8.0.0.0.6391.0.0.0.0.0.0.0.0..0.0....0...1c..64.serp..0.0.0.UiQhpfaBsuU"
    webbrowser.open_new_tab(url)


def playmusic():
    SRF.speak("playing music ")
    try:
        os.mkdir("music_folder")
    except FileExistsError:
        pass
    songs = os.listdir("music_folder")

    num = random.randint(0, len(songs))
    os.startfile(os.path.join("music_folder", songs[num-1]))
