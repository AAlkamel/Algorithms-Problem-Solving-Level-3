#include <iostream>
#include <string>
using namespace std;
string RemovePunctuationsFromString(string S1)
{
  string result = "";
  for (char &i : S1)
  {
    if (!ispunct(i))
    {
      result += i;
    }
  }
  return result;
}
int main()
{
  string s = "How Are, you? . how Are 'you? How; Are you?.";
  cout << RemovePunctuationsFromString(s) << endl;
  return 0;
}
