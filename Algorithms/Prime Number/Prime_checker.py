n = int(input())
if n > 1: 
    for i in range(2, n): 
        if (n % i) == 0: 
            print(n, "not_a_prime") 
            break
    else: 
        print(n, "is_a_prime") 
else: 
   print(n, "not_a_prime") 
