#Python program to print all prime numbers between less than or equal to n

'''
   what is a prime number?
   A prime number is one, which is divisible by 1 and the number itself.

   Now, here the basic idea is that if a number is prime then its miultiples cannot be prime.
   so, what we do is, intially we create an empty list.
       # we populate the list with numbers from 2 to n. (1 is not a prime)

    next, we run a loop till square root of n  because if we cannot a factor n till square root of n then it is a prime number.

    now, we remove all the the multiples of each number prom the list

    At last we are left with a list of prime numbers only.

Its that simple.Just basic maths.

      
'''
import math
n = int(input("Enter the range: "))
arr = []

for i in range(2, n+1):
    arr.append(i)

i = 2
while(i <= int(math.sqrt(n))):        
    if i in arr:
        for j in range(i*2, n+1, i):
            if j in arr:
                arr.remove(j)        # we remove the multiple of that number if it is present in the list.
    i = i+1


print(arr)
