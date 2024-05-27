#include <iostream>
#include <string>
#include <vector>
using namespace std;
string readString()
{
  string theString;
  cout << "enter your string\n";
  getline(cin, theString);
  return theString;
}
string TrimLeft(string s)
{
  // My Answer
  // while (s[0] == ' ')
  // {
  //   s.erase(0, 1);
  // }
  // return s;
  /// Abuhadhod Answer
  for (int i = 0; i < s.length(); i++)
  {
    if (s[i] != ' ')
    {
      return s.substr(i, s.length() - 1);
    }
  }
  return "";
}
string TrimRight(string s)
{
  // My Answer
  //  while (s[s.length() - 1] == ' ')
  //  {
  //    s.pop_back();
  //  }
  //  return s;
  /// Abuhadhod Answer
  for (int i = s.length() - 1; i >= 0; i--)
  {
    if (s[i] != ' ')
    {
      return s.substr(0, i + 1);
    }
  }
  return "";
}
string Trim(string s)
{
  return TrimLeft(TrimRight(s));
}
int main()
{
  string s1 = readString();
  // cout << "\nyour string with trim left is : " << TrimLeft(s1) << endl;
  // cout << "\nyour string without trim left is : " << s1 << endl;
  // cout << "\nyour string with trim right is : " << TrimRight(s1) << " endl" << endl;
  // cout << "\nyour string without trim right is : " << s1 << "endl";
  cout << "\nyour string with trim is : " << Trim(s1) << " endl" << endl;
  cout << "\nyour string without trim is : " << s1 << "endl";
}