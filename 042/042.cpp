#include <string>
#include <iostream>
using namespace std;

string ReplaceWordInString(string s1, string wordToReplace, string replaceTo)
{
  int position = s1.find(wordToReplace);
  while ((position = s1.find(wordToReplace)) != std::string::npos)
  {
    s1.replace(position, wordToReplace.length(), replaceTo);
  }
  return s1;
}
int main()
{
  string s = "How Are you How Are you How Are you";
  cout << ReplaceWordInString(s, "How", "...") << endl;
  return 0;
}
