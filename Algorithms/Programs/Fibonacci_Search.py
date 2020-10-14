def fibonacciSearch(arr, x):
    n = len(arr)
    m2 = 0
    m1 = 1
    m = m2 + m1

    while m < n:
        m2 = m1
        m1 = m
        m = m2 + m1

    offset = -1

    while m > 1:
        i = min(offset+m2, n-1)

        if arr[i] < x:
            m = m1
            m1 = m2
            m2 = m - m1
            offset = i

        elif arr[i] > x:
            m = m2
            m1 = m1 - m2
            m2 = m - m1
            # offset = i

        else:
            return i

    if (m1 and arr[offset+1] == x ):
        return offset+1

    return -1
    
arr= [-65, 1, 5, 9, 11, 54, 64, 85]
x = 85 

result = fibonacciSearch(arr, x)
if (result==-1):
    print("Element not found.")
else:
   print("Element found at index ",result)
