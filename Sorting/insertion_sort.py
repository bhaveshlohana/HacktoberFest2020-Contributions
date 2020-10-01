
def insertion_sort(arr):

    for i in range(1,len(arr)):
        key = arr[i]
        j = i-1

        # loop is entered if elem is smaller than elems in arr[0...i-1]
        while j >= 0 and arr[j] > key:
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = key
        # print(arr)

    return arr
