def selection_sort(arr):

    for i in range(len(arr)):
        # index of min elem
        min = i

        for j in range(i+1,len(arr)):
            # arr[j] is smaller than the min elem
            if arr[j] < arr[min]:
                min = j

        # swap        
        arr[i],arr[min] = arr[min],arr[i]
        # print(arr)
    
    return arr
