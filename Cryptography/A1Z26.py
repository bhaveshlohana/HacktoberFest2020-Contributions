def A1Z26(text):
    ciphered = ""
    count = 0
    for letter in text:
        number = ord(letter)
        if letter == " ":
            ciphered += " "
        elif number >= 97:
            number -= 96
        elif number >= 65:
            number -= 64
        ciphered += str(number)
        count += 1
        if count != len(text):
            if letter != " ":
                if text[count] != " ":
                    ciphered += "-"
    print(ciphered)
