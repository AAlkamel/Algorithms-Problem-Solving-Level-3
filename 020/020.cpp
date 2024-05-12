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
bool isPalindromMatrix(int arr[3][3], int Row, int col)
{
  for (short i = 0; i < Row; i++)
  {
    for (short y = 0; y < col / 2; y++)
    {
      if (arr[i][y] != arr[i][col - y - 1])
      {
        return false;
      }
    }
  }
  return true;
}
int main()
{
  // Seeds the random number generator in C++, called only once
  srand((unsigned)time(NULL));
  int arr[3][3] = {{1, 9, 1}, {8, 7, 8}, {2, 5, 2}};
  cout << "the flowing is a 3X3 random matrix 1\n";
  printMatrix(arr, 3, 3);

  isPalindromMatrix(arr, 3, 3) ? cout << "the Matrix is palindrom\n" : cout << "the Matrix is not palindrom\n";

  system("pause>0");
}