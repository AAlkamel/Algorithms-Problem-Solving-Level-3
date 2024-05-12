#include <iostream>
using namespace std;

void printNumberOfFibonacciSeries(int number)
{
  int prev2 = 0, prev1 = 1, num = 1;
  for (int i = 0; i < number; i++)
  {
    cout << num << "   ";
    num = prev1 + prev2;
    prev2 = prev1;
    prev1 = num;
  }
}
int main()
{
  printNumberOfFibonacciSeries(15);
}