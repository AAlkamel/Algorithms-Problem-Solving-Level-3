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
bool isIdentity(int arr[3][3], int Row, int col)
{
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (i == y && arr[i][y] != 1)
      {
        return false;
      }
      else if (i != y && arr[i][y] != 0)
      {
        return false;
      }
    }
  }
  return true;
}

int main()
{
  int arr[3][3] = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
  // int arr[3][3] = {{1, 5, 0}, {4, 1, 0}, {0, 0, 1}};
  // int arr[3][3] = {{4, 5, 0}, {4, 1, 0}, {0, 0, 1}};

  cout << "matrix 1\n";
  printMatrix(arr, 3, 3);
  isIdentity(arr, 3, 3) ? cout << "\nthe matrices are Identity" << endl
                        : cout << "\nthe matrices are Not Identity" << endl;
  system("pause>0");
}
