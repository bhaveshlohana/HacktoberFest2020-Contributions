msg = input()
shift = int(input())
def fn(msg,shift): 
    ans = "" 
    for i in range(len(msg)): 
        char = msg[i] 
        if (char.isupper()): 
            ans += chr((ord(char) + shift-65) % 26 + 65)  
        else: 
            ans += chr((ord(char) + shift-97) % 26 + 97) 
    return ans
print ("After Encryption of the message with the given shift : " + fn(msg,shift))
