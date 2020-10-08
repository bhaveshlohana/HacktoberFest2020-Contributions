def getPrimes(a):  
    # SieveOfEratosthenes to get all prime numbers upto a
    if a<2:
        return [False]*(a+1)
    primes = [True for i in range(a+1)] 
    p = 2
    while p * p <= a: 
        if primes[p]: 
            for j in range(p * p, a+1, p): 
                primes[j] = False
        p += 1
    primes[0] = False
    primes[1] = False
    return primes
