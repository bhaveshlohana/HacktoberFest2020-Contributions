#Exercise 1

""" objetivo: definir tipo vetor
pode ser definido pelas suas coordenas (x,y) """

#Operaçoes basicas:

#Construtor:
""" vetor: real x real -> vetor 
vetor(x, y) tem como valor o vetor cuja extremidade  é o ponto (x, y)"""

#Seletores:
""" abcissa: vetor -> real
abcissa(v) é a abcissa do vetor v
-------
ordenada: vetor -> real
ordenada(v) é a ordenada do vetor v """

#Reconhecedores:
""" e_vetor: universal -> logico
e_vetor(arg) tem valor verdadeiro se arg é um vetor
-------
e_vetor_nulo: vetor -> logico
e_vetor_nulo tem valor verdadeiro apenas se arg é o vetor (0,0) """

#Teste
""" vetores_iguais: vetor x vetor -> logico
vetores_iguais(v1, v2) tem valor verdadeiro se os vetores v1 e v2 forem iguais """

""" def vetor(x, y):
    if numero(x) and numero(y):
        return (x, y)
    else:
        raise ValueError("vetor: argumento errado")

def numero(x):
    if isinstance(x, (int, float)):
        return True
    else:
        return False

def transf_saida(vet):
    return str(vet[0]) + " ex " + " + " + str(vet[1]) + " ey"

def abcissa(vet):
    return vet[0]

def ordenada(vet):
    return vet[1]

def e_vetor_arg(vet):
    if isinstance(vet, tuple):
        if len(vet) == 2:
            if numero(vet[0]) and numero(vet[1]):
                return True
            else:
                return False
        else: 
            return False
    else:
        return False

def e_vetor_nulo(vet):
    if vet[0] == 0 and vet[1] == 0:
        return True
    else:
        return False



#Exercise 2

def soma_vetores(v1, v2):
    return(v1[0] + v2[0], v1[1] + v2[1])
    
def mult_vetores(v1, v2):
    return(v1[0] * v2[0], v1[1] * v2[1])

def e_colinear(vet):
    if vet[1] == 0:
        return True
    else:
        return False
 """


#Exercise 3

#objetivo: criar um tipo racional

#Construtores:
""" cria_rac: Z x N -> racional
cria_rac(n, d) tem como valor o numero racional cujo numerador é n e o denominador é d  """

#Seletores
""" num: racional -> Z
num(r) tem como valor o numerador do racional n

den: racional -> N
den(r) tem como valor o denominador do racional n """

#Reconhecedores

""" e_racional: universal -> lógico
e_racional(arg) tem o valor verdadeiro se o numero arg é um racional e falso em caso contrário

e_racional_zero: racional -> lógico
e_racional_zero(r) tem o valor verdadeiro se r é o racional nulo e falso em caso contrário

e_racional_inteiro: racional -> lógico 
e_racional_zero(r) tem o valor verdadeiro se o racional r é um numero inteiro (ou seja, um racional da forma n/1), e falso em caso contrario """

#Testes
""" rac_iguais: racional x racional -> lógico
rac_iguais(r1, r2) tem o valor verdadeiro se os racionais r1 e r2 sao iguais e falso em caso contrario """

#Representação: Lista [n, d] em que "n" é o numerador e "d" é o denominador --> R[n/d] = [n, d]

""" def cria_rac(n, d):
    if isinstance(n, int) and isinstance(d, int):
        if d != 0:
            return [n,d]
        else:
            raise ValueError("cria_rac: denominador = 0")
    else:
        raise ValueError("cria_rac: argumento não inteiro")

def num(r):
    return r[0]

def den(r):
    return r[1]

def e_racional(val):
    if isinstance(val, list):
        if len(val) == 2:
            if isinstance(val[0], int) and isinstance(val[1], int):
                if val[1] != 0:    
                    return True
                else:
                    return False
            else:
                return False
        else:
            return False
    else:
        return False

def e_racional_zero(r):
    return r[0] == 0


def e_racional_inteiro(r):
    return r[1] == 1

def rac_iguais(r1, r2):
    return r1[0] * r2[1] == r2[0] * r1[1]

#Transformador de saída:
def escreve_rac(lst):
    print(str(lst[0]) + "/" + str(lst[1]))

#Outros:

def produto_rac(r1, r2):
    return [r1[0] * r2[0], r1[1] * r2[1]]

def soma_rac(r1, r2):
    return [(r1[0] * r2[1] + r1[1] * r2[0]), r1[1] * r2[1]]
 """
#.....--------------------------------.........................-----------------------------------.........................-----------------
#Exercise 5

#Objetivo: Criar o tipo data
#Data: dia(inteiro entre 1 e 31), mes(inteiro entre 1 e 12), ano(inteiro positivo, nulo ou negativo)
#Nota em anos bissextos

#Operaçoes básicas:

#Construtores
""" cria_data: N x N x N -> data 
cria_data(d, m, a) tem como valor a data com o dia d, o mes m e o ano a 
 """
#Seletores
""" dia: data -> N
dia(dt) tem como valor o dia da data dt

mes: data -> N
mes(dt) tem como valor o dia da data dt

ano: data -> N
ano(dt) tem como valor o ano da data dt
 """
#Reconhecedores
""" e_data: Universal -> Logico
e_data(dt) tem o valor lógico verdadeiro se dt for uma data e falso em caso contrário """


#Testes

""" mesma_data: data x data -> logico
mesma_data(dt1, dt2) tem o valor lógico verdadeiro se as datas dt1 e dt2 forem a mesma data e falso em caso contrário
 """
#Representaçao do tipo data:
""" Dicionario com as chaves "d", "m" e "a" associadas ao dia, mes e ano, ou seja, R[d/m/a] = {"d": d, "m": m, "a": a} """

""" def bissexto(a):
    if (a % 4) == 0:
        if (a % 100) and (a % 400) != 0:
            return True
        else:
            return False
    else:
        return False


def dias_de(m,a):
    if m in [1, 3, 5, 7, 8, 10, 12]:
        return 31
    elif m in [4, 6, 9, 11]:
        return 30
    elif m == 2 and bissexto(a):
        return 29
    else:
        return 28

def cria_data(d, m, a):
    if isinstance(d, int) and isinstance(m, int) and isinstance(a, int):
        if (d > 0) and (m > 0):
            if m <= 12:
                if d > dias_de(m, a):
                    print("cria_data: meses a mais")
                else:
                    return {"d": d, "m": m, "a": a}
            else:
                print("cria_data: meses a mais")    
        else:
            print("cria_data: o dia e mês devem ser maiores que zero")
    else:
        print("cria_data: os elementos devem ser inteiros")

def dia(dt):
    return dt["d"]

def mes(dt):
    return dt["m"]

def ano(dt):
    return dt["a"]

def mesma_data(d1, d2):
    return d1["a"] == d2["a"] and d1["m"] == d2["m"] and d1["a"] == d2["a"]

def e_data(arg):
    if isinstance(arg, dict):
        if len(arg) == 3:
            if "d" in arg and "m" in arg and "a" in arg:
                if isinstance(arg["d"], int) and isinstance(arg["m"], int) and isinstance(arg["a"], int):
                    if 0<arg["d"]<=dias_de(arg["m"], arg["a"]) and 1<=arg["m"]<=12:
                        return True
                    else:
                        return False
                else:
                    return False
            else:
                return False
        else:
            return False
    else:
        return False

    
def escreve_data(dt):


    def representa_ano(a, data):
        if 100 <= a < 1000:
            data = data + "0" + str(a) 
        elif 10<= a <100:
            data = data + "00" + str(a) 
        elif a < 10:
            data = data + "000" + str(a) 
        else:
            data = data + str(a) 
        return data

    def representa_ano_2(a, data):
        if a > 0:
            data = representa_ano(abs(a), data) 
        elif a < 0:
            data = representa_ano(abs(a), data) + " AC" 

        else:
            data = data + "0000"
        return data

    if dt["d"] < 10:
        data = "0" + str(dt["d"]) + "/"
    else:
        data = str(dt["d"]) + "/"
    if dt["m"] < 10:
        data = data + "0" + str(dt["m"]) + "/"
    else:
        data = data + str(dt["m"]) + "/"
    data = representa_ano_2(dt["a"], data)
    print(data)


escreve_data(cria_data(2,1,2010)) """


#Exercise 8

#Objetivo: Criar o tipo "conjunto"

#Representação: O conjunto vazio é representado pela lista vazia. Um conjunto com os elementos e1,..., en (n>=1) é representado pela lista com elementos R[e1]...R[en]
""" 
from random import random 

def conjunto():
    return []

def insere(e, c):
    if e in c:
        return c
    else:
        return c + [e]

def elem_conj(c):
    if c == []:
        raise ValueError("elem_conjunto:conjunto vazio")
    else:
        return c[int(random()*len(c))]
        

def retira_conj(e, c):
    if e in c:
        return retira(e, c)
    else:
        return c

def retira(e, c):
    if c == []:
        return c 
    elif e == c[0]:
        return c[1:] 
    else:
        return [c[0]] + retira(e,c[1:])

def retira2(e, c):
    if c == []:
        return c
    else:
        for i in range(len(c)):
            if c[i] == e:
                return c[:i] + c[i+1:]
    
def cardinal(c):
    return len(c)

def e_conjunto(arg):
    return isinstance(arg, list)def conjunto():
    return [

def e_conj_vazio(c):
    return c == []    

def pertence(e, c):
    return e in c
        
def subconjunto(c1, c2):
    for el in c1:
        if el not in c2:
            return False
        else:
            continue
    return True

def subconjunto2(c1, c2):
    if e_conj_vazio(c1):
        return True
    else:
        e = elem_conj(1) 
        if pertence(e, c2):
            return (subconjunto(retira(e, c1), retira(e, c2)))
        else:
            return False

def uniao(c1, c2):
    if e_conj_vazio(c1):
        return c2
    else:
        res = c2
        while not e_conj_vazio(c1):
            elem = elem_conj(c1)
            c1 = retira_conj(elem, c1)
            res = insere(elem, res)
        return res

def intersecao(c1, c2):
    res = conjunto()
    if e_conj_vazio(c1) or e_conj_vazio(c2):
        return res
    else:
        while not e_conj_vazio(c1):
            elem = elem_conj(c1)
            if elem in c2:
                res += [elem]
            c1 = retira(elem, c1)
        return res

print(intersecao([1, 2, 44, 5], [43+1, 5, 9]))

def diferenca(c1, c2):
    res = conjunto()
    if e_conj_vazio(c1):
        return res
    elif e_conj_vazio(c2):
        return c1
    else:
        while not e_conj_vazio(c1):
            elem = elem_conj(c1)
            c1 = retira_conj(elem, c1)
            if not pertence(elem, c2):
                res = insere(elem, res)
        return res

 """




