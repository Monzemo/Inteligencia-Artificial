#include <iostream>
#include <time.h>

using namespace std;

int main()
{
		int tam = 5;
		int lista[tam] = {3,1,8,2,5};
		int temp,i,j;

		for (i=tam-1; i>0; i--){
			for (j=0; j<i; j++){
				if (lista[j] > lista[j+1]){
					temp = lista[j];
					lista[j] = lista[j+1];
					lista[j+1] = temp;
				}
			}
		}
		for (i=0; i<tam; i++){
			cout <<lista[i] << " ";
		}

		system("pause");
		return 0;
	}
