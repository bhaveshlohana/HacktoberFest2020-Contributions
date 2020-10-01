# Recursive function to return gcd of a and b
def gcd(a,b):
    if (b == 0):
         return a
    return gcd(b, a%b)
 
def lcm(a,b):
 	# lcm*hcf=a*b
 	return a*b/gcd(a,b)



a = int(input())
b = int(input())

hcf=gcd(a, b)

if(hcf):
    print('GCD of', a, 'and', b, 'is', hcf)

a = int(input())
b = int(input())

lcm=lcm(a, b)

if(lcm):
	print('LCM of', a, 'and', b, 'is', lcm)
