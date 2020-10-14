def isArmstrong(num):
  sum=0;
  a=num
  while num>0:
      digit=num%10
      sum=sum+pow(digit,3)
      num=num//10
  if sum==a:
      return True
  else:
      return False 
    
if __name__ == "__main__":
    n=int(input("enter the number"))

    if isArmstrong(n):
        print(f"{n} is Armstrong")
    else:
        print(f"{n} is not Armstrong")
