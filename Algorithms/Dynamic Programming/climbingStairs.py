def climbStairs(A):
    if A == 0 or A == 1:
        return 1
    if A == 2:
        return 2
    else:
        arr = [1, 2]
        for i in range(2, A):
            curr = arr[i - 2] + arr[i - 1]
            arr.append(curr)
    return arr[-1]


n = int(input("Enter number of stairs :"))
print(climbStairs(n))
