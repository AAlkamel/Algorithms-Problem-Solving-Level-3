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
int sumRow(int arr[3][3], int RowNumber, int col)
{
  int sumRow = 0;
  for (int y = 0; y < col; y++)
  {
    sumRow += arr[RowNumber][y];
  }
  return sumRow;
}

void AddSumEachRowToArr(int arr[3][3], int Row, int col, int sumRowsArr[3])
{
  for (int i = 0; i < Row; i++)
  {
    sumRowsArr[i] = sumRow(arr, i, col);
  }
}
void printRowsArr(int row[3], int length)
{
  for (short i = 0; i < length; i++)
  {
    cout << "Row " << i + 1 << " sum = " << row[i] << endl;
  }
}

int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr[3][3], sumRowsArr[3];
  fillMatrixWithRandoNumbers(arr, 3, 3);
  cout << "the flowing is a 3X3 random matrix\n";
  printMatrix(arr, 3, 3);
  AddSumEachRowToArr(arr, 3, 3, sumRowsArr);
  cout << "\nthe flowing are the sum of each row in matrix \n";
  printRowsArr(sumRowsArr, 3);

  system("pause>0");
}
