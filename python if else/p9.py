userNumber=int(input("Please enter a number from 1 through 7:"))

if userNumber==1:
    print("Monday")
elif userNumber==2:
    print("Tuseday")
elif userNumber==3:
    print("Wednesday")
elif userNumber==4:
    print("Thursday")
elif userNumber == 5:
    print("Friday")
elif userNumber == 6:
    print("Saturday")
elif userNumber == 7:
    print("Sunday")
else:
    print(str(userNumber)+"is not a number from 1 to 7.Please enter a correct number")