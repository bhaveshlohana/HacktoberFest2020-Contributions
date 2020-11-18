import numpy as np

def divide(matrix2D): 

    r, c = matrix2D.shape 
    r2, c2 = r//2, c//2
    return matrix2D[:r2, :c2], matrix2D[:r2, c2:], matrix2D[r2:, :c2], matrix2D[r2:, c2:] 
  
def strassen(x, y): #Code to multiply any 2^n Dimensional matrix

    if len(x) == 1: 
        return x * y #Base case
  

    a, b, c, d = divide(x) 
    e, f, g, h = divide(y) 
  
    p1 = strassen(a, f - h)   
    p2 = strassen(a + b, h)         
    p3 = strassen(c + d, e)         
    p4 = strassen(d, g - e)         
    p5 = strassen(a + d, e + h)         
    p6 = strassen(b - d, g + h)   
    p7 = strassen(a - c, e + f)   
   
    c11 = p5 + p4 - p2 + p6   
    c12 = p1 + p2            
    c21 = p3 + p4             
    c22 = p1 + p5 - p3 - p7   
   
    c = np.vstack((np.hstack((c11, c12)), np.hstack((c21, c22))))  
  
    return c 

#sample
A = np.random.rand(4,4)
B = np.random.rand(4,4)

print("A =",A)
print("B =", B)
print("A*B =",strassen(A,B))
