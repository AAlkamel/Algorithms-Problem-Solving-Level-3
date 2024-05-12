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
int isNumberInMatrix(int arr[3][3], int number, int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (arr[i][y] == number)
      {
        return true;
      }
    }
  }
  return false;
}
void printIntersectIn2Matrixes(int arr1[3][3], int arr2[3][3], int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (isNumberInMatrix(arr2, arr1[i][y], 3, 3))
      {
        cout << setw(3) << arr1[i][y] << "  ";
      }
    }
  }
}

int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr1[3][3], arr2[3][3];
  fillMatrixWithRandoNumbers(arr1, 3, 3);
  fillMatrixWithRandoNumbers(arr2, 3, 3);
  cout << "the flowing is a 3X3 random matrix 1\n";
  printMatrix(arr1, 3, 3);
  cout << "the flowing is a 3X3 random matrix 2\n";
  printMatrix(arr2, 3, 3);

  cout << "\nthe flowing is intersected\n";
  printIntersectIn2Matrixes(arr1, arr2, 3, 3);

  system("pause>0");
}