import pyttsx3
import speech_recognition as sr


engine = pyttsx3.init('sapi5')
voices = engine.getProperty('voices')
engine.setProperty('voice', voices[1].id)


def speak(text):
    engine.say(text)
    engine.runAndWait()


def takecommand():
    r = sr.Recognizer()

    with sr.Microphone() as source:
        #r.adjust_for_ambient_noise(source, duration=0.5)
        audio = r.listen(source)
        said = ""

        try:
            said = r.recognize_google(audio)
            print(said)

        except Exception as e:
            speak("I didnt get that !!")
            print("Exception !! call for friday again " + str(e))
            pass

    return said.lower()


def takecommandbackground():
    r = sr.Recognizer()
    with sr.Microphone() as source:
        r.adjust_for_ambient_noise(source, duration=0.3)
        # print("Listening....")
        audio = r.listen(source, phrase_time_limit=4)

        try:
            # print("Recognizing....")
            query = r.recognize_google(audio)
            #print("user said : ", query)
            # speak(query)

        except Exception:
            #print("Say that again please !! ")
            return "none"
    return query.lower()
