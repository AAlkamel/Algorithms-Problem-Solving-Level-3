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
void multiply2Matrixes(int arr1[3][3], int arr2[3][3], int arrResult[3][3], int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      arrResult[i][y] = arr1[i][y] * arr2[i][y];
    }
    cout << endl;
  }
}

int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr1[3][3], arr2[3][3], arrResult[3][3];
  fillMatrixWithRandoNumbers(arr1, 3, 3);
  fillMatrixWithRandoNumbers(arr2, 3, 3);
  cout << "the flowing is a 3X3 random matrix 1\n";
  printMatrix(arr1, 3, 3);
  cout << "the flowing is a 3X3 random matrix 2\n";
  printMatrix(arr2, 3, 3);

  multiply2Matrixes(arr1, arr2, arrResult, 3, 3);
  cout << "\nthe flowing are the Multiplay of matrix 1 in matrix 2 \n";
  printMatrix(arrResult, 3, 3);

  system("pause>0");
}
