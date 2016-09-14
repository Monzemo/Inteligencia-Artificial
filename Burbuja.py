from time import clock

lista = [3,1,8,2,5]

tiempo_inicial = clock()
for i in range(1,len(lista)):
	for j in range(len(lista) - i):
		if lista[j] > lista[j + 1]:
			temp = lista[j]
			lista[j] = lista[j + 1]
			lista[j + 1] = temp
tiempo_final = clock()
			
print (lista)
print (tiempo_final - tiempo_inicial)
