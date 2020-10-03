n = int(input("Enter an input number"))

f = False
for i in range(2,n):
    if n%i==0:
        f = True

if f:
    print("Not Prime")
else:
    print("Prime")
