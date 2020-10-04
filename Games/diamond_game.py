import random
def diamonds_game():
    string = "AKQJT98765432"
    input_list = [str(i) for i in string]
    diamond_list = [str(i) for i in string]
    user_input_list = [str(i) for i in string]
    comp_input_list = [str(i) for i in string]
    user_list = []
    comp_list = []
    
    item_values = {'A' : 14, 'K' : 13, 'Q' : 12, 'J' : 11, 'T' : 10, '9' : 9, '8' : 8, '7' : 7, '6' : 6, '5' : 5, '4' : 4, '3' : 3, '2' : 2}
    
    def random_input():
        print(input_list)
        return random.choice(input_list)
    
    def deletion(input_list, element):
        updated_list= input_list.remove(element)
        return input_list
    
    def top_elements():
        choice = random_input()
        if diamond_top == random_input():
            deletion(comp_input_list, choice)

    def stratagies():
        print("Choose the type of stratagy does the computer wanted to perform among\n1. Random\n2. Same as the top\n3. Sequence\n")
        choice = int(input())
        n = 0
        while n != 14:
            if choice == 1:
                comp_input = random_input() 

                n = n + 1   
            elif choice == 2:
                comp_input = top_elements()
                n = n + 1
            elif choice == 3:
                comp_input = sequence_input()
                n = n + 1
    def play_game():
        diamond_input = random_input()
        print("Diamond card on top is : " + diamond_input)
        print("User input is : ")
        user_input = str(input())
        comp_input = stratagies()

    def is_compare(user_input, comp_input, diamond_input):
        if user_input > comp_input:
            user_list = user_list.append(user_input)
        elif user_input< comp_input:
            comp_list = comp_list.append(comp_input)
        return (user_list, comp_list)

    def calculate_score(user_list):
        play_game()
        return sum([item_values.get(i) for i in user_list])
    print(calculate_score(user_list))

diamonds_game()