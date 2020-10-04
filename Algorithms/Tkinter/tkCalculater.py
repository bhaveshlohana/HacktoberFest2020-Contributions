import tkinter as tk

window=tk.Tk()
window.title('TK CALCULATOR')

eqn=" "

def btnprs(btn):
    global eqn

    if(btn=='c'):
        eqn='0'

    elif(btn=='='):
        result=eval(eqn)
        eqn=str(result)

    else:
        if(eqn=='0'):
            eqn=' '
        
    
        eqn=eqn+btn
        
    label2.config(text=eqn)
    

label1=tk.Label(window,text='Tk Calcutator',fg='black',font='HELVITICA 15 bold')
label1.grid(row=0,columnspan=8,padx=5,pady=3)

label2=tk.Label(window,text='0',bg='white',font='HELVITICA 15 bold',width=15,height=1)
label2.grid(row=1,columnspan=8,padx=5,pady=3)


buttons=[tk.Button for i in range(16)]

buttons[0]=tk.Button(window,text='1',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('1'))
buttons[0].grid(row=2,column=0,padx=8,pady=8)

buttons[1]=tk.Button(window,text='2',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('2'))
buttons[1].grid(row=2,column=1,padx=8,pady=8)

buttons[2]=tk.Button(window,text='3',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('3'))
buttons[2].grid(row=2,column=2,padx=8,pady=8)

buttons[3]=tk.Button(window,text='+',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('+'))
buttons[3].grid(row=2,column=3,padx=8,pady=8)

buttons[4]=tk.Button(window,text='4',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('4'))
buttons[4].grid(row=3,column=0,padx=8,pady=8)

buttons[5]=tk.Button(window,text='5',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('5'))
buttons[5].grid(row=3,column=1,padx=8,pady=8)

buttons[6]=tk.Button(window,text='6',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('6'))
buttons[6].grid(row=3,column=2,padx=8,pady=8)

buttons[7]=tk.Button(window,text='-',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('-'))
buttons[7].grid(row=3,column=3,padx=8,pady=8)

buttons[8]=tk.Button(window,text='7',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('7'))
buttons[8].grid(row=4,column=0,padx=8,pady=8)

buttons[9]=tk.Button(window,text='8',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('8'))
buttons[9].grid(row=4,column=1,padx=8,pady=8)

buttons[10]=tk.Button(window,text='9',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('9'))
buttons[10].grid(row=4,column=2,padx=8,pady=8)

buttons[11]=tk.Button(window,text='X',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('*'))
buttons[11].grid(row=4,column=3,padx=8,pady=8)

buttons[12]=tk.Button(window,text='C',font='HELVITICA 12 bold',width=2,height=1,bg='red',command=lambda:btnprs('c'))
buttons[12].grid(row=5,column=0,padx=8,pady=8)

buttons[13]=tk.Button(window,text='0',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('0'))
buttons[13].grid(row=5,column=1,padx=8,pady=8)

buttons[14]=tk.Button(window,text='=',font='HELVITICA 12 bold',width=2,height=1,bg='light green',command=lambda:btnprs('='))
buttons[14].grid(row=5,column=2,padx=8,pady=8)

buttons[15]=tk.Button(window,text='/',font='HELVITICA 12 bold',width=2,height=1,command=lambda:btnprs('/'))
buttons[15].grid(row=5,column=3,padx=8,pady=8)
