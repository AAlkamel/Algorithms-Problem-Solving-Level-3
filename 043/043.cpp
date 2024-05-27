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
vector<string> splitString(string s, string Delimiter)
{
  int position;
  string word;
  vector<string> words;
  while ((position = s.find(Delimiter)) != std::string::npos)
  {
    word = s.substr(0, position);
    if (word != "")
    {
      words.push_back(word);
    }
    s.erase(0, position + Delimiter.length());
  }
  if (s != "")
  {
    words.push_back(s);
  }
  return words;
}
string joinString(vector<string> words, string Delimiter)
{
  string joinWords = "";
  for (string &word : words)
  {
    joinWords += (word + Delimiter);
  }
  if (joinWords != "")
  {
    return joinWords.substr(0, (joinWords.length() - Delimiter.length()));
  }
  return joinWords;
}
string lowerAllString(string s1)
{
  for (short i = 0; i < s1.length(); i++)
  {
    s1[i] = tolower(s1[i]);
  }
  return s1;
}
string ReplaceWordInString(string s1, string StringToReplace, string replaceTo, bool MatchCase = true)
{
  vector<string> words = splitString(s1, " ");
  for (string &word : words)
  {
    if (MatchCase)
    {
      if (word == StringToReplace)
      {
        word = replaceTo;
      }
    }
    else
    {
      if (lowerAllString(word) == lowerAllString(StringToReplace))
      {
        word = replaceTo;
      }
    }
  }
  return joinString(words, " ");
}
int main()
{
  string s = "How Are you how Are you How Are you";
  cout << ReplaceWordInString(s, "How", "...") << endl;
  cout << ReplaceWordInString(s, "How", "...", false) << endl;
  return 0;
}
