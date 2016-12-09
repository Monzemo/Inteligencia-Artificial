
#include <stdio.h>
#define SINASIGNAR 0 // Para las celdas vacias en la matriz
#define N 9 // Tamaño de la matriz

// Esta función encuentra una entrada en la matriz que todavía no está asignada 
bool UbicacionSinAsignar(int matriz[N][N], int &fila, int &col);
 
// Comprueba para asignar el número a la fila dada
bool isSafe(int matriz[N][N], int fila, int col, int num);
 
/* Toma una cuadricula parcialmente llena e intenta asignar valores a
   todas las ubicaciones no asignadas, de tal manera que cumplan con los requisitos
   para la solución Sudoku (no duplicación entre filas, columnas y cuadros) */
bool ResuelveSudoku(int matriz[N][N])
{
    int fila, col;
 
    // Si no hay ninguna ubicación no asignada, ha terminado
    if (!UbicacionSinAsignar(matriz, fila, col))
       return true; 
 
    // checa los numeros del 1 al 9
    for (int num = 1; num <= 9; num++)
    {
        // Si parece prometedor
        if (isSafe(matriz, fila, col, num))
        {
            // Hace una asignación tentativa
            matriz[fila][col] = num;
 
            // Regresa si la asignación fue exitosa
            if (ResuelveSudoku(matriz))
                return true;
 
            // Si falló, lo elimina e intenta de nuevo
            matriz[fila][col] = SINASIGNAR;
        }
    }
    return false; 
}
 
/* Busca en la matriz para encontrar una entrada que todavía no está asignada, si
   la encuentra, la fila de parámetros de referencia establecerá la ubicación
   que no está asignada, por lo tanto regresa un true, si no hay entradas no asignadas
   permanece, regresa un false */
bool UbicacionSinAsignar(int matriz[N][N], int &fila, int &col)
{
    for (fila = 0; fila < N; fila++)
        for (col = 0; col < N; col++)
            if (matriz[fila][col] == SINASIGNAR)
                return true;
    return false;
}
 
/* Devuelve un booleano que indica si una entrada asignada en la fila especificada coincide con el número dado. */
bool enFila(int matriz[N][N], int fila, int num)
{
    for (int col = 0; col < N; col++)
        if (matriz[fila][col] == num)
            return true;
    return false;
}
 
/* Devuelve un booleano que indica si una entrada asignada en la columna especificada coincide con el número dado */
bool enColumna(int matriz[N][N], int col, int num)
{
    for (int fila = 0; fila < N; fila++)
        if (matriz[fila][col] == num)
            return true;
    return false;
}
 
/* Devuelve un booleano que indica si una entrada asignada dentro del cuadro 3x3 especificado coincide con el número dado */
bool enCuadro(int matriz[N][N], int iniciaFila, int iniciaCol, int num)
{
    for (int fila = 0; fila < 3; fila++)
        for (int col = 0; col < 3; col++)
            if (matriz[fila+iniciaFila][col+iniciaCol] == num)
                return true;
    return false;
}
 
/* Devuelve un booleano que indica si será legal asignar el número a la fila dada, col ubicación. */
bool isSafe(int matriz[N][N], int fila, int col, int num)
{
    /* Comprueba si 'num' ya no está en la fila y columna actual 3x3 */
    return !enFila(matriz, fila, num) &&
           !enColumna(matriz, col, num) &&
           !enCuadro(matriz, fila - fila%3 , col - col%3, num);
}
 
/* Función que imprime la matriz */
void printMatriz(int matriz[N][N])
{
    for (int fila = 0; fila < N; fila++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", matriz[fila][col]);
        printf("\n");
    }
}
 
int main()
{
    // 0 significa lugar o celda no asignado
    int matriz[N][N] = 
	{
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
		};
    if (ResuelveSudoku(matriz) == true)
          printMatriz(matriz);
    else
         printf("No tiene solucion");
 
    return 0;
}
