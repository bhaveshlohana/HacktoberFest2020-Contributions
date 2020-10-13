plaintext = "DEFENDTHEEASTWALLOFTHECASTLE"
key = "FORTIFICATIONDEFENDTHEEASTWA"
ciphertext = ""

if __name__ == "__main__":
    for index in range(len(plaintext)):
        sum_key_plaintext = (ord(key[index]) - 64) + (ord(plaintext[index]) - 64)
        if sum_key_plaintext > 27:
            ciphertext += chr(sum_key_plaintext - 26 - 1 + 64)
        else:
            ciphertext += chr(sum_key_plaintext - 1 + 64)
    print(ciphertext)