#Find maximum sum of a contiguous subarray using Kadane's Algorithm in Python using  iteration

from sys import maxsize       #importing sys library for MAX_INT

def kadane(array, size):              
	result = -maxsize        
	max_here = 0
	for i in range(size):
		max_here+=array[i]
		if result<max_here:                      #check when to change the result
			result = max_here                      #change the result to the maximum sum yet
		if max_here<0:
			max_here = 0
	return result


array = list(map(int, input().split()))
size = len(array)
print(kadane(array, size))
