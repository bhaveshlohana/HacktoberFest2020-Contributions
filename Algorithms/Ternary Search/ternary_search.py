# Ternary search function
def ternarySearch(l, u, search, array): 
    while u >= l:
        print(u)
        mid1 = l + (u-l) // 3
        mid2 = u - (u-l) // 3
  
        # Check if element being searched is any one of the middle elements.
        if search == array[mid1]: 
            return mid1 
        if search == array[mid2]: 
            return mid2 
  
        if search < array[mid1]: 
            u = mid1 - 1
        elif search > array[mid2]: 
            l = mid2 + 1
        else: 
            l = mid1 + 1
            u = mid2 - 1
  
    # Element searched for has not been found.
    return -1
  
if __name__ == "__main__":
    print("Enter the elements of the array as space separated integers", end = '\n')
    array = [ int(x) for x in input().split()]
    print("Enter element to be searched", end = '\n')
    search = int(input())
    print("The element ", search, "is present at index", ternarySearch(0, len(array) - 1, search, array), end = '\n') 