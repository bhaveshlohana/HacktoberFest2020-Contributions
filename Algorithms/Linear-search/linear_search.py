n = int(input("Enter the number of elements in array: "))
a = []
print(f"Enter {n} elements")
for i in range(n):
    x = int(input())
    a.append(x)

key = int(input("Enter the key you would do search: "))

found = False
index = -1
for i in range(n):
    if a[i] == key:
        found = True
        index = i
        break
if found:
    print('Key {} found at index {}'.format(key, index))
else:
    print('Key {} not found in the array'.format(key))
