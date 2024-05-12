#include <iostream>
#include <iomanip>
using namespace std;
int RandomNumber(int From, int To)
{
  int randNum = rand() % (To - From + 1) + From;
  return randNum;
}
void fillMatrixWithRandoNumbers(int arr[3][3], int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      arr[i][y] = RandomNumber(1, 10);
    }
  }
}
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
int sumMatrix(int arr[3][3], int Row, int col)
{
  int result = 0;
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      result += arr[i][y];
    }
  }
  return result;
}
bool areEqualMatrices(int arr1[3][3], int arr2[3][3], int Row, int col)
{
  return sumMatrix(arr1, Row, col) == sumMatrix(arr2, Row, col);
}
int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr1[3][3], arr2[3][3];
  fillMatrixWithRandoNumbers(arr1, 3, 3);
  fillMatrixWithRandoNumbers(arr2, 3, 3);
  cout << "matrix 1\n";
  printMatrix(arr1, 3, 3);
  cout << "\nmatrix 2\n";
  printMatrix(arr2, 3, 3);
  areEqualMatrices(arr1, arr2, 3, 3) ? cout << "\nthe matrices are equal" << endl
                                     : cout << "\nthe matrices are Not equal" << endl;
  system("pause>0");
}
