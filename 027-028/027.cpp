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
string upperAllString(string s1)
{

  for (short i = 0; i < s1.length(); i++)
  {
    s1[i] = toupper(s1[i]);
  }
  return s1;
}
string lowerAllString(string s1)
{
  for (short i = 0; i < s1.length(); i++)
  {
    s1[i] = tolower(s1[i]);
  }
  return s1;
}
char convirtCharState(char c)
{
  return isupper(c) ? tolower(c) : toupper(c);
}
string convirtAllCharStateInString(string s1)
{
  for (short i = 0; i < s1.length(); i++)
  {
    s1[i] = convirtCharState(s1[i]);
  }
  return s1;
}
int main()
{
  string s1 = readString();
  // s1 = upperAllString(s1);
  // cout << s1 << endl;
  // s1 = lowerAllString(s1);
  // cout << s1 << endl;
  s1 = convirtAllCharStateInString(s1);
  cout << s1 << endl;
}