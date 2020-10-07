#To import the tkinter module
import Tkinter
from Tkinter import *

#declare val globally
val = ""
A = 0
op = ""



#button function
def btn1_isclickes():
    global val
    val = val + "1"
    data.set(val)

    


def btn2_isclickes():
    global val
    val = val + "2"
    data.set(val)



def btn3_isclickes():
    global val
    val = val + "3"
    data.set(val)



def btn4_isclickes():
    global val
    val = val + "4"
    data.set(val)


def btn5_isclickes():
    global val
    val = val + "5"
    data.set(val)


def btn6_isclickes():
    global val
    val = val + "6"
    data.set(val)



def btn7_isclickes():
    global val
    val = val + "7"
    data.set(val)


def btn8_isclickes():
    global val
    val = val + "8"
    data.set(val)


def btn9_isclickes():
    global val
    val = val + "9"
    data.set(val)


def btn0_isclickes():
    global val
    val = val + "0"
    data.set(val)
    


def btplus():
    global A
    global op
    global val
    A = int (val)
    op = "+"
    val = val + "+"


def btsub():
    global A
    global op
    global val
    A = int (val)
    op = "-"
    val = val + "-"


def btmul():
    global A
    global op
    global val
    A = int (val)
    op = "x"
    val = val + "x"


def btdiv():
    global A
    global op
    global val
    A = int (val)
    op = "/"
    val = val + "/"
   

def c():
    global A
    global op
    global val
    val = ""
    A = 0
    op = ""
    data.set(val)






def result():
    global A
    global op
    global val
    val3 = val
    if op == "+":
        x = int((val3.split("+")[1]))
        C = A + x
        val = str(C)
        data.set(C)
    elif op == "-":
        x = int((val3.split("-")[1]))
        C = A - x
        data.set(C)
        val = str(C)
            
    elif op == "x":
        x = int((val3.split("x")[1]))
        C = A * x
        data.set(C)
        val = str(C)
                
    elif op == "/":
        x = int((val3.split("/")[1]))
        if x == 0:
            A= ""
            val = ""
            data.set(val)                     
        else:
            
            C = int(A / x)
            data.set(C)
            val = str(C)
            

#to create the window
root = Tkinter.Tk()
root.geometry("450x400+300+300")

#to make it non-resizable
root.resizable(0,0)
root.title("SMARTY")

#to create a lable
data = StringVar()
lbl = Label(
    root,
    text = "label",
    anchor = SE,
    font = ("Verdana",20),
    textvariable = data,
    background = "#000000",
    fg = "#ffff00",
    )
lbl.pack(expand = True, fill = "both",)

 
#to divide the windows in different frames
b1=Frame(root, bg="#000000")
b1.pack(expand = True, fill="both")

b2=Frame(root)
b2.pack(expand = True, fill="both")

b3=Frame(root)
b3.pack(expand = True, fill="both")


b4=Frame(root)
b4.pack(expand = True, fill="both")

#to create the buttons for frame 1
btn1= Button(
     b1,
     text = "1",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn1_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn1.pack(side = LEFT, expand = True, fill= "both")


btn2= Button(
     b1,
     text = "2",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn2_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn2.pack(side = LEFT, expand = True, fill= "both")


btn3= Button(
     b1,
     text = "3",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn3_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn3.pack(side = LEFT, expand = True, fill= "both")


btnadd= Button(
     b1,
     text = "+",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btplus,
     fg = 'green',
     bg = '#000000'
    
     )
btnadd.pack(side = LEFT, expand = True, fill= "both")



#create button for frame2
btn4= Button(
     b2,
     text = "4",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn4_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn4.pack(side = LEFT, expand = True, fill= "both")


btn5= Button(
     b2,
     text = "5",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn5_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn5.pack(side = LEFT, expand = True, fill= "both")


btn6= Button(
     b2,
     text = "6",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn6_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn6.pack(side = LEFT, expand = True, fill= "both")


btnsub= Button(
     b2,
     text = "-",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btsub,
     fg = 'green',
     bg = '#000000'
     )
btnsub.pack(side = LEFT, expand = True, fill= "both")



#create buttons for frame3

btn7= Button(
     b3,
     text = "7",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn7_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn7.pack(side = LEFT, expand = True, fill= "both")


btn8= Button(
     b3,
     text = "8",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn8_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn8.pack(side = LEFT, expand = True, fill= "both")


btn9= Button(
     b3,
     text = "9",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn9_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn9.pack(side = LEFT, expand = True, fill= "both")


btnmul= Button(
     b3,
     text = "x",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btmul,
     fg = 'green',
     bg = '#000000'
     )
btnmul.pack(side = LEFT, expand = True, fill= "both")




#create buttons for frame 4
btnc= Button(
     b4,
     text = "C",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = c,
     fg = 'white',
     bg = '#000000'
     )
btnc.pack(side = LEFT, expand = True, fill= "both")


btn0= Button(
     b4,
     text = "0",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btn0_isclickes,
     fg = 'yellow',
     bg = '#000000'
     )
btn0.pack(side = LEFT, expand = True, fill= "both")


btneq= Button(
     b4,
     text = "=",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = result,
     fg = 'red',
     bg = '#000000'
     )
btneq.pack(side = LEFT, expand = True, fill= "both")


btndiv= Button(
     b4,
     text = "/",
     font = ("Verdana", 18),
     relief = GROOVE,
     border = 0,
     command = btdiv,
     fg = 'green',
     bg = '#000000'
     )
btndiv.pack(side = LEFT, expand = True, fill= "both")






root.mainloop()

