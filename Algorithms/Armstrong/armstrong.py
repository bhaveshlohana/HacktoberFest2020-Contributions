def isArmstrong(num):
  sum=0;
  a=num
  while num>0:
      digit=num%10
      sum=sum+pow(digit,noOfDigits(a))
      num=num//10
  if sum==a:
      return True
  else:
      return False 
def noOfDigits(n) :
  c=0
  while n > 0:
      digit = n %10
      c=c+1 
      n = n //10
  return c

if __name__ == "__main__":
    n=int(input("enter the number :"))

    if isArmstrong(n):
        print(f"{n} is Armstrong")
    else:
        print(f"{n} is not Armstrong")
