def is_prime(a):
    flag = True
    for i in range(2,int(a/2)+1):
        if(a%i == 0):
            flag = False
            break
    return flag

number = int(input('Enter the limit to which prime sexy prime numbers to be found :  '))
if(number<2):
    print('No prime numbers less than 2')
else:
    c = 0
    for i in range(2,number-5): # As sexy prime numbers differ with 6 so instead of running loops till n, running loops till n-6
        if(is_prime(i) and is_prime(i+6)):
            print(i,i+6)