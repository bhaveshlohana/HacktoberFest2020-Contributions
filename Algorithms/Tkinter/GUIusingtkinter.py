#importing tkinter which comes already installed with python 
from tkinter import *
from tkinter import messagebox

#main_window is the parent or the main window
window=Tk()
 
 #giving our gui a title
window.title("Fun GUI")

#size of minimized GUI
window.geometry('350x250')

lb=Label(window,text="Hello to my site!! Wanna see something :-> ")

lb.grid(column=0,row=0)

def buttonchecker():
	messagebox.showinfo("Information","Here is my very own GUI :) ")

#B is our button,here command helps to join the function which will be executed when we click on the button
B=Button(window,text="click here",command=buttonchecker,bg="yellow")

#joined the button to our gui
B.grid(row=0,column=2)

#this command helps in opening our gui window
window.mainloop()