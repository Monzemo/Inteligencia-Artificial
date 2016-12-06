#include <iostream>

enum { _ = -1 };

struct Sudoku
{
  int data[9][9];
} matriz = 
{
  {
    { _, 8, _, 5, 7, 6, 2, _, _ },
    { _, _, _, 4, _, 2, _, _, _ },
    { _, _, _, _, 3, 9, 5, 4, 8 },
    { 6, 3, _, 9, _, _, 8, 5, 2 },
    { _, 9, _, 2, _, _, 3, 7, _ },
    { 8, _, _, _, 5, _, 6, 9, 4 },
    { 2, 5, 7, 6, _, 3, 4, 8, 9 },
    { 3, _, 8, 7, _, _, _, 2, 5 },
    { _, 4, _, _, _, _, _, _, 6 },
  }
};

bool checa(const Sudoku &matriz)
{
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
      for (int k = j + 1; k < 9; k++)
      {
        if (matriz.data[i][j] != _ && matriz.data[i][j] == matriz.data[i][k])
          return false;
        if (matriz.data[j][i] != _ && matriz.data[j][i] == matriz.data[k][i])
          return false;
        if (matriz.data[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] != _ &&
            matriz.data[j % 3 + (i % 3) * 3][j / 3 + (i / 3) * 3] ==
            matriz.data[k % 3 + (i % 3) * 3][k / 3 + (i / 3) * 3])
          return false;
      }
  return true;
}

bool encuentraSolucion(Sudoku &matriz)
{
  int x = -1;
  int y = -1;
  int min = 10;
  for (int i = 0; i < 9; i++)
    for (int j = 0; j < 9; j++)
    {
      if (matriz.data[i][j] == _)
      {
        int c = 0;
        for (int k = 1; k <= 9; k++)
        {
          matriz.data[i][j] = k;
          if (checa(matriz))
            ++c;
          matriz.data[i][j] = _;
        }
        if (min > c)
        {
          min = c;
          x = i;
          y = j;
        }
      }
    }
  if (x == -1)
    return true;
  for (int k = 1; k <= 9; k++)
  {
    matriz.data[x][y] = k;
    if (checa(matriz))
      if (encuentraSolucion(matriz))
        return true;
  }
  matriz.data[x][y] = _;
  return false;
}

int main()
{
  if (encuentraSolucion(matriz))
  {
    for (int i = 0; i < 9; i++)
    {
      for (int j = 0; j < 9; j++)
        std::cout << matriz.data[i][j] << " ";
      std::cout << std::endl;
    }
  }
  else
    std::cout << "No tiene solucion\n";
}
