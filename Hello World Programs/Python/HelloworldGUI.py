import tkinter as tk
import time
from tkinter.constants import ANCHOR, CENTER

def safeexit():
    time.sleep(0.2)
    root.destroy()

def hovering(e):
    button['background'] = 'green'
    button['foreground'] = 'white'


def nothovering(e):
    button['background'] = '#F5F5F5'
    button['foreground'] = '#333333'

root=tk.Tk()
root.title("Hello World")
root.resizable(0,0)
root.geometry('350x200+600+200')
root.config(bg="black")

button = tk.Button(root, text = "Hello World", font = ("Tahoma", 16), width = 12, bg = "#F5F5F5", fg = "#333333", relief = "raised", command = safeexit)
button.place(relx=0.28, rely=0.38)

button.bind("<Enter>",hovering)
button.bind("<Leave>",nothovering)
root.mainloop()
