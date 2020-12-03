n=int(input("Enter a number: "))
if (n-1)%8==0:
    print("Thumb!")
elif (n-3)%4==0:
    print("Middle Finger!")
elif (n-5)%8==0:
    print("Small Finger!")
else:
    while True:
        n=n-2
        if n==0:
            print("Index Finger!")
            break
        n=n-6
        if n==0:
            print("Index Finger!")
            break
        if n<0:
            print("Ring Finger!")
            break
        else:
            continue
