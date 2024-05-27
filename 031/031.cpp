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
char readChar()
{
  char theChar;
  cout << "enter your Char\n";
  cin >> theChar;
  return theChar;
}
int countLetter(string s, char c)
{
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] == c)
      count++;
  }
  return count;
}
int countLetter(string s, char c, bool sensitive)
{
  if (sensitive)
  {
    return countLetter(s, c);
  }

  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (tolower(s[i]) == tolower(c))
      count++;
  }
  return count;
}
int main()
{
  string s1 = readString();
  char c = readChar();
  cout << "\n count  letters is: " << countLetter(s1, c) << endl;
  cout << "\n count  letters is: " << countLetter(s1, c, false) << endl;
  cout << "\n count  letters is: " << countLetter(s1, c, true) << endl;
}