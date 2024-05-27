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
int countWordsInString(string s, string Delimiter)
{
  int position;
  string sWord;
  int countWords = 0;
  while ((position = s.find(Delimiter)) != std::string::npos)
  {
    sWord = s.substr(0, position);
    if (sWord != "")
    {
      ++countWords;
    }
    s.erase(0, position + Delimiter.length());
  }
  if (s != "")
  {
    ++countWords;
  }
  return countWords;
}
int main()
{
  string s1 = readString();
  cout << "\n The count Words in your string is : " << countWordsInString(s1, " ") << endl;
}