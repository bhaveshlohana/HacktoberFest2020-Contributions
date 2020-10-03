import tkinter as tk
from tkinter import ttk
import pyqrcode

i=1
root=tk.Tk()
root.title("QR Code Generator")
ttk.Label(root,text='Enter or Paste Your link: ').grid(row=0,column=0)
var=tk.StringVar()
ttk.Entry(root,width=20,textvariable=var).grid(row=0,column=1)
def submit():
    global i
    link=var.get()
    pyqrcode.create(link).svg("qrcode"+str(i)+".svg", scale = 8)
    i+=1
i=1
ttk.Button(root,text='Generate',command=submit).grid(row=1,column=0)
root.mainloop()
