#include <iostream>
#include <string>
#include <vector>
using namespace std;
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
string joinString(string words[], short length, string Delimiter)
{
  string joinWords = "";
  for (short i = 0; i < length; i++)
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

  vector<string> words = {"How", "are", "you?"};
  string wordsArr[] = {"How", "are", "you?"};
  cout << "\n The count Words in your string is : " << words.size() << endl;
  for (string &i : words)
  {
    cout << i << endl;
  }
  cout << "\nYour vector Words in string is : " << joinString(words, ",") << endl;
  cout << "\nYour Array Words in string is : " << joinString(wordsArr, 3, ",") << endl;
}