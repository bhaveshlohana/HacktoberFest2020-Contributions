def binarySearch(arr, x): 
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
  
        mid = (high + low) // 2
        if arr[mid] < x: 
            low = mid + 1
  
        elif arr[mid] > x: 
            high = mid - 1
  
        else: 
            return mid 

    return -1

n = int(input("Enter the length of the array: "))
arr = []

for i in range(n):
    num = int(input())
    arr.append(num)
x = int(input("Enter the number to be searched: "))

idx = binarySearch(arr, x)
if idx==-1:
    print("The element is not present")
else:
    print("The element is present at index {}".format(idx))
