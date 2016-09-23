import random
from time import clock

tiempo_inicial = clock()
R = random.Random(50)

def qsort(L):
	quicksort(L,0,len(L))

def quicksort(L,start,stop):
	if stop - start < 2: return
	key = L[R.randrange(start,stop)]

	e = u = start
	g = stop
	while u < g:
		if L[u] < key:
			swap(L,u,e)
			e = e + 1
			u = u + 1
		elif L[u] == key:
			u = u + 1
		else:
			g = g - 1
			swap(L,u,g)
	quicksort(L,start,e)
	quicksort(L,g,stop)

def swap(A,i,j):
	temp = A[i]
	A[i] = A[j]
	A[j] = temp
	
	
print("quicksort:\t\n")
L = [3,1,4,1,5,9,2,6,5,3,5,8,9,7,9]
print("tu arreglo desordenado  era:\t\n" ,L)
qsort(L)
tiempo_final = clock()
print ('tu arreglo ordenado es:\n' ,L)
print (tiempo_final - tiempo_inicial)