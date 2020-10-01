'''
Pure python 3 implementation of merge sort.
Algo-- Divide into smaller and smaller chunks until all the chunks are of size 1 .
Then start merging by comparison to form the complete result
'''
import random

def merge(input_array,left, right):
    i,j,k=(0,0,0)
    while(i<len(left) and j<len(right)):
            if left[i] <= right[j]:
                input_array[k] = left[i]
                i += 1
            else:
                input_array[k] = right[j]
                j += 1
            k += 1
    if i<len(left):
        input_array[k:] = left[i:]
    else:
        input_array[k:] = right[j:]


def merge_sort_recursive(input_array):
    # Base case for recursion:
    n = len(input_array)
    if n < 2:
        return
    mid = int(n/2)
    left = input_array[:mid]
    right = input_array[mid:]
    merge_sort_recursive(left)
    merge_sort_recursive(right)
    merge(input_array, left, right)

if __name__ == '__main__':
    print("With duplicates")
    for _ in range(5):
        input_array = [random.randrange(1, 20) for _ in range(10)]
        print("Before", input_array)
        merge_sort_recursive(input_array)
        print("After", input_array)
        print("\n")


    print("\n\nWithout duplicates")
    for _ in range(5):
        input_array = random.sample(range(10), 10)
        print("Before", input_array)
        merge_sort_recursive(input_array)
        print("After", input_array)
        print("\n")