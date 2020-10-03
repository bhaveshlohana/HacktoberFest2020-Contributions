#!/usr/bin/env python
# coding: utf-8

# In[2]:


#Linear Search program in Python

array=list(map(int,input().split())) #get an array of elements  which are space-separated
search_element=int(input())          #input the elemnt to be searched in the array
x=0
for i in range(len(array)):
    if search_element == array[i]:
        x=i
if x == 0:
    print ('The given element is not in the array') #If the element is not present in the array
else:
    print ('The given element is at location: %d in the array' % x) 


# In[ ]:




