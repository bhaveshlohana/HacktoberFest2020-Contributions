def atbash(string):
    s2=''
    for char in string:
        if char.islower()==True:
            s2+=chr(122-(ord(char)-97))
        elif char.isupper()==True:
            s2+=chr(90-(ord(char)-65))
        else:
            s2+=char
    string=s2
    return string

