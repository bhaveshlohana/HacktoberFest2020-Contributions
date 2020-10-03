# Guess The No
n = 45
attempt = 0
NoOfGuess = 9

while NoOfGuess > 0:
    attempt += 1
    print("---------------------------------")
    No = int(input("Enter a No:-"))

    if No == n:
        print("Congratulations You won!")
        print("Total Attempt Taken:-", attempt)
        break

    elif No < n:
        print("Given No is Smaller")

    else:
        print("Given No is Greater")
    NoOfGuess -= 1

    print("---------------------------------")
    if NoOfGuess == 0:
        print("Game Over! The Number was ",n)
    else:
        print("No of Guesses left: ", NoOfGuess)
