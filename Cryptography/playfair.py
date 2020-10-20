key = list(input("Please enter the key: ").lower())

matrix = [[False for i in range(5)] for j in range(5)]
di = {chr(x):False for x in range(97, 123)}
di.pop('j')

i, j = 0, 0
for x in key:
    if x == 'j':
        x = 'i'
    if di[x] == False:
        matrix[i][j] = x
        di[x] = (i, j)
        j = j + 1
        if j == 5 :
            j = 0
            i = i + 1
            if i == 5:
                break

if matrix[-1][-1] == False:
    for x in range(97, 123):
        x = chr(x)
        if x == 'j' :
            continue
        if di[x] == False:
            matrix[i][j] = x
            di[x] = (i, j)
            j = j + 1
            if j == 5 :
                j = 0
                i = i + 1
                if i == 5:
                    break

print("The matrix is: ")
for i in range(5):
    print(" ".join(matrix[i]))

choice = int(input("Press 1 to encrypt \n" + 
                    "Press 2 to decrypt \n" +
                    "Enter your choice: "))
if choice == 1 :                
    text = list(input("Enter text to be encrypted: ").replace(" ", ""))
    prev = text[0]
    for i in range(1, len(text)) :
        if text[i] == prev :
            text.insert(i, 'x') #Adding fillers
        prev = text[i]

    if len(text)%2 != 0 :
        text.append('x')

    output = []
    for i in range(0, len(text), 2) :
        a, b = text[i], text[i+1]
        posa, posb = di[a], di[b]

        #checking for same row
        if posa[0] == posb[0] :
            output.append(matrix[posa[0]][(posa[1] + 1)%5])
            output.append(matrix[posb[0]][(posb[1] + 1)%5])
        
        #checking for same column
        elif posa[1] == posb[1] :
            output.append(matrix[(posa[0] + 1)%5][posa[1]])
            output.append(matrix[(posb[0] + 1)%5][posb[1]])

        else:
            output.append(matrix[posa[0]][posb[1]])
            output.append(matrix[posb[0]][posa[1]])
    
    print("Encrypted text is: ", "".join(output))

else: 

    text = list(input("Enter text to be decrypted: ").replace(" ", ""))
    prev = text[0]
    for i in range(1, len(text)) :
        if text[i] == prev :
            text.insert(i, 'x') #Adding fillers
        prev = text[i]

    if len(text)%2 != 0 :
        text.append('x')

    output = []
    for i in range(0, len(text), 2) :
        a, b = text[i], text[i+1]
        posa, posb = di[a], di[b]

        #checking for same row
        if posa[0] == posb[0] :
            output.append(matrix[posa[0]][(posa[1] - 1)%5])
            output.append(matrix[posb[0]][(posb[1] - 1)%5])
        
        #checking for same column
        elif posa[1] == posb[1] :
            output.append(matrix[(posa[0] - 1)%5][posa[1]])
            output.append(matrix[(posb[0] - 1)%5][posb[1]])

        else:
            output.append(matrix[posa[0]][posb[1]])
            output.append(matrix[posb[0]][posa[1]])
    
    print("Decrypted text is: ", "".join(output))
