from random import randint

def quick_sort(a):
    if len(a) <= 1:
        return a
    
    small, equal, large = [],[],[]
    pivot = a[randint(0, len(a))]

    for x in a:
        if x < pivot:
            small.append(x)
        elif x == pivot:
            equal.append(x)
        else:
            large.append(x)
    
    return quick_sort(small) + equal + quick_sort(large)