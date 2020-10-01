def mergesort(array):
    if len(array) == 1:
        return array
    mid = len(array)//2
    left = array[:mid]
    right = array[mid:]
    return mergesortarray(mergesort(left), mergesort(right))


def mergesortarray(leftarray, rightarray):
    sorted = [None]*(len(leftarray)+len(rightarray))

    k = i = j = 0
    while(i < len(leftarray) and j < len(rightarray)):
        if leftarray[i] < rightarray[j]:
            sorted[k] = leftarray[i]
            i = i+1
        else:
            sorted[k] = rightarray[j]
            j = j+1
        k = k+1

    while (i < len(leftarray)):
        sorted[k] = leftarray[i]
        i += 1
        k = k+1

    while(j < len(rightarray)):
        sorted[k] = rightarray[j]
        j = j+1
        k = k+1

    return sorted


if __name__ == "__main__":

    array = list(map(int, input().split()))
    print(mergesort(array))
