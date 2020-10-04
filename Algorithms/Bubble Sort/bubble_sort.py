# Bubble Sort

def bubble_sort(num_list):
	for items in range(len(num_list)-1,0,-1):
		for item in range(items):
			if num_list[item] > num_list[item+1]:
				# Swap
				temp = num_list[item]
				num_list[item] = num_list[item+1]
				num_list[item+1] = temp
	return num_list
	
	
print (bubble_sort([54,26,93,17,77,31,44,55,20]))
