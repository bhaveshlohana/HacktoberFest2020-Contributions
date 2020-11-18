x = int(input("enter a number: "))
factor=[]
i=1
while(i<=x):
    if x%i==0:
        factor.append(i)
        print(i)
    i+=1
print(factor)
