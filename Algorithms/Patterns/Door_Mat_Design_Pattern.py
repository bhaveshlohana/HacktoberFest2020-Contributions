print("Enter size of mat NxM")
print("Try to put M 3 times of N to get a good pattern ;)")
n,m=[int(y) for y in input().split()]
halfnolines=(n-1)//2
t=halfnolines
for i in range(1,halfnolines+1):
    b=2*i-1
    print("-"*3*t+".|."*b+"-"*3*t)
    t=t-1
#print("WELCOME")
a=(3*halfnolines*2+1-7)//2+1
print("-"*a+"WELCOME"+"-"*a)
t=1
for i in range(halfnolines):
    print("-"*3*t+".|."*b+"-"*3*t)
    t=t+1
    b-=2
