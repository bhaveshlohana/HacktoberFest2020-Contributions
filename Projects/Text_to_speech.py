#first install gtts package on cmd --> pip install gtts  
from gtts import gTTS
#import gTTS from package install
import os #neeed to learn more ...
#inbuild package

#mytext= "Text to speech conversion using python" #we can gave text here too or
#to read the file make file handler
#default method in python which is used to open file open(,"r") and read(mode),it can be write too
fh=open("text.txt","r")
mytext=fh.read().replace("\n"," ") #here i too replace all the line ending with " "

language="en"#variable called language t lang we us fr-->french,en-->english which is supported by gTTS

output=gTTS(text=mytext,lang=language,slow=False) #slow makes False so our audio play in fast speed not in slow speed

output.save("output.mp3") #u can saved ur output in mp3 by calling method call save
fh.close()
os.system("start output.mp3") #for playing audio file
