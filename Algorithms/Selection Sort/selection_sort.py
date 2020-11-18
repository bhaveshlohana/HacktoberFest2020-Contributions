l=list(map(int,input().split()))
for i in range(len(l)):
 minx=i
 for j in range(i+1,len(l)):
  if l[j]<l[minx]:
   l[minx],l[j]=l[j],l[minx]
    

print(l)
