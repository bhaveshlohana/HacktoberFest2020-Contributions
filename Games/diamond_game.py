import random
def diamonds_game():
    cards = "AKQJT98765432"
    input_cards = diamond_cards = user_cards = comp_cards = [str(i) for i in string]
    user_bid_list = comp_bid_list = []
    
    card_score = {'A' : 14, 'K' : 13, 'Q' : 12, 'J' : 11, 'T' : 10, '9' : 9, '8' : 8, '7' : 7, '6' : 6, '5' : 5, '4' : 4, '3' : 3, '2' : 2}
    
    def random_input():
        print(input_cards)
        return random.choice(input_cards)
    
    def deletion(input_cards, element):
        updated_list= input_cards.remove(element)
        return input_cards
    
    def top_elements():
        choice = random_input()
        if diamond_top == random_input():
            deletion(comp_cards, choice)

    def stratagies():
        print("Choose the type of stratagy does the computer wanted to perform among\n1. Random\n2. Same as the top\n3. Sequence\n")
        choice = int(input())
        n = 0
        while n != 14:
            if choice == 1:
                comp_input = random_input()
            elif choice == 2:
                comp_input = top_elements()
            elif choice == 3:
                comp_input = sequence_input()
            else:
            	print("Invalid Input. Please try again!!")
            	stratagies()
            n = n + 1
    def play_game():
        diamond_top_card = random_input()
        print("Diamond card on top is : " + diamond_top_card)
        print("User input is : ")
        user_bid = str(input())
        comp_input = stratagies()

    def is_compare(user_bid, comp_input, diamond_top_card):
        if user_bid > comp_input:
            user_bid_list = user_bid_list.append(user_bid)
        elif user_bid < comp_input:
            comp_bid_list = comp_bid_list.append(comp_input)
        return (user_bid_list, comp_bid_list)

    def calculate_score(user_bid_list):
        play_game()
        return sum([item_values.get(i) for i in user_bid_list])
    print(calculate_score(user_bid_list))

diamonds_game()
