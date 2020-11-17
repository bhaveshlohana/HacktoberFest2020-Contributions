def isArmstrong(num): #calling armstrong function
  sum=0;              #used to storethe reversed number
  a=num               #copy to another variable
  while num>0:        #reversing function
      digit=num%10    
      sum=sum+pow(digit,3)  #storing reverse values one by one
      num=num//10
  if sum==a:          #checking if the reversed value equals given value
      return True
  else:
      return False 
    
if __name__ == "__main__":  #main function
    n=int(input("enter the number"))   #input

    if isArmstrong(n):   #calling function
        print(f"{n} is Armstrong")   #printing with proper Format
    else:
        print(f"{n} is not Armstrong")    ##printing with proper Format
