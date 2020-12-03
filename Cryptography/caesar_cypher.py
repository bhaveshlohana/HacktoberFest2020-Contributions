import string
from collections import deque

def Caesar_Cypher(string_to_translate, number_of_rotations):
    
    upper = deque(string.ascii_uppercase,maxlen=26)
    lower = deque(string.ascii_lowercase,maxlen=26)

    # print(upper)
    # print(lower)

    upper.rotate(number_of_rotations)
    lower.rotate(number_of_rotations)

    # print(upper)
    # print(lower)

    upper_string = ''.join(list(upper))
    lower_string = ''.join(list(lower))

    # print(upper_string)
    # print(lower_string)

    return string_to_translate.translate(str.maketrans(string.ascii_uppercase, upper_string)).translate(str.maketrans(string.ascii_lowercase, lower_string))

input_string = input("Enter string u want to translate ")
rotate_by = int(input("Enter the number u want to rotate by "))
print(f"Translated string is {Caesar_Cypher(input_string,rotate_by)}")

