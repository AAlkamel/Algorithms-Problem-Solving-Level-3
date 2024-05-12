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
bool isScalarMatrix(int arr[3][3], int Row, int col)
{
  int FirstDiagonal = arr[0][0];
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (i == y && arr[i][y] != FirstDiagonal)
      {
        return false;
      }
      else if (i != y && arr[i][y] != 0)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  int arr[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};
  // int arr[3][3] = {{1, 5, 0}, {4, 1, 0}, {0, 0, 1}};
  // int arr[3][3] = {{4, 5, 0}, {4, 1, 0}, {0, 0, 1}};

  cout << "matrix 1\n";
  printMatrix(arr, 3, 3);
  isScalarMatrix(arr, 3, 3) ? cout << "\nthe matrices are Scalar" << endl
                            : cout << "\nthe matrices are Not Scalar" << endl;
  system("pause>0");
}
