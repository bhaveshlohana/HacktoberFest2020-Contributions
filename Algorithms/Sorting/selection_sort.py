def selection_sort(arr):

    for i in range(len(arr)):
        min = i # index of min elem

        for j in range(i+1,len(arr)):
            # arr[j] is smaller than the min elem
            if arr[j] < arr[min]:
                min = j
             
        arr[i],arr[min] = arr[min],arr[i] # swap   
        # print(arr)
    
    return arr
