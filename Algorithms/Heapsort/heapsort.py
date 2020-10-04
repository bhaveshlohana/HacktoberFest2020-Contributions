# Python program for heap sort
def heapify(arr, n, i):
    largest = i 
    l = 2 * i + 1
    r = 2 * i + 2

    if l < n and arr[i] < arr[l]:
        largest = l

    if r < n and arr[largest] < arr[r]:
        largest = r

    if largest != i:
        arr[i],arr[largest] = arr[largest],arr[i] # swap

        heapify(arr, n, largest)

#Function to sort a list
def heapSortAlgorithm(li):
    n = len(li)

    # Create a maxheap.
    for i in range(n // 2 - 1, -1, -1):
        heapify(li, n, i)

    #get the elements one by one and swap
    for i in range(n-1, 0, -1):
        li[i], li[0] = li[0], li[i]
        heapify(li, i, 0)

#main code
li = [ 12, 41, 2, 76, 19, 11, 98, 34]
heapSortAlgorithm(li)
print ("Array after HeapSort is: ")
for i in range(len(li)):
    print ("%d" %li[i])
