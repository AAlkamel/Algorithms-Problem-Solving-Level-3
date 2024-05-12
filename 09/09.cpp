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
void printMatrixRow(int arr[3][3], int RowNumber, int col)
{
  for (int y = 0; y < col; y++)
  {
    printf(" %0*d  ", 2, arr[RowNumber - 1][y]);
  }
}
void printMatrixCol(int arr[3][3], int ColNumber, int Row)
{
  for (int y = 0; y < Row; y++)
  {
    printf(" %0*d  ", 2, arr[y][ColNumber - 1]);
  }
}
int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr1[3][3];
  fillMatrixWithRandoNumbers(arr1, 3, 3);
  cout << "the flowing is a 3X3 random matrix \n";
  printMatrix(arr1, 3, 3);
  cout << "\nthe flowing is middle Row matrix \n";
  printMatrixRow(arr1, 2, 3);
  cout << "\nthe flowing is middle Col matrix \n";
  printMatrixCol(arr1, 2, 3);

  system("pause>0");
}
