#!/bin/python3

import turtle

def circle(size):
	turtle.showturtle()
	turtle.shape('turtle')
	turtle.pensize(20)
	turtle.circle(size)

def eye(size):
	list = ['red','green','red']
	for i in list:
		turtle.pencolor(i)
		circle(size)
		size+=40
	turtle.hideturtle()

def semi(size):
	i = turtle.pos()
	while True:
		turtle.right(30)
		turtle.forward(size)
		f = turtle.pos()
		if i[0]== f[0]: break

turtle.bgcolor('black')
turtle.pencolor('black')
pos = turtle.pos()
turtle.goto(pos[0]-150,pos[1])
eye(20)
turtle.goto(150+pos[0],pos[1])
eye(20)
turtle.penup()
pos = turtle.pos()
turtle.goto(pos[0]-300,pos[1]-100)
turtle.pendown()
list2 = [300,80,300,80]
for i in list2:
    turtle.forward(i)
    turtle.right(90)
turtle.done()
