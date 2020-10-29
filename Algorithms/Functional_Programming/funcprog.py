#--------------------------------------------------------------Funçoes revisitadas e prog. funcional-----------------------------------------------------------------------------

#Exercise 1

""" def soma_digitos_pares(num):
    '''
    Takes a number as an argument and returns the sum of its odd elements
    '''
    if num // 10 != 0:
        if num % 2 == 0:
            return num % 10 + soma_digitos_pares(num // 10)
        else:
            return soma_digitos_pares(num // 10)
    else:
        return num

print(soma_digitos_pares(234567)) """


#Exercise 2

""" def inverte_digitos(n):
    '''
    Takes a number as an argument and returns it backwards
    '''
    def inverte_aux(n1, res):
        if n1 == 0:
            return res
        else:
            return inverte_aux(n1 // 10, res * 10 + n1 % 10)
    return inverte_aux(n, 0) 


# print(inverte_digitos(1234567))
a = eval(input("Insert a number --->"))
print(inverte_digitos(a)) """

#Exercise 3

""" def soma_quadrados_lista(lst):
    '''
    Takes a list as an argument and returns the sum of the list's elements squared
    '''
    if lst == []:
        return 0
    else:
        return lst[0] ** 2 + soma_quadrados_lista(lst[1:])   

print(soma_quadrados_lista([1, 2, 3, 4, 5]))
 """

#Exercise 4

""" def quick_sort(lst):

    def parte(lst, e):
        menores = []
        maiores = [] 
        for el in lst:
            if el < e:
                menores = menores + [el]
            elif el > e:
                maiores = maiores + [el]
        return [menores, maiores]

    if lst == []:
        return lst
    else:
        menores, maiores = parte(lst,lst[0])
    return quick_sort(menores) + [lst[0]] + quick_sort(maiores)

a = [6, 5, 8, 15, 99]    
print(quick_sort(a))
 """

#Exercise 5

""" def transforma(tr, lst):
    res = []
    if lst == []:
        return lst
    else:        
        return res + [tr(lst[0])] + transforma(tr, lst[1:])

a = [1, 2, 3, 4]

print(transforma(lambda x: x ** 2, a))
  """


 

""" def filtra(fn, lst):
    res = []
    if lst == []:
        return lst
    else:
        if fn(lst[0]):
            return res + [lst[0]] + filtra(fn,lst[1:])
        else:
            return filtra(fn,lst[1:])

print(filtra(lambda x: x % 2 == 0, [1, 2, 3, 4, 5, 6]))
 """

#TODO: SOLVE !!
""" 
def acumula(fn, lst):
    res = lst[0]
    if lst == []:
        return lst
    else:
        return fn(res, acumula(fn, lst)) 

 

print(acumula(lambda x, y: x * y, [1, 2, 3, 4, 5])) 
"""

#Exercise 6

""" def(lst):
    return(acumula(lambda x, y: x + y, transforma(lambda x: x ** 2, lst)))
     """

#Exercise 7

""" a)Calculates the sum of the numbers from  4 up to 500
b)Calculates the sum of the square of the numbers from 1 up to 5
c)1 + (1+2) + (1+2+3)+ (1+2+3+4) + (1+2+3+4+5)
 """

#Exercise 8
#TODO: NO IDEA

""" def piatorio(a, b, fn, prox):
    res = 1
    while a <= b:
        res = res * fn(a)
        a = prox(a)
    return res

a = piatorio(
    1,


)
print(a) """

#Exercise 9
""" def faz_potencia(n):
    def f_p(x):
        return x ** n
    return f_p

print(faz_potencia(3)(2)) """

#Exercise 10

""" def h(f,g,x):
    return f(x) ** 2 + 4 * (g(x) ** 3)

print(h(lambda x: x * 2, lambda x: x + 3, 2)) """

#Exercise 11
 #TODO: ??
""" def derivada(f, n):
    def fn_derivada(x):
        return ((f(x + dx) - f(x)) / dx

    if  n == 0:
        return 0
    else: 
        return derivada(fn_derivada, n - 1)

print(lambda x : x + 1, 5) """

#Exercise 12--- SQUARE ROOT(newton's method)

""" dx = 0.0001

def met_newton(f, palpite):
    tf_N = trans_newton(f)
    while not boa_aprox(f(palpite)):
        palpite = tf_N(palpite)
    return palpite

def trans_newton(f):
    def t_n(x):
        return x - f(x) / derivada(f)(x)
    return t_n

def boa_aprox(x):
    return abs(x) < dx

def derivada(f):
    def fn_derivada(x):
        return (f(x + dx) - f(x)) / dx

    return fn_derivada

def quadrado(x):
    return x ** 2

def raiz_quadrada(n):
    return met_newton(lambda y: quadrado(y) - n, 1)

print(raiz_quadrada(9))
          """

#Exercise 14
""" def quadrado(x):
    return x ** 2

def rasto(nome, fn):

    def rastreada(n):

        print("Avaliaçao de " + nome + " com argumento " + str(n))
        res = fn(n)
        print("Resultado " + str(res))
        return res

    return rastreada

print(rasto("quadrado", quadrado)(3))
 """

#----------------------------------------------------------------------Recursion(cap.7)-----------------------------------------------------------
""" def soma_tot(lst):
    def soma_elementos(lst, som_ac):
        if lst == []:
            return som_ac
        else:
            return soma_elementos(lst[1:], som_ac + lst[0])
    return soma_elementos(lst, 0)        

print(soma_tot([1, 1, 6, 1, 1]))
 """
#--------------Exercises chapter 7------------------
#Exercise 1



""" def m_p(x, y):

    def m_p_a(z):
        if z == 0:
            return 1
        else:
            return m_p_a(z - 1) * x

    return m_p_a(y) """

""" def m_p(x, y):
 m_p_a(z, res):
        if  z == 0:
            return res
        else:
            return m_p_a(z - 1, res * x)
    return m_p_a(y, 1)

print(m_p(2, 3)) """


"""
a)

m_p(2,4)
    m_p_a(4)
        m_p_a(3) 
            m_p_a(2) 
                m_p_a(1) 
                    m_p_a(0) 
                    return 1
                return 2
            return 4
        return 8
    return 16
16

b) This function calculates x^y

c)The one above a and b
"""

#Exercise 2
""" def misterio(n):
    def misterio_aux(d, s):
        if d == 0:
            return "pos"
        elif s == 0:
            return "neg"
        else:
            return misterio_aux(d-1, s +1)
    if n == 0:
        return "nulo"
    else: 
        return misterio_aux(n, n)

print(misterio(0))
 """

"""
a)We calculate if the number if positive or negatice
b)The recursion used is linear recursion
"""






#Exercise 3

""" def quadrado(n):
    
    def vezes(m, n):
        if m == 1:
            return n
        else: 
            return n + vezes(m - 1, n)
    
    def calc_quad(n):
        if n == 1:
            return 1
        else:
            return vezes(2,n) - 1 + calc_quad(n - 1)
    if isinstance(n, int):
        return calc_quad(n)
    else:
        raise ValueError ('quadrado: arg should be int')

print(quadrado(a))

 """

#Same exercise with tail recursion (below)

""" def quadrado(n):

    def vezes(m, n, res):
        if m == 1:
            return n + res
        else:
            return vezes(m - 1, n, res + n)


    def calc_quad(n, res):
        if n == 1:
            return res + n
        else:
            return calc_quad(n - 1, res + vezes(2, n, 0) - 1)

    if isinstance(n, int):
        return calc_quad(n, 0)
    else:
        raise ValueError ('quadrado: arg should be int')


print(quadrado(9))
  """
#Exercise 4

""" def numero_digitos(num):
    cont = 0
    while num != 0:
        num = num // 10
        cont += 1
    return cont

print(numero_digitos(8)) """

"""  
def numero_digitos(num):

    def conta(num, cont):
        if num // 10 == 0:
            return cont 
        else:
            return conta(num // 10, cont + 1)

    if isinstance(num, int):
        return conta(num, 1)
    else:
        raise ValueError("numero_digitos: not int type")
 
 
#Exercise 5 

def e_capicua(num):
    def e_capicua_aux(n, n_d):
        if n_d < 2:
            return True
        elif (n // pow(10, n_d - 1)) == n % 10:
            return e_capicua_aux((n % (pow(10, n_d - 1))) // 10, n_d - 2)
        else:
            return False
    return e_capicua_aux(num, numero_digitos(num))

print(e_capicua(12324)) """
 

#Exercise 6



#TODO: SOLVE THIS ONE!!


""" def espelho(num):

    def last(num, adic, res, cont):
        return res + last(num // 10, pow(10, cont) + num % 10, res + adic, cont + 1)


    if num % 10 != 0:
            return last(num, 0, 0, 0)
    else:
        raise ValueError("espelho: divisible by 10")

print(espelho(4567))  """








#Exercise 7

""" def num_divisores(num):
    cont = 1
    res = 0
    while cont <= num:
        if num % cont == 0:
            res += 1
        cont +=1
    return res """

""" def numero_divisores(num):

    def num_divisores_aux(num, res, cond, cont):
        if cont <= num:
            if cond(num, cont):
                return num_divisores_aux(num, res + 1, cond, cont + 1)
            else: 
                return num_divisores_aux(num, res, cond, cont + 1) 
        else:
            return res
    if num == 0:
        return 0
    else:
        return num_divisores_aux(num, 0, lambda x, y: x % y == 0, 1)

print(numero_divisores(20))
print(numero_divisores(13)) """








#Exercise 8

def A(m, n):
    if m == 0:
        return n + 1
    elif m > 0 and n == 0:
        return A(m - 1, 1)
    elif m > 0 and n > 0:
        return A(m -1, A(m, n -1))







#Exercise 9

""" def produto(x, y):
    if x == 0:
        return 0
    elif x % 2 == 0:
        return produto(x // 2, y + y)
    else:
        return y + produto(x - 1, y)


def produto(x, y):
    def produto_aux(x, y, ac):
    if x == 0:
        return ac
    elif x % 2 == 0:
        return produto(x // 2, y + y, ac)
    else:
        return produto(x - 1, y, ac + y)

    return produto_aux(x, y, 0)

 """




#Exercise 10
""" 
def g(n):
    if n == 0:
        return 0
    elif n > 0:
        return n - g(g(n-1)) 

print(g(4))
"""


#Exercise 11

""" def C(m, n):
    if n == 0:
        return 1
    elif m == n:
        return 1
    elif m < n:
        return 0
    elif m > n or m > 0 or n > 0:
        return C(m - 1, n) + C(m -1, n -1)


print(C(2,2))

 """







#Hanoi Tower (non-related)

""" def hanoi():
    cont = 0
    def mova(n, origem, destino, aux):
        global cont
        
        def mova_disco(de, para):
 #           print ("Jogada", cont, "\n\n")
            print("Tower", de, "-->", "Tower", para, "\n\n")

        if n == 1:
            cont += 1
            print ("Jogada", cont, "\n\n")
            mova_disco(origem, destino)

        else:
            print ("Jogada", cont, "\n\n")
            mova(n - 1, origem, aux, destino)
            cont += 1
            mova_disco(origem, destino)
            mova(n - 1, aux, destino, origem)

    n = int(input("Quantos discos deseja considerar? \n -->"))
    print("Solução do puzzle: \n")
    mova(n, "1", "3", "2")

hanoi() """
