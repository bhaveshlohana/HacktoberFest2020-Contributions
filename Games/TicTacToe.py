def win(L):
    a=L[0]
    b=L[1]
    c=L[2]
    for i in L:
        if(i[0]==i[1] and i[1]==i[2] and i[2]!=' '):
            return 'a'
    for i in range(3):
        if(a[i]==b[i] and b[i]==c[i] and c[i]!=' '):
            return 'a'
    if(a[0]==b[1] and c[2]==b[1] and b[1]!=' '):
        return 'a'
    if(a[2]==b[1] and c[0]==b[1] and b[1]!=' '):
        return 'a'
    else:
        return 'b'

while(True):
    L=[[' ',' ',' '],[' ',' ',' '],[' ',' ',' ']]
    for i in range(9):
        if(i%2==0):
            j='X'
        else:
            j='O'
        print(L[0])
        print(L[1])
        print(L[2])
        k=0
        while(k==0):
            a=input('Enter the Number of Row :-> ')
            if(a.isdigit() and int(a)>0 and int(a)<4):
                b=input('Enter the Number of Column :-> ')
                if(b.isdigit() and int(b)>0 and int(b)<4):
                    a=int(a)-1
                    b=int(b)-1
                    if(L[a][b]==' '):
                        L[a][b]=j
                        k=1
                    else:
                        print('Space occupied by ',L[a][b],' Try again')
                        continue
                else:
                    print('Enter the Number of Column Correctly')
            else:
                print('Enter the Number of row correctly')
        if(win(L)=='a'):
            print(j, 'won')
            print(L[0])
            print(L[1])
            print(L[2])
            p=int(input('Enter 1 to playagain'))
            if(p!=1):
                break
        elif(not(win(L)=='a')and i==8):
            print('Match Tied')
            print(L[0])
            print(L[1])
            print(L[2])
            p=int(input('Enter 1 to playagain'))
            if(p!=1):
                break
