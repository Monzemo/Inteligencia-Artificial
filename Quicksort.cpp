#include<stdio.h>

int partition(int *a, int p, int r) {
  int pivot = a[r]; // pivote
  int i = p-1, j, temp;
  for(j = p; j <= r-1; j++) {
    //Si el elemento actual es menor que o igual a pivotar
    if(a[j] <= pivot) {
      i++;
      temp = a[i];
      a[i] = a[j];
      a[j] = temp;
    }
  }
  temp = a[i+1];
  a[i+1] = a[r];
  a[r] = temp;
  return i+1;
}

void quick_sort(int *a, int p, int r) {
  if(p < r) {
    int q = partition(a,p,r);
    quick_sort(a, p, q-1);
    quick_sort(a, q+1, r);
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
  quick_sort(a, 0, n-1);
  printf("el arreglo ordenado es: \n");
  for(i=0; i<n; i++) {
    printf("%d \n", a[i]);
  }
  return 0;
}

