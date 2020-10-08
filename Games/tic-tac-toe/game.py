from tkinter import *
from tkinter import messagebox


root = Tk()
root.title("Tic-Tac-Toe")

Label(root, text="welcome! please enter name").grid(row=0, columnspan=2)
Label(root, text="player1").grid(row=1, column=0)
Label(root, text="player2").grid(row=2, column=0)
p1 = StringVar()
p2 = StringVar()
Entry(root, textvariable=p1, width=20).grid(row=1, column=1)
Entry(root, textvariable=p2, width=20).grid(row=2, column=1)


def p1w():
    return p1.get() + " wins"


def p2w():
    return p2.get() + " wins"


xi = 0


def game():
    game = Tk()
    game.title('Tic-Tac-Toe')

    def play(b):
        global xi
        if xi % 2 == 0:
            b["text"] = 'X'
            checkwin()
        elif xi % 2 == 1:
            b["text"] = 'O'
            checkwin()
        xi = xi+1
        b.configure(state=DISABLED)

    def disableButton():
        b1.configure(state=DISABLED)
        b2.configure(state=DISABLED)
        b3.configure(state=DISABLED)
        b4.configure(state=DISABLED)
        b5.configure(state=DISABLED)
        b6.configure(state=DISABLED)
        b7.configure(state=DISABLED)
        b8.configure(state=DISABLED)
        b9.configure(state=DISABLED)

    def checkwin():
        if (b1['text'] == 'X' and b2['text'] == 'X' and b3['text'] == 'X' or
            b4['text'] == 'X' and b5['text'] == 'X' and b6['text'] == 'X' or
            b7['text'] == 'X' and b8['text'] == 'X' and b9['text'] == 'X' or
            b1['text'] == 'X' and b5['text'] == 'X' and b9['text'] == 'X' or
            b3['text'] == 'X' and b5['text'] == 'X' and b7['text'] == 'X' or
            b1['text'] == 'X' and b2['text'] == 'X' and b3['text'] == 'X' or
            b1['text'] == 'X' and b4['text'] == 'X' and b7['text'] == 'X' or
            b2['text'] == 'X' and b5['text'] == 'X' and b8['text'] == 'X' or
                b7['text'] == 'X' and b6['text'] == 'X' and b9['text'] == 'X'):
            disableButton()
            messagebox.showinfo("Tic-Tac-Toe", p1w())

        elif(xi == 8):
            messagebox.showinfo("Tic-Tac-Toe", "It is a Tie")

        elif (b1['text'] == 'O' and b2['text'] == 'O' and b3['text'] == 'O' or
              b4['text'] == 'O' and b5['text'] == 'O' and b6['text'] == 'O' or
              b7['text'] == 'O' and b8['text'] == 'O' and b9['text'] == 'O' or
              b1['text'] == 'O' and b5['text'] == 'O' and b9['text'] == 'O' or
              b3['text'] == 'O' and b5['text'] == 'O' and b7['text'] == 'O' or
              b1['text'] == 'O' and b2['text'] == 'O' and b3['text'] == 'O' or
              b1['text'] == 'O' and b4['text'] == 'O' and b7['text'] == 'O' or
              b2['text'] == 'O' and b5['text'] == 'O' and b8['text'] == 'O' or
              b7['text'] == 'O' and b6['text'] == 'O' and b9['text'] == 'O'):
            disableButton()
            messagebox.showinfo("Tic-Tac-Toe", p2w())

    def name():
        s = "welcome!"+p1.get()+" starts the game"
        return s

    Label(game, text=name(), font=("harrington", 24)).grid(row=0, columnspan=3)
    b1 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b1))
    b1.grid(column=1, row=1)
    b2 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b2))
    b2.grid(column=2, row=1)
    b3 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b3))
    b3.grid(column=3, row=1)
    b4 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b4))
    b4.grid(column=1, row=2)
    b5 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b5))
    b5.grid(column=2, row=2)
    b6 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b6))
    b6.grid(column=3, row=2)
    b7 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b7))
    b7.grid(column=1, row=3)
    b8 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b8))
    b8.grid(column=2, row=3)
    b9 = Button(game, text=" ", width=30, height=10,
                relief="raised", command=lambda: play(b9))
    b9.grid(column=3, row=3)


Button(root, text="continue", width=10, height=1,
       command=game, relief="raised").grid(row=3, column=1)

root.mainloop()
