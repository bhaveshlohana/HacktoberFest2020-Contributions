from tkinter import *
from tkinter import messagebox
import PIL
from PIL import Image, ImageTk

wind= Tk()
wind.title('21 Matches')
mat= ImageTk.PhotoImage(Image.open("images/match.jpg"))
ls=['|']*21
fr = LabelFrame(wind, padx=5, pady=5)
fr.grid(row = 0, column =0, columnspan = 3, padx=8, pady =8)
dic= {f'l{i}':i for i in range(0,21)}
for i in dic:
    col = int(dic[i])
    i = Label(fr, image = mat)
    i.grid(row=0, column = col)


but1= Button(wind, text='1', padx = 10, command = lambda: press(1))
but1.grid(row=1, column=0, columnspan = 3)
but2= Button(wind, text='2', padx = 10,command = lambda: press(2))
but2.grid(row=1, column=1, columnspan = 3)
move = Label(wind, text='YOUR MOVE')
move.grid(row= 2, column =0, columnspan= 3)


def press(inp):
    user_edit(inp)
    o = 1 if inp==2 else 2
    mac_edit(o)

def user_edit(i):
    global ls
    global move
    global bl
    global d
    bl = ImageTk.PhotoImage(Image.open("images/blank.jpg"))
    d = {f'l{k}':k for k in range(len(ls)-i,21)}
    ls = ls[:len(ls)-i]
    for _ in d:
        col = int(d[_])
        _ = Label(fr, image = bl)
        _.grid(row=0, column = col)
    but1.config(state= DISABLED)
    but2.config(state= DISABLED)
    move.config(text= 'MY MOVE')

def push(dic):
    global bl
    global di
    for _ in di:
        wind.after(1000)
        col = int(di[_])
        _ = Label(fr, image = bl)
        _.grid(row=0, column = col)


def mac_edit(o):
    global ls
    global move
    global di
    di = {f'l{k}':k for k in range(len(ls)-o,len(ls))}
    push(di)
    ls = ls[:len(ls)-o]
    but1.after(2000,lambda: but1.config(state= NORMAL))
    but2.after(2000 ,lambda: but2.config(state= NORMAL))
    move.after(2000, lambda: move.config(text= 'YOUR MOVE'))
    if len(ls) == 0:
        ls=['|']*21
        messagebox.showinfo('HAHAH', "I WIN")
        wind.quit()
wind.mainloop()
