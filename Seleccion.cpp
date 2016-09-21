#include <iostream>
#include <time.h>

using namespace std;

int main()
{
		int tam = 5;
		int lista[tam] = {7,3,5,9,1};
		int temp,i,j,min;

		for(i=0 ; i<tam-1 ; i++){
			min=i;
			for(j=i+1 ; j<tam ; j++){
			if (lista[min] > lista[j]) min=j;
			}
			temp=lista[min];
   			lista[min]=lista[i];
   			lista[i]=temp;
			}
			for (i=0; i<tam; i++){
			cout <<lista[i] << " ";
			}
			system("pause");
			return 0;
			}
