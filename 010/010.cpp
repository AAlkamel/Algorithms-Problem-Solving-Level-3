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
int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr1[3][3];
  fillMatrixWithRandoNumbers(arr1, 3, 3);
  cout << "the flowing is a 3X3 random matrix \n";
  printMatrix(arr1, 3, 3);
  cout << "\nthe matrix sum :" << sumMatrix(arr1, 3, 3) << endl;

  system("pause>0");
}
