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
char readChar()
{
  char theChar;
  cout << "enter your Char\n";
  cin >> theChar;
  return theChar;
}
bool IsVowel(char Character)
{
  char c = tolower(Character);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}
int countVowels(string s)
{
  int count = 0;
  for (int i = 0; i < s.length(); i++)
  {
    if (IsVowel(s[i]))
      count++;
  }
  return count;
}

int main()
{
  string s1 = readString();
  cout << "\n count vowels is: " << countVowels(s1) << endl;
}