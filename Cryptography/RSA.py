# -*- coding: utf-8 -*-
"""
Created on Mon Oct  5 23:40:47 2020

@author: Abhinav
"""


def gcd(x, y):
    
    a = int(0)
    # choose the smaller number
    if x > y:
        a = y       # a = smaller number
    else:
        a = x       # a = smaller number
    for i in range(1, a+1):
        if((x % i == 0) and (y % i == 0)):
            gcd = i 
    return gcd

       
def e_value(p,q):
    n = p*q
    phi = (p-1)*(q-1)
    e = int(2)            # 1<e<phi(n)
    
    print("PHI: {}".format(phi))
    
    while (True):
        a = gcd(e,phi)
        if a==1:
            d_value(n,phi,e)
            print("e: {}".format(e))
            break
        else:
            e+=1


def prime_number(n):
    flag = 0
    if n==2 or n==1:
        flag = 1
    for i in range(2,(n//2)):
        if n%i == 0:
            flag = 1
    if flag==0:
        return True
    else:
        return False

def input_numbers():
    p = int(input("Enter a prime number: "))
    q = int(input("Enter a prime number: "))
   
    if (prime_number(p) and prime_number(q)):
        e_value(p,q)
    
    else:
        print("Please enter prime numbers.")
        input_numbers()
       
        

def decrypt(c,private_key):
    v = pow(c,private_key[1])%private_key[0]      # v = decrypted text      
    print("Decrypted Text: {}".format(v))
        
       
def encrypt(public_key,private_key):
    m = int(input("Enter message to be encrypted: ")) # m = message
    c = pow(m,public_key[1])%public_key[0]
    print("Cipher Text: {}".format(c))
    decrypt(c,private_key)
        
def keys(n,e,d):
    public_key = (n,e)
    private_key = (n,d)
    encrypt(public_key,private_key)
                
def d_value(n,phi,e):
    if (phi+1)%e == 0:
        d = int((phi+1)/e)                       
        print("d: {}".format(d))
    keys(n,e,d)
    

    
input_numbers()

    

    
            
            
            
            
            
            
            
            