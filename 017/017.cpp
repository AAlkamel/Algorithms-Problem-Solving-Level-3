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

int main()
{
  // int arr[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};
  // int arr[3][3] = {{1, 5, 0}, {4, 1, 0}, {0, 0, 1}};
  int arr[3][3] = {{4, 0, 0}, {4, 1, 0}, {0, 0, 1}};
  int number = 0;
  cout << "matrix 1\n";
  printMatrix(arr, 3, 3);
  cout << "\nenter number to look at in matrix";
  cin >> number;
  isNumberInMatrix(arr, number, 3, 3) ? cout << "\nthe number is in matrix" << endl
                                      : cout << "\nthe number is Not in matrix" << endl;
  system("pause>0");
}
