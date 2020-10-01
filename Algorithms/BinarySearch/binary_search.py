n = int(input("Enter the number of elements in array: "))
a = []
print('Enter {} elements: '.format(n))
for i in range(n):
    x = int(input())
    a.append(x)

key = int(input("Enter the key you would do search: "))

start = 0
end = n-1
mid = 0

found = False
while start<=end:
    mid = (start+end)//2
    if key == a[mid]:
        found = True
        break
    elif key<a[mid]:
        end = mid-1
    else:
        start = mid+1

if found:
    print('Key {} found at index {}'.format(key, mid))
else:
    print('Key {} not found in the array'.format(key))