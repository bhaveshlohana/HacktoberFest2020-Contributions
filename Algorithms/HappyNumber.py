def numHappy(n):
    if n == 1:
        return 1
    else:
        suma = 0
    
        while(n>0):
            suma += (n%10)**2
            n//=10
    
        print(suma)

        return numHappy(suma)

print(numHappy(293))