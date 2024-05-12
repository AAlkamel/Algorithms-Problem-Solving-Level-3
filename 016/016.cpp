#include <iostream>
#include <iomanip>
using namespace std;
void printMatrix(int arr[3][3], int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      printf(" %0*d  ", 2, arr[i][y]);
      // cout << setw(3) << arr[i][y] << "  ";
    }
    cout << endl;
  }
}
int countNumberInMatrix(int arr[3][3], int number, int Row, int col)
{
  int count = 0;
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (arr[i][y] == number)
      {
        count++;
      }
    }
  }
  return count;
}
bool isSparceMatrix(int arr[3][3], int Row, int col)
{
  int matrixSize = Row * col;
  int matrixHaf = matrixSize % 2 == 0 ? matrixSize / 2 : (matrixSize / 2) + 1;
  return countNumberInMatrix(arr, 0, Row, col) >= matrixHaf;
}

int main()
{
  // int arr[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};
  // int arr[3][3] = {{1, 5, 0}, {4, 1, 0}, {0, 0, 1}};
  int arr[3][3] = {{4, 0, 0}, {4, 1, 0}, {0, 0, 1}};

  cout << "matrix 1\n";
  printMatrix(arr, 3, 3);
  isSparceMatrix(arr, 3, 3) ? cout << "\nthe matrices are Sparce" << endl
                            : cout << "\nthe matrices are Not Sparce" << endl;
  system("pause>0");
}
