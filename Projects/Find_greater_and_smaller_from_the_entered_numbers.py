largest_no=None
smallest_no=None

while True:


    no = input("Enter the no.")

    if no == 'done' :
    	break


    try:


    	no=int(no)



    except:

        print("Invalid input")
        continue


    if largest_no is None:

            largest_no = no
    elif no> largest_no:

            largest_no = no

    if  smallest_no is None:

            smallest_no = no

    elif no< smallest_no:

            smallest_no = no


print ("Maximum is", largest_no)
print ("Minimum is", smallest_no)
