#include <iostream>
#include <string>
using namespace std;
string readString()
{
  string theString;
  cout << "enter your string\n";
  getline(cin, theString);
  return theString;
}
int countCapitalLetters(string s)
{
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (isupper(s[i]))
      count++;
  }
  return count;
}
int countSmallLetters(string s)
{
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (islower(s[i]))
      count++;
  }
  return count;
}
int main()
{
  string s1 = readString();
  cout << "\n The string length is: " << s1.length() << endl;
  cout << "\n count capital letters is: " << countCapitalLetters(s1) << endl;
  cout << "\n count small letters is: " << countSmallLetters(s1) << endl;
}