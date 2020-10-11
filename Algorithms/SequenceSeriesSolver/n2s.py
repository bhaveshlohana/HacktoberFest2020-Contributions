def pow_sum(n,p):
    ls= []
    for i in range(1,n+1):
        ls.append(i**p)
    return ls, sum(ls)
if __name__== "__main__":
    n = int(input('Enter the no. of terms till which you want to calculate the series: '))
    p = int(input('Enter the power argument: '))
    m, n= pow_sum(n,p)
    print(f"The series is given by:\n{m}...\nThe sum of this {p}-power series is:\n{n}")
