# Recursive function to return gcd of a and b
def gcd(a,b):
    if (b == 0):
         return a
    return gcd(b, a%b)
