def binary_search(arr, key): 
    low = 0
    high = len(arr) - 1
    mid = 0
  
    while low <= high: 
        mid = (high + low)

        if arr[mid] < key: 
            low = mid + 1
  
        # If key is greater than the middle element, ignore left half 
        elif arr[mid] > key: 
            high = mid - 1
  
        # If key is smaller than the middle element, ignore right half
        else: 
            return mid 
  
    # when the element is not present 
    return -1
  
  
arr = [ 5, 7, 9, 10, 13 ] 

key = 10
result = binary_search(arr, key) #stores the index of the key, -1 if not found
print(result)

key = 11
result = binary_search(arr, key) #stores the index of the key, -1 if not found
print(result)