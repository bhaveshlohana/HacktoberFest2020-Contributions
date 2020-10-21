a=int(input("Enter the first number: "))
b=int(input("Enter the second number: "))
c=int(input("Enter the third number: "))
if(a>b and a>c):
    print("a"+str(a)+"is maximum")
elif(b>a and b>c):
    print("b"+str(b)+"is maximum")
else:
    print("c"+str(c)+"is maximum")