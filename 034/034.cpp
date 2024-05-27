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
int findDelimiter(string s, string Delimiter)
{
  if (s.find(Delimiter) != std::string::npos)
  {
    return s.find(Delimiter);
  }
  return -1;
}
void printEachWordInString00(string s, string Delimiter)
{
  int position;
  string sWord;
  while ((position = findDelimiter(s, Delimiter)) >= 0)
  {
    sWord = s.substr(0, position);
    if (sWord != "")
    {
      cout << sWord << endl;
    }
    s.erase(0, position + Delimiter.length());
  }
  if (s != "")
  {
    cout << s << endl;
  }
}
void printEachWordInString(string s, string Delimiter)
{
  int position;
  string sWord;
  while ((position = s.find(Delimiter)) != std::string::npos)
  {
    sWord = s.substr(0, position);
    if (sWord != "")
    {
      cout << sWord << endl;
    }
    s.erase(0, position + Delimiter.length());
  }
  if (s != "")
  {
    cout << s << endl;
  }
}
int main()
{
  string s1 = readString();
  cout << "\n The Words in your string are : " << endl;
  printEachWordInString(s1, " ");
}