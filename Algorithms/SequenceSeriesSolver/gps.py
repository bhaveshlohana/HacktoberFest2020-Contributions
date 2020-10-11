def gpc(a, r, n):
    ls = [a]
    for i in range(n-1):
        a *= r
        ls.append(a)
    return ls,sum(ls)
if __name__=='__main__':
    a = int(input('Enter the first term: '))
    r = int(input('Enter the common ratio: '))
    n = int(input('Enter the no. of terms you want to calulate the sum to: '))
    m, n = gpc(a, r, n)
    print(f'The series is given by:\n{m}...\nThe sum of the GP is:\n{n}')
