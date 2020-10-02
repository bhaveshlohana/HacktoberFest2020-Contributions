###################################################
### Author : Divyesh Mehta
### Algorithm : Fibonacci Search
### Language : Python
####################################################

def fibonacci_search(arr, e, n):
    n2 = 0
    n1 = 1
    nT = n2 + n1

    while nT < n:
        n2 = n1
        n1 = nT
        nT = n2 + n1

    flag = -1

    while nT > 1:
        i = min(flag + n2, n - 1)

        if arr[i] < e:
            nT = n1
            n1 = n2
            n2 = nT - n1
            flag = i

        elif arr[i] > e:
            nT = n2
            n1 = n1 - n2
            n2 = nT - n1
        else:
            print(f"Element found at index {i}")
            return

    if n1 and arr[flag + 1] == e:
        return flag + 1

    print("Given Input Not Found in Array !!")


arr = [10, 20, 30, 40, 50]

num = int(input("Enter The Value to Search:"))

fibonacci_search(arr, num, len(arr))
