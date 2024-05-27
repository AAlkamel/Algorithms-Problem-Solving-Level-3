#include <iostream>
#include <string>
using namespace std;

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
int main()
{
  char c = readChar();
  cout << "\nthe letter: " << c << (IsVowel(c) ? " is a vowel" : " is Not a vowel") << endl;
}