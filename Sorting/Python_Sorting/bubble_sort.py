'''
Python implementation of bubble sort.
Algo is simple terms is that in each cycle compare the ith elem with it's adjacent elem and swap if it's bigger.
This way in each cycle biggest elem "bubbles up" to the end of the list
Can be used to check if an array/list is already sorted or not. Since there will be no swaps in first iteration itself.
'''

import random
import os
random.seed(os.urandom(1024))

def is_sorted(array):
    return all(array[i] <= array[i+1] for i in range(len(array)-1))

def bubble_sort(input_array):
    swap=0
    for j in range(len(input_array)-1):
        for i in range(len(input_array)-1):
            if input_array[i]>input_array[i+1]:
                swap += 1
                input_array[i], input_array[i+1] = input_array[i+1], input_array[i]
        if swap == 0:
            #since no swaps are done, means already sorted. Hence, break free from the chains. :D
            print("Array is already sorted")
            break
    return input_array


if __name__ == '__main__':
    print("testing with sample containing no duplicates")
    input_unique = random.sample(range(10),10)
    print(input_unique)
    print(bubble_sort(input_unique))
    print("Input unique is sorted", is_sorted(input_unique))
    bubble_sort(input_unique)

    print("***************************************** \n")
    print("testing with sample containing duplicates")
    input_duplicate = [random.randrange(1, 10) for _ in range(0, 10)]
    print(input_duplicate)
    print(bubble_sort(input_duplicate))
    print("Input duplicate is sorted", is_sorted(input_duplicate))
    print("***************************************** \n")

    print("Random testing with duplicate elements")
    print(bubble_sort([1,1,1,1,2,3,3,3,3,3,5]))