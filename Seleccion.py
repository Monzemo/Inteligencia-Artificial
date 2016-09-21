from time import clock

lista = [3,1,8,2,5]
n = len(lista)

tiempo_inicial = clock()
for i in range(0, n-1):
	min=i
	temp=lista[i]
	for j in range(i,n):
		if lista[j] < temp:
			min=j
			temp = lista[j]
			lista[min] = lista[i]
			lista[i] = temp
tiempo_final = clock()
			
print (lista)
print (tiempo_final - tiempo_inicial)