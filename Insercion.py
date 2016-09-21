from time import clock

lista = [3,1,8,2,5]

tiempo_inicial = clock()
for i in range(1,len(lista)):
	temp = lista[i]
	j = i -1
	while j >= 0:
		if temp < lista[j]:
			lista[j+1] = lista[j]
			lista[j] = temp
			j = j-1
		else:
			break
tiempo_final = clock()
			
print (lista)
print (tiempo_final - tiempo_inicial)