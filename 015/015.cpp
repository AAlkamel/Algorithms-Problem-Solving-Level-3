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
int countNumberInMatrix(int arr[3][3], int number, int Row, int col)
{
  int count = 0;
  for (int i = 0; i < Row; i++)
  {
    for (int y = 0; y < col; y++)
    {
      if (arr[i][y] == number)
      {
        count++;
      }
    }
  }
  return count;
}

int main()
{
  int arr[3][3] = {{3, 0, 0}, {0, 3, 0}, {0, 0, 3}};
  int number = 0;
  // int arr[3][3] = {{1, 5, 0}, {4, 1, 0}, {0, 0, 1}};
  // int arr[3][3] = {{4, 5, 0}, {4, 1, 0}, {0, 0, 1}};

  cout << "matrix 1\n";
  printMatrix(arr, 3, 3);
  cout << "\n enter number to count in Matrix" << endl;
  cin >> number;
  cout << "\n count " << number << " in Matrix is: " << countNumberInMatrix(arr, number, 3, 3) << endl;
  system("pause>0");
}
