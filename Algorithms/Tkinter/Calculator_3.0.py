#!/usr/bin/env python3
from tkinter import *

root = Tk()
root.title('simple calculator')
root.configure(bg='#483D8B')
e = Entry(root, width=30, fg='white', bg='#5577ff', borderwidth=5)
d = Text(root, width=26, height=4, fg='white', bg='#ff7788', borderwidth=2)
d.insert(END, 'Debug Output')

f_num = None
op = None
s_num = None
pre_op = None
op_flag = False


def debug(error):
    if error != '':
        d.insert(END, f'\n{error}')
    else:
        d.insert(END, f'\n{"-" * 7} \n f_num:{f_num} \n op:{op}\n pre_op:{pre_op}\n s_num:{s_num}\n{"-" * 7}')


def b_click(n):
    if e.get() != '':
        prev = e.get()
        clr()
        e.insert(0, prev + str(n))
    else:
        e.insert(0, n)


def b_do(s):
    global f_num, op, op_flag, pre_op
    try:
        f_num = float(e.get())
    except Exception as error:

        debug(error)
    pre_op = op
    op = s

    op_flag = True
    clr()


def b_eq():
    global s_num, op, f_num, op_flag, pre_op
    if not op_flag:
        s_num = float(e.get())
        clr()
        e.insert(0, s_num)
        debug('')
    else:
        try:
            s_num = float(e.get())
        except Exception as err:

            debug(err)
        clr()
        debug('')
        if f_num is None:
            f_num = 0
        if s_num is None:
            s_num = 0
        else:
            if op == '+':
                e.insert(0, f_num + s_num)
                f_num = float(e.get())
                op_flag = False
            elif op == '-':
                e.insert(0, f_num - s_num)
                f_num = float(e.get())
                op_flag = False
            elif op == '*':
                e.insert(0, f_num * s_num)
                f_num = float(e.get())
                op_flag = False
            elif op == '/':
                if s_num != 0:
                    e.insert(0, f_num / s_num)
                    f_num = float(e.get())
                    op_flag = False
                else:
                    e.insert(0, 'ZeroDivisionError')
                    op_flag = False
            elif op is None:
                e.insert(0, s_num)

            else:
                e.insert(0, 'Error@391')


def clr():
    e.delete(0, END)


b0 = Button(root, text='0', padx=14, pady=10, command=lambda: b_click(0), width=10)
b1 = Button(root, text='1', padx=14, pady=10, command=lambda: b_click(1), width=10)
b2 = Button(root, text='2', padx=14, pady=10, command=lambda: b_click(2), width=10)
b3 = Button(root, text='3', padx=14, pady=10, command=lambda: b_click(3), width=10)
b4 = Button(root, text='4', padx=14, pady=10, command=lambda: b_click(4), width=10)
b5 = Button(root, text='5', padx=14, pady=10, command=lambda: b_click(5), width=10)
b6 = Button(root, text='6', padx=14, pady=10, command=lambda: b_click(6), width=10)
b7 = Button(root, text='7', padx=14, pady=10, command=lambda: b_click(7), width=10)
b8 = Button(root, text='8', padx=14, pady=10, command=lambda: b_click(8), width=10)
b9 = Button(root, text='9', padx=14, pady=10, command=lambda: b_click(9), width=10)
bplus = Button(root, text='+', padx=14, pady=10, command=lambda: b_do('+'), width=10)
bsb = Button(root, text='-', padx=14, pady=10, command=lambda: b_do('-'), width=10)
bml = Button(root, text='*', padx=14, pady=10, command=lambda: b_do('*'), width=10)
bdiv = Button(root, text='/', padx=14, pady=10, command=lambda: b_do('/'), width=10)
beq = Button(root, text='=', padx=14, pady=10, command=b_eq, width=10)
bclr = Button(root, text='Clear', padx=14, pady=10, command=clr, width=10)
bdot = Button(root, text='.', padx=14, pady=10, command=lambda: b_click('.'), width=10)

b1.grid(row=1, column=0)
b2.grid(row=1, column=1)
b3.grid(row=1, column=2)

b4.grid(row=2, column=0)
b5.grid(row=2, column=1)
b6.grid(row=2, column=2)

b7.grid(row=3, column=0)
b8.grid(row=3, column=1)
b9.grid(row=3, column=2)

b0.grid(row=4, column=1)
bplus.grid(row=4, column=0)
bsb.grid(row=4, column=2)

bml.grid(row=5, column=2)
bdiv.grid(row=5, column=0)

bclr.grid(row=6, column=2)
d.grid(row=6, column=0, rowspan=2, columnspan=2)
beq.grid(row=7, column=2)

e.grid(row=0, column=0, columnspan=3, padx=15, pady=10)
bdot.grid(row=5, column=1)

root.mainloop()
