from tkinter import *
from itertools import permutations
from tkinter import messagebox

root = Tk()

root.title("welcome to my tictoe game")
root.geometry("400x500+0+0")
current = 1
moves = 0
buttons = []
player_1 = []
player_2 = []
winMoves = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
    [1, 4, 7],
    [2, 5, 8],
    [3, 6, 9],
    [1, 5, 9],
    [3, 5, 7]
]
#======functions=======#


def func(event):
    global current, moves, winMoves
    if event.widget.cget('text')=='X' or event.widget.cget('text')=='O':
        messagebox.showwarning('wrong move', 'please select another box')
    elif(current == 1):
        player_1.append(int(event.widget.cget('text')))
        current = 2
        moves = moves+1
        event.widget.configure( bg= "green")
        event.widget.configure( text= "X")
        player_1.sort(reverse=False)
    else:
        player_2.append(int(event.widget.cget('text')))
        current = 1
        moves = moves+1
        event.widget.configure( bg= "yellow")
        event.widget.configure( text= "O")
        player_2.sort(reverse=False)
    if(moves>=5):
        list1=list(permutations(player_1,3))
        list2=list(permutations(player_2,3))
        for item in list1:
            if list(item) in winMoves:
                
                p1=1
                messagebox.showinfo('Game End',"PLayer 1 Won....!!! meow meow meow")
        if(moves>5):
            for item in list2:
                if list(item) in winMoves:
                    p2=1
                    messagebox.showinfo('Game End',"PLayer 2 Won....!!! meow meow meow")

    # print(player_1,player_2)




lbl=Label(root,text="Tictac", font=("times new roman",30,"bold"),bg="blue",fg="white",bd=7,relief=GROOVE,pady=2).pack(fill=X)

#=======game board===========#
F1 = LabelFrame(root,text="titctac board", font=("arial", 30,"bold"))
F1.place(x=0,y=65,relwidth=1)
no=1
for i in range(3):
    for j in range(3):
        b=Button(F1,text=no,bd=7, relief=GROOVE,bg="blue" , font="arial 25 bold")
        b.grid(row=i,column=j ,padx=10,pady=10)
        b.bind("<Button-1>", func)
        buttons.append(b)
        no=no+1




root.mainloop()
