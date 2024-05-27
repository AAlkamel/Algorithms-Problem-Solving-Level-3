#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
string FileName = "client.csv";
struct sClient
{
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  double AccountBalance;
};

string readString(string message)
{
  string theString;
  cout << "\n"
       << message;
  getline(cin >> ws, theString);
  return theString;
}
sClient ReadNewClient()
{
  sClient client;
  string delimter = "#||#";
  cout << "Please enter client data:\n";
  client.AccountNumber = readString("enter account number: ");
  client.PinCode = readString("enter pinCode: ");
  client.Name = readString("enter Name: ");
  client.Phone = readString("enter phone: ");
  cout << "\nenter account Balance: ";
  cin >> client.AccountBalance;
  return client;
}
string clientToLine(sClient client, string delimter)
{
  return (
      client.AccountNumber + delimter +
      client.PinCode + delimter +
      client.Name + delimter +
      client.Phone + delimter +
      to_string(client.AccountBalance));
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
sClient convertLineToRecord(string clientLine, string delimter)
{
  sClient client;
  vector<string> records = splitString(clientLine, delimter);
  client.AccountNumber = records[0];
  client.PinCode = records[1];
  client.Name = records[2];
  client.Phone = records[3];
  client.AccountBalance = stod(records[4]);
  return client;
}
void printClientRecord(sClient client)
{
  cout << "<===:The client record is:===> \n\n";
  cout << "    Account number   : " << client.AccountNumber << endl;
  cout << "    Account pinCode  : " << client.PinCode << endl;
  cout << "    Client  name     : " << client.Name << endl;
  cout << "    Account phone    : " << client.Phone << endl;
  cout << "    Account balance  : " << client.AccountBalance << "\n"
       << endl;
}
void AddDataLineToFile(string fileName, string clientLine)
{
  fstream MyFile;
  MyFile.open(FileName, ios::out | ios::app);
  if (MyFile.is_open())
  {
    MyFile << clientLine << endl;
    MyFile.close();
  }
}
void AddClients()
{
  char again = 'y';
  while (tolower(again) == 'y')
  {
    system("cls");
    sClient client = ReadNewClient();
    AddDataLineToFile(FileName, clientToLine(client, ","));
    printClientRecord(client);
    cout << "To add more clients enter y" << endl;
    cin >> again;
  }
}
int main()
{
  AddClients();
  return 0;
}
