def palcheck(s):
     ns=""
     for i in s:
          ns=i+ns
     if s==ns:
          return True
     return False

def cod(s):
     l=len(s)
     for i in range(2,l):
          if palcheck(s[:i]):
               t1=s[:i]
               k=s[i:]
               break
     t=len(k)
     for j in range(2,t):  
          if palcheck(k[:j]):
               t2=k[:j]
               k2=k[j:]
     if palcheck(k2)==True:
          print(t1,t2,k2)
          return 1
     print("Impossible")
     return 0

us=input("Input String\n")
if len(us)>=1 and len(us)<=1000:
     cod(us)
else:
     print("Not Under Limitation")

