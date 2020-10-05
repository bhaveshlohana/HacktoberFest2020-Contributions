import math
def EliminaGaussiana(A,b):
	for k in range(0,n-1):
		pivo = A[k][k]
		l_pivo = k
		for i in range(k+1,n-1):
			if (abs(A[i][k]) > abs(pivo)):
				pivo = A[i][k]
				l_pivo = i
		if pivo == 0:
			break

		if l_pivo != k:
			for j in range(0,n):
				troca = A[k][j]
				A[k][j] = A[l_pivo][j]
				A[l_pivo][j] = troca
			troca = b[k]
			b[k] = b[l_pivo]
			b[l_pivo] = troca

		for i in range(k+1,n):
				m = A[i][k]/A[k][k]
				A[i][k]=0
				for j in range(k+1,n):
					A[i][j]=A[i][j]-m*A[k][j]
				b[i] = b[i] - m*b[k]

	x = [0]*n
	x[n-1] = b[n-1]/A[n-1][n-1]

	for i in range(n-2,-1,-1):
		soma = 0
		for j in range(i,n):
			soma = soma + A[i][j]*x[j]
		x[i] = (b[i] - soma)/A[i][i] 

	return x

def calVetor(A,r,b,x):

	for i in range(0,n):
		for j in range(0,n):
			r[i] += A[i][j]*x[j]

	for i in range(0,n):
		r[i] = b[i] - r[i]

	return r

def norma(r):
	norma = 0
	for i in range(0,n):
		norma = r[i]**2 + norma
	norma = math.sqrt(norma)
	return norma

print("nome do arquivo")
name = input()
arquivo = open(name, "r")
v = (arquivo.readline())
v = v[:-1]
n = int(v) #tamanho da matriz
l = [0]*(n+1) #matriz auxiliar
A = [0]*n #matriz A 
for x in range(0,n): #gerando as matrizes zeradas
	A[x] = [0]*n

b = [0]*n #vetor b 
r = [0]*n #vetor residual
i = 0

#lendo arquivo

for linha in arquivo: 
	l[i] = linha.split()
	i=i+1


#gerando as matrizes com os valores

for x in range(0,n): 
	for i in range(0,n+1):
		if i == n:
			b[x] = float(l[x][i])
		else:
			A[x][i] = float(l[x][i])

#iterações de refinamento

for i in range(0,2):
	x = EliminaGaussiana(A,b)
	r = calVetor(A,r,b,x)
	b = r
	norm = norma(r)
	print("Norma:")
	print(norm)
	print("Vetor residual:")
	print(r)
