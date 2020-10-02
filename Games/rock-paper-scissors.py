from random import randint


choice = ["Rock", "Paper", "Scissors"]

opponent = choice[randint(0, 2)]

player = False

while player == False:
    player = input("Rock, Paper, Scissors?: ")
    print("Opponent chose: ", opponent)
    if player == opponent:
        print("Tie!")
    elif player == "Rock":
        if opponent == "Paper":
            print("You lose! Paper beats Rock.")
        else:
            print("You win!", player, "beats", opponent)
    elif player == "Paper":
        if opponent == "Scissors":
            print("You lose!", opponent, "beats", player)
        else:
            print("You win!", player, "beats", opponent)
    elif player == "Scissors":
        if opponent == "Rock":
            print("You lose...", opponent, "beats", player)
        else:
            print("You win!", player, "beats", opponent)
    else:
        print("Input Error")
    player = False
    opponent = choice[randint(0, 2)]
