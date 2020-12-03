#Coded by Timothy Joshua Chua
#A technique to find the prime numbers up to a given n
#Implementation of Sieve of Erathosthenes technique in python




if __name__ == "__main__":

  n = 103
  my_list = [1 for i in range(n+1)] #Instantiates a list of n+1 ones(meaning assume they are all prime initially)


  number = 2
  while(number ** 2 <= n):
    multiplier = 2
    while(number * multiplier <= n): #Find the multiples of the prime numbers and mark them as composite by giving them the value of 0
      my_list[number*multiplier] = 0
      multiplier += 1

    number += 1

  number = 2

  #This will print out the prime numbers(those with my_list[x] = 1 as the composite numbers were given a value of 0)
  for i in range(2, n+1):
    if(my_list[i] == 1):
      print(number)

    number += 1
