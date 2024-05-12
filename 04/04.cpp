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
      arr[i][y] = RandomNumber(1, 100);
    }
  }
}
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
int sumCol(int arr[3][3], int colNumber, int Row)
{
  int sumCol = 0;
  for (int y = 0; y < Row; y++)
  {
    sumCol += arr[y][colNumber];
  }
  return sumCol;
}
void printEachMatrixColSum(int arr[3][3], int Row, int col)
{
  for (int i = 0; i < col; i++)
  {

    cout << "col " << i + 1 << " sum = " << sumCol(arr, i, Row) << endl;
  }
}

int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr[3][3];
  fillMatrixWithRandoNumbers(arr, 3, 3);
  cout << "the flowing is a 3X3 random matrix\n";
  printMatrix(arr, 3, 3);
  cout << "\nthe flowing are the sum of each col in matrix \n";
  printEachMatrixColSum(arr, 3, 3);

  system("pause>0");
}
