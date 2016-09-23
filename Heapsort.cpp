
#include <iostream>
using namespace std;

void Heap(int arr[], int n, int i)// Un índice de matriz []. n es el tamaño

{
    int mgrande = i;  //inicializamos
    int l = 2*i + 1;
    int r = 2*i + 2;
    // si es el mas grande
    if (l < n && arr[l] > arr[mgrande])
        mgrande = l;
    // Si hijo derecho es más grande que la más grande hasta el momento
    if (r < n && arr[r] > arr[mgrande])
       mgrande = r;
    // si es mas grande y no es la raiz
    if (mgrande != i)
    {
        swap(arr[i], arr[mgrande]);
        Heap(arr, n, mgrande);
    }
}

void heapSort(int arr[], int n)
{    // reorganizar matriz
    for (int i = n / 2 - 1; i >= 0; i--)
        Heap(arr, n, i);

    for (int i=n-1; i>=0; i--)
    {  // mueve la raiz actual y pone fin
        swap(arr[0], arr[i]);

        Heap(arr, i, 0);
    }
}

void printArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "matriz es:\t \n";
    printArray(arr,n);

    heapSort(arr, n);

    cout << "matriz ordenada es:\t \n";
    printArray(arr, n);
}
