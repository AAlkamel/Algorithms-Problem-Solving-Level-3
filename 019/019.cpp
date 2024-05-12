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
      printf(" %0*d  ", 2, arr[i][y]);
      // cout << setw(3) << arr[i][y] << "  ";
    }
    cout << endl;
  }
}
short MinMatrix(int arr[3][3], int Row, int col)
{
  short min = arr[0][0];
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (min > arr[i][y])
      {
        min = arr[i][y];
      }
    }
  }
  return min;
}
short MaxMatrix(int arr[3][3], int Row, int col)
{
  short max = arr[0][0];
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (max < arr[i][y])
      {
        max = arr[i][y];
      }
    }
  }
  return max;
}

int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr1[3][3];
  fillMatrixWithRandoNumbers(arr1, 3, 3);
  cout << "the flowing is a 3X3 random matrix 1\n";
  printMatrix(arr1, 3, 3);
  cout << "\nthe max number in matrix is: " << MaxMatrix(arr1, 3, 3) << endl;
  cout << "\nthe min number in matrix is: " << MinMatrix(arr1, 3, 3) << endl;

  system("pause>0");
}