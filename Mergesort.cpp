#include<stdio.h>

void merge(int *a, int p, int q, int r) {

  int n1, n2, i, j = 0, k = 0, t;
  n1 = q - p + 1;
  // N1 será 0-0 + 1 = 1
  n2 = r - q;
  // // N2 será 0-0 + 1 = 1

  /* Estamos tomando dos subconjuntos L R R n1 n2 // tamaño y respectivamente para copiar elementos de un [0..0] y [1..1].*/
  int L[n1], R[n2];

  // Copiar elementos de un [0..0] a L [n1] Como se indicó anteriormente
  for(i = 0; i < n1; i++) {
    L[i] = a[p+i];
  }

 // Copiar elementos de un [1..1] a R [n2] como se ha dicho
  for(i = 0; i < n2; i++) {
    R[i] = a[q+1+i];
  }
// Comparar los elementos de la matriz de L y R y colocarlos // volver en orden creciente de nuevo a la matriz de una [0..1]
  for(i = p; i <= r; i++) {
    if(L[j] <= R[k]) {
      a[i] = L[j++];
    }
    else if(L[j] > R[k]) {
      a[i] = R[k++];
    }

    if(j == n1) {
      for(t = i+1; t <= r; t++) {
        a[t] = R[k++];
      }
      break;
    }

    if(k == n2) {
      for(t = i+1; t <= r; t++) {
        a[t] = L[j++];
      }
      break;
    }
  }
}

void merge_sort(int *a, int p, int r) {
  if(p < r) {
   // Obtener la mitad de la matriz
    int q = (p+r)/2;
    //recursively call merge sort for the two halves
    merge_sort(a, p, q);
    merge_sort(a, q+1, r);
    merge(a, p, q, r);
  }
  else {
   // Si el índice de inicio es igual al último índice, el regreso
    return;
  }
}

int main() {
  int n, i;
  printf("introduce el tamaño de tu arreglo \n");
  scanf("%d", &n);
  int a[n];
  printf("introduce los elementos del arreglo \n");
  for(i=0; i<n; i++) {
    scanf("%d", &a[i]);
  }
  merge_sort(a, 0, n-1);
  printf("el arreglo ordenado es: \n");
  for(i=0; i<n; i++) {
    printf("%d \n", a[i]);
  }
  return 0;
}

