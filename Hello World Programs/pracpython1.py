sum = 0

while True:
    user_input = input("enter the item price or press q to quit: \n")
    if user_input!='q':
        sum = sum + int(user_input)
        print(f"order total so far: {sum}")

    else:
        print(f"your bill total is {sum}. thnks for visiting")
        break


