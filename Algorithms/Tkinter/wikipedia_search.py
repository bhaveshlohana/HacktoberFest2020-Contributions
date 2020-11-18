from tkinter import *
from tkinter.font import Font
import wikipedia


def search_me():
    entry_value=entry.get()
    answer_value =wikipedia.summary(entry_value)
    answer.delete(1.0,END)
    answer.insert(INSERT,answer_value)

window=Tk()
window.geometry('500x400+150+100')
topframe=Frame(window)

entry =Entry(topframe)
entry.pack()


button =Button(topframe,text ='search',command =search_me)
button.pack()

topframe.pack(side =TOP)

bottomframe=Frame(window)

scroll =Scrollbar(bottomframe)
scroll.pack(side =RIGHT,fill=Y)

answer = Text(bottomframe,width =50 ,height =20,yscrollcommand=scroll.set,wrap = WORD)
answer.pack(side=LEFT)

scroll.config(command=answer.yview)

bottomframe.pack()

window.mainloop()
