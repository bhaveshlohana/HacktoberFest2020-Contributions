from random import*
print("wanna play?(y/n)")
c=str(input())
if(c=="y"):
 m_c=0
 m_u=0
 print("Let's play stone paper scissor\nhere\n1 for stone\n2 for paper\n3 for scissor\nNOW LET'S PLAY")
 for i in range(5):
  print("your turn:")
  n=int(input())
  a=randint(0,3)
  print("I chose %d" %(a))
  if(n==1 and a==2):
   m_c+=1
  if(n==2 and a==1):
   m_u+=1
  if(n==2 and a==3):
   m_c+=1
  if(n==3 and a==2):
   m_u+=1
  if(n==1 and a==3):
   m_u+=1
  if(n==3 and a==1):
   m_c+=1
 print("your score=%d\ncomputer score=%d" %(m_u,m_c))
 if(m_u>m_c):
  print("You Won the Game..!!")
 elif(m_u==m_c):
  print("it's a draw Match")
 else:
  print("Better Luck Next Time..")
if(c=='n'):
 print("Then Bye")
