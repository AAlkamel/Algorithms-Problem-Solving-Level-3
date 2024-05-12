#include <iostream>
using namespace std;

void printNumberOfFibonacciSeriesRecursion(short number, short prev1, short prev2)
{
  int fibNum = 0;
  if (number > 0)
  {
    fibNum = prev1 + prev2;
    cout << fibNum << "  ";
    prev2 = prev1;
    prev1 = fibNum;
    printNumberOfFibonacciSeriesRecursion(number - 1, prev1, prev2);
  }
}
int main()
{
  printNumberOfFibonacciSeriesRecursion(10, 0, 1);
}