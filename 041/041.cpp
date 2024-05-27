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
string joinReverseString(vector<string> words, string Delimiter)
{
  string joinWords = "";
  for (int i = words.size() - 1; i >= 0; i--)
  {
    joinWords += (words[i] + Delimiter);
  }
  if (joinWords != "")
  {
    return joinWords.substr(0, (joinWords.length() - Delimiter.length()));
  }
  return joinWords;
}
int main()
{
  string s1 = readString();
  vector<string> words = splitString(s1, " ");
  cout << "\n The count Words in your string is : " << words.size() << endl;
  for (string &i : words)
  {
    cout << i << endl;
  }
  cout << "\nYour Words in string is : " << joinString(words, " ") << endl;
  cout << "\nYour Words Reversed in string is : " << joinReverseString(words, " ") << endl;
}