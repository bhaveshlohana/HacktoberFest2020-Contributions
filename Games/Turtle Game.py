#!/bin/python3
from turtle import *
from random import randint
import sqlite3

Bet=input("Enter the turtle whom you want to bet on(Raj,Simran,Rahul,Anjali,Dimple,Praneel):")

conn = sqlite3.connect('python2.db') 
c = conn.cursor() 

def create_table(): 
        c.execute('CREATE TABLE IF NOT EXISTS RecordONE (Age REAL, Name TEXT,Sex TEXT,Amt REAL)') 

def data_entry():
    name = input("Enter your name:")
    age = int(input("Enter your age:"))
    sex=input("Enter your gender:")
    amt=int(input("Enter amount of money you want to bet:"))
    c.execute("INSERT INTO RecordONE (age, Name,Sex,Amt) VALUES(?,?,?,?)", (age, name,sex,amt))
    p=amt
    conn.commit() 

create_table() 
data_entry() 

c.close() 
conn.close() 

speed(10)

penup()
goto(-140,140)

for steps in range(15):
  write(steps,align="center")
  right(90)
  forward(10)
  pendown()
  forward(230)
  penup()
  backward(240)
  left(90)
  forward(20)
  
forward(20)
Raj = Turtle()
Raj.color('red')
Raj.shape('turtle')
Raj.penup()
Raj.goto(-160,100)
Raj.pendown()

Simran = Turtle()
Simran.color('green')
Simran.shape('turtle')
Simran.penup()
Simran.goto(-160,70)
Simran.pendown()

Rahul = Turtle()
Rahul.color('yellow')
Rahul.shape('turtle')
Rahul.penup()
Rahul.goto(-160,40)
Rahul.pendown()

Anjali = Turtle()
Anjali.color('blue')
Anjali.shape('turtle')
Anjali.penup()
Anjali.goto(-160,10)
Anjali.pendown()

Dimple = Turtle()
Dimple.color('black')
Dimple.shape('turtle')
Dimple.penup()
Dimple.goto(-160,-20)
Dimple.pendown()

Praneel = Turtle()
Praneel.color('grey')
Praneel.shape('turtle')
Praneel.penup()
Praneel.goto(-160,-50)
Praneel.pendown()

Winner = []

A=0
B=0
C=0
D=0
E=0
F=0

for turn in range(100):
  a=randint(1,5)
  A=A+a
  if(A>=300):
    Winner.append("Raj")
  Raj.forward(a)

  b=randint(1,5)
  B=B+b
  if(B>=300):
    Winner.append("Simran")
  Simran.forward(b)

  c=randint(1,5)
  C=C+c
  if(C>=300):
    Winner.append("Rahul")
  Rahul.forward(c)

  d=randint(1,5)
  D=D+d
  if(D>=300):
    Winner.append("Anjali")
  Anjali.forward(d)

  e=randint(1,5)
  E=E+e
  if(E>=300):
    Winner.append("Dimple")
  Dimple.forward(e)

  f=randint(1,5)
  F=F+f
  if(F>=300):
    Winner.append("Praneel")
  Praneel.forward(f)

Result=Winner[0]

if (Bet == Result):
  p=p*4
  print("You WON \n")
  print("Congrats you earned :Rs",p)

else:
  print("You LOST \n")
