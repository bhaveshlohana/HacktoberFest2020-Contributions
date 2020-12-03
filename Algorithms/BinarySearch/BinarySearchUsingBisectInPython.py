# Python code to demonstrate the working of 
# insort(), insort_left() and insort_right() 
  
# importing "bisect" for bisection operations 
import bisect 
  
# initializing list 
li1 = [1, 3, 4, 4, 4, 6, 7] 
  
# initializing list 
li2 = [1, 3, 4, 4, 4, 6, 7] 
  
# initializing list 
li3 = [1, 3, 4, 4, 4, 6, 7] 
  
# using insort() to insert 5 at appropriate position 
# inserts at 6th position 
bisect.insort(li1, 5) 
  
print ("The list after inserting new element using insort() is : ") 
for i in range(0, 7): 
    print(li1[i], end=" ") 
  
# using insort_left() to insert 5 at appropriate position 
# inserts at 6th position 
bisect.insort_left(li2, 5) 
  
print("\r") 
  
print ("The list after inserting new element using insort_left() is : ") 
for i in range(0, 7): 
    print(li2[i], end=" ") 
  
print("\r") 
  
# using insort_right() to insert 5 at appropriate position 
# inserts at 5th position 
bisect.insort_right(li3, 5, 0, 4) 
  
print ("The list after inserting new element using insort_right() is : ") 
for i in range(0, 7): 
    print(li3[i], end=" ")
