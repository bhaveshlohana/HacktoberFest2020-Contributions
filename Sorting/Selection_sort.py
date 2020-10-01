def selection_sort(arr):

  for position in range(len(arr)):

    curr_min = position

    for i in range(position+1, len(arr)):

      if arr[i] < arr[min_item]:
        curr_min = i

    arr[position], arr[curr_min] = arr[curr_min], arr[position]

  return arr

my_array = [1, 4, 2, 6, 10, -1, -6]
print(selection_sort(my_array))
