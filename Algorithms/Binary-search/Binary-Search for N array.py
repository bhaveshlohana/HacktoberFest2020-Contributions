# Input 2 Arrays
# a = array of elements
# x = array of elements to find from a

def binary_search(a, x):
    r = []
    for i in x:
        left, right = 0, len(a)
        if i<a[0] or i>a[len(a)-1]:
            r.append(-1)
            continue
        while left <= right :
            mid = (left + (left + right)//2) + 1
            if i < a[mid]:
                right = mid
                continue
            elif i > a[mid]:
                left = mid + 1
                continue
            else:
                r.append(i)
    print(r)            
    
binary_search([1,5,8,12,13],[8,1,23,1,11])
