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
string upperFirstLetterOfString(string s1)
{
  bool isFirstLetter = true;
  for (short i = 0; i < s1.length(); i++)
  {
    if (isFirstLetter && s1[i] != ' ')
    {
      s1[i] = toupper(s1[i]);
    }
    isFirstLetter = s1[i] == ' ';
  }
  return s1;
}
string lowerFirstLetterOfString(string s1)
{
  bool isFirstLetter = true;
  for (short i = 0; i < s1.length(); i++)
  {
    if (isFirstLetter && s1[i] != ' ')
    {
      s1[i] = tolower(s1[i]);
    }
    isFirstLetter = s1[i] == ' ';
  }
  return s1;
}
int main()
{
  string s1 = readString();
  s1 = upperFirstLetterOfString(s1);
  cout << s1 << endl;
  s1 = lowerFirstLetterOfString(s1);
  cout << s1 << endl;
}