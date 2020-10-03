from sys import stdin, stdout

# one way to find angrams can be to sort two strings and then check if both of them are equal
s1 = stdin.readline()
s2 = stdin.readline()

if len(s1) != len(s2):
    exit()

if set(s1) & set(s2) == set(s1):
    print("Contains same Character")
else:
    print("Cannot be Anagrams")
    exit()

dict_x = {}
dict_y = {}

for i in range(len(s1)):
    if s1[i] in dict_x:
        dict_x[s1[i]] += 1
    else:
        dict_x[s1[i]] = 1

for i in range(len(s2)):
    if s2[i] in dict_y:
        dict_y[s2[i]] += 1
    else:
        dict_y[s2[i]] = 1

for i in dict_x:
    if dict_x[i] != dict_y[i]:
        print("Not Anagram")
        exit()

print("Anagram")
