def quick_sort(num_list):
   quick_sort_partition(num_list,0,len(num_list)-1)
   return num_list 

   
def quick_sort_partition(num_list,first,last):
   if first<last:
       split_point = partition(num_list,first,last)
       # Left
       quick_sort_partition(num_list,first,split_point-1)
       # Right
       quick_sort_partition(num_list,split_point+1,last)


def partition(num_list,first,last):
   pivot = num_list[first]
   left_mart = first+1
   right_mark = last
   done = False
   while not done:
	   # Find position of pivot
       while left_mart <= right_mark and num_list[left_mart] <= pivot:
           left_mart = left_mart + 1
       while num_list[right_mark] >= pivot and right_mark >= left_mart:
           right_mark = right_mark -1
       if right_mark < left_mart:
           done = True
       else:
           temp = num_list[left_mart]
           num_list[left_mart] = num_list[right_mark]
           num_list[right_mark] = temp
   
   # Pivot position exchange
   temp = num_list[first]
   num_list[first] = num_list[right_mark]
   num_list[right_mark] = temp
   return right_mark


print quick_sort([54,26,93,17,77,31,44,55,20])