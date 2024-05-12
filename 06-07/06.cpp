#include <iostream>
#include <iomanip>
using namespace std;
void printMatrix(int arr[3][3], int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      cout << setw(3) << arr[i][y] << "  ";
    }
    cout << endl;
  }
}
void transposeMatrix(int arr[3][3], int arrTranspose[3][3], int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      arrTranspose[i][y] = arr[y][i];
    }
    cout << endl;
  }
}
void fillMatrixWithOrderedNumbers(int arr[3][3], int Row, int col)
{
  int counter = 1;
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      arr[i][y] = counter++;
    }
  }
}
int main()
{
  int arr[3][3],
      arrTranspose[3][3];
  fillMatrixWithOrderedNumbers(arr, 3, 3);
  cout << "the flowing is a 3X3 matrix\n";
  printMatrix(arr, 3, 3);
  transposeMatrix(arr, arrTranspose, 3, 3);
  cout << "the flowing is a 3X3 transpose matrix\n";
  printMatrix(arrTranspose, 3, 3);
  system("pause>0");
}
