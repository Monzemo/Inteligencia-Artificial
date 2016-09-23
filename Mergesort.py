from time import clock

tiempo_inicial = clock()
def MergeSort(A):
    #print("Dividir: ",A)
    if len(A)>1:
        mitad = len(A)//2
        mitadizq = A[:mitad]
        mitadder = A[mitad:]
        MergeSort(mitadizq)
        MergeSort(mitadder)
        i=0
        j=0
        k=0
        while i < len(mitadizq) and j < len(mitadder):
            if mitadizq[i] < mitadder[j]:
                A[k]=mitadizq[i]
                i=i+1
            else:
                A[k]=mitadder[j]
                j=j+1
            k=k+1

        while i < len(mitadizq):
            A[k]=mitadizq[i]
            i=i+1
            k=k+1

        while j < len(mitadder):
            A[k]=mitadder[j]
            j=j+1
            k=k+1
  
print ("Ordenamiento MERGESORT")

A=[5,6,8,3]
print ("Numeros a Ordenar: ",A)
MergeSort(A)
tiempo_final = clock()

print ("Numeros Ordenados son: ",A)
print (tiempo_final - tiempo_inicial)