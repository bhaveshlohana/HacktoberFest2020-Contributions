print("Welcome to Caesar Cipher in Python")
print("Enter a string")

string = input()

print("Enter the number by which the alphabets are to be moved")

num = int(input())

op_string=''

for s in string:
    asc = ord(s)
    if(asc>=48 and asc<=57):
        mod = num%10
        ch = chr(asc + mod)
        op_string+=str(ch)
    
    elif (asc>=65 and asc<=90) or (asc>=97 and asc<=122):
        mod = num%26
        ch = chr(asc + mod)
        op_string+=str(ch)

print("The SHifted & Encoded string is:")
print(op_string)
