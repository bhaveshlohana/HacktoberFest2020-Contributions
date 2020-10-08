from tkinter import *
import sqlite3 as sq
from tkinter import messagebox

conn = sq.connect('address_book.db')
c=conn.cursor()
root=Tk()
root.geometry("338x500")
root.title("ADDRESS BOOK")


'''c.execute("""Create table address (
first_name text,
phone_no integer,
address text,
relation text)""")'''

def exit():
    mb = messagebox.askyesno("Exit","Do you really want to exit!! :-(")
    if mb == True:
        quit()

def submit():
    conn = sq.connect('address_book.db')
    c = conn.cursor()
    c.execute("Insert into address values (:first_name,:phone_no,:address,:relation)",
              {
                  'first_name': C_name.get(),
                  'phone_no': phone_no.get(),
                  'address': address_book.get(),
                  'relation': relation1.get()
              })
    conn.commit()
    conn.close()

    C_name.delete(0,END)
    phone_no.delete(0,END)
    address_book.delete(0,END)
    relation1.delete(0,END)






def add():
    conn = sq.connect('address_book.db')
    c = conn.cursor()
    c.execute("select *,oid from address")
    a=c.fetchall()
    conn.commit()
    conn.close()
    print_record=''
    #Creating a query
    for i in a:
        print_record+=str(i[0]) + "     "+str(i[4]) +"\n" +str(i[1]) +"\n" +str(i[2]) +"\n"+str(i[3]) + "\n" + "-------------------------------------------------------------" + "\n"
        Label_add2=Label(root,text=print_record)
        Label_add2.grid(row=11,column=0,columnspan=2)

def delete():
    conn = sq.connect('address_book.db')
    c = conn.cursor()
    c.execute("delete from address where oid= " + delete_box.get())

    conn.commit()
    conn.close()



C_name = Entry(root,width=30)
C_name.grid(row=1,column=1,pady=(10,0))
phone_no = Entry(root,width=30)
phone_no.grid(row=2,column=1)
address_book = Entry(root,width=30)
address_book.grid(row=3,column=1)
relation1 = Entry(root,width=30)
relation1.grid(row=4,column=1)

delete_box=Entry(root,width=30)
delete_box.grid(row=5,column=1)

#create a delete btn
del_btn=Button(root,text="DELETE ID",padx=45,bg="black",fg="white",command=delete)
del_btn.grid(row=5,column=0)
Label_name=Label(root,bg="purple",fg="white",text="Enter Name:",padx=40)
Label_name.grid(row=1,column=0,pady=(10,0))
Label_phone=Label(root,bg="dark blue",fg="white",text="phone no:",padx=46)
Label_phone.grid(row=2,column=0)
Label_add=Label(root,bg="blue",fg="white",text="Address:",padx=50)
Label_add.grid(row=3,column=0)
Label_rel=Label(root,bg="light blue",fg="white",text="Relation:",padx=49)
Label_rel.grid(row=4,column=0)

Submit_btn=Button(root,text="Add Address to database",padx=100,bg="black",fg="white",command=submit)
Submit_btn.grid(row=6,column=0,columnspan=3)
add_btn = Button(root,text="Show all Addresses",bg="light grey",padx=115,command=add)
add_btn.grid(row=7,column=0,columnspan=3)

clr_btn=Button(root,text="Cancel",padx=145,bg="white",command=exit)
clr_btn.grid(row=8,column=0,columnspan=3)
conn.commit()
conn.close()


root.mainloop()
