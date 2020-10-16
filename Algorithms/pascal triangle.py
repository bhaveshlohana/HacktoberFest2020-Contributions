def fact(n):
    res=1
    for c in range(1,n+1):
        res = res*c
    
    return res

rows = int(input("Enter the number of rows : "))

for i in range(0, rows):
    for j in range(1, rows-i):
        print("  ", end="")

    for k in range(0, i+1):
        coff = int(fact(i)/(fact(k)*fact(i-k)))
        print("  ", coff, end="")
    
    print()
