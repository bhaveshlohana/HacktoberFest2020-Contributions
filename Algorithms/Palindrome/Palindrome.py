my_string = input("Enter a string")	#Input a string
if my_string.casefold()==(my_string.casefold())[::-1]:
    print("Palindrome") 

else:
    #Traversing from both ends of the strings and checking if they are same 
    print("NotPalindrome")
