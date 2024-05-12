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
void printFirstLetterOfString(string s1)
{
  bool isFirstLetter = true;
  for (short i = 0; i < s1.length(); i++)
  {
    if (isFirstLetter && s1[i] != ' ')
    {
      cout << s1[i] << endl;
    }
    isFirstLetter = s1[i] == ' ';
  }
}
int main()
{
  string s1 = readString();
  printFirstLetterOfString(s1);
}