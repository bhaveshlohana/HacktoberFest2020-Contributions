p=raw_input("Enter the plain text to encrypt")
key=raw_input("Enter the encryption key")
p=p.lower()
key=key.lower()
mat=[['0' for i in range(26)]for j in range(26)]
alpha="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz"
for i in range(26):
    for j in range(i,26+i):
        mat[i][j-i]=alpha[j]
print(mat)
repeat=len(p)/len(key)
for i in range(repeat):
    key=key+key
res=""
for i in range(len(p)):
    pind=0
    keyind=0
    if ord(p[i])<97:
        pind=ord(p[i])-65
    else:
        pind=ord(p[i])-97
    if ord(key[i])<97:
        keyind=ord(key[i])-65
    else:
        keyind=ord(key[i])-97
    res+=mat[pind][keyind]
    print(p[i],key[i])
print(res)

dec=""
for i in range(len(res)):
    pind=ord(res[i])
    kind=ord(key[i])
    dind=(pind-kind+26)%26
    dec+=chr(dind+97)
print(dec)
