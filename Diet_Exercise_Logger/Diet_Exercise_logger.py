# DietExerciseLogger 
# you can add your own client/name

def getdate():
	
	import datetime
	time = datetime.datetime.now()
	return time

def edit(clientname):
	
	print("enter 1 or 2")
	task = int(input("1:edit diet\n2:edit exercise\n:"))
	
	if task==1:
		#writing in file
		filename = f"{clientname}_diet.txt"
		with open(filename,"a") as f:
			while True:
				food = str(input('enter the food you ate:-\nenter end to exit\n:'))
				
				if food=='end':
					print("Succesfull")
					break
				
				time = '['+str(getdate())+']'
				f.write(time)
				f.write('\t')
				f.write(food)
				f.write('\n')
				print('\n')
		
	elif task==2:
		filename = f"{clientname}_exe.txt"
		with open(filename,"a") as f:
			while True:
				exercise = str(input('enter the exercise you done-\nenter end to exit\n:'))
				
				if exercise=='end':
					print("Succesfull")
					break
				
				time = '['+str(getdate())+']'
				f.write(time)
				f.write('\t')
				f.write(exercise)
				f.write('\n')
				print('\n')
	
	else:
		print('enter a relewant no.')

def display(clientname):

	try:	
		task = int(input("1:show diet\n2:show exercise\n: "))
		
		if task==1:
			
			filename=f"{clientname}_diet.txt"
			with open(filename) as f:
				print("The food items are\n******XxX******")
				for lines in f:
					print(lines,end='')

		elif task==2:
			filename=f"{clientname}_exe.txt"
			with open(filename) as f:
				print("The exercise are\n******XxX******")
				for lines in f:
					print(lines,end='')
		else:
			print('enter a relewant no.')
	except:
		print("\nclient not found")

def clear(clientname):

	#the truncate() function is used to clear all files in a text file 
	#if we open in read mode than use truncate(0)
	
	try:

		task = int(input("1:clear diet\n2:clear exercise\n: "))

		if task==1:
			filename=f"{clientname}_diet.txt"
			with open(filename,"r+") as f:
				f.truncate(0)

		elif task==2:
			filename=f"{clientname}_exe.txt"
			with open(filename,"r+") as f:
				f.truncate(0)
		
		else:
			print('enter a relewant no.')
	except:
		print("\nclient not found")

print('WELCOME TO DIET-EXERCISE-LOGGER')

while True:
	
	task=int(input("\n1:add/edit diet/exercise\n2:display diet/exercise\n3:clear diet/exercise\n4:Exit\n: "))
			
	if task==1:
		client = str(input("enter your name or client name:\n"))
		edit(client)
	
	elif task==2:
		client = str(input("enter your name or client name:"))
		display(client)
	
	elif task==3:
		client = str(input("enter your name or client name:"))
		clear(client)
	
	elif task==4:
		break

	else:
		print('enter a relevant option')


