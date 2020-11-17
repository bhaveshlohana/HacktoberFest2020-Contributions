def maxSubArray(A):
    presum = 0
    maxi = -1
    for i in range(len(A)):
        presum += A[i]
        if presum > maxi:
            maxi = presum
        if presum <= 0:
            presum = 0
    if maxi == -1:
        return max(A)
    return maxi


A = [-2, 1, -3, 4, -1, 2, 1, -5, 4]
print(maxSubArray(A))
