#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;
string FileName = "client.csv";
string delim = ",";
struct sClient
{
  string AccountNumber;
  string PinCode;
  string Name;
  string Phone;
  double AccountBalance;
  bool MarkForDelete;
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
vector<sClient> loadClientsDataFromFile(string FileName)
{
  fstream MyFile;
  vector<sClient> clients;
  MyFile.open(FileName, ios::in); // read only
  if (MyFile.is_open())
  {
    string line;
    sClient client;
    while (getline(MyFile, line))
    {
      client = convertLineToRecord(line, delim);
      clients.push_back(client);
      // printClientRecord(client);
    }
    MyFile.close();
  }
  return clients;
}
void printClientsHeader(int count)
{
  cout << "                     client list (" << count << ") client(s)                   " << endl;
  cout << "===========================================================================" << endl;
  cout << "| Account Number  | Pin code  | Client Name       | Phone       | Balance  ";
  cout << "\n===========================================================================" << endl;
}
void printClient(sClient client)
{
  cout << "| " << left << setw(16) << client.AccountNumber;
  cout << "| " << left << setw(10) << client.PinCode;
  cout << "| " << left << setw(18) << client.Name;
  cout << "| " << left << setw(12) << client.Phone;
  cout << "| " << left << setw(9) << client.AccountBalance << "\n";
  cout << "---------------------------------------------------------------------------" << endl;
}
void printClientsData(vector<sClient> clients)
{
  printClientsHeader(clients.size());
  for (sClient &client : clients)
  {
    printClient(client);
  }
}
bool findClientByAccountNumber(vector<sClient> clients, string AccountNumber, sClient &client)
{
  for (sClient &c : clients)
  {
    if (c.AccountNumber == AccountNumber)
    {
      client = c;
      return true;
    }
  }
  return false;
}
bool MarkClientForDelete(vector<sClient> &clients, string AccountNumber)
{
  for (sClient &c : clients)
  {
    if (c.AccountNumber == AccountNumber)
    {
      c.MarkForDelete = true;
      return true;
    }
  }
  return false;
}
string ReadAccountNumber()
{
  return readString("enter AccountNumber to find client?\n");
}
void SaveClientsDataToFile(string fileName, vector<sClient> &clients)
{
  fstream MyFile;
  MyFile.open(FileName, ios::out);
  if (MyFile.is_open())
  {
    for (sClient &client : clients)
    {
      if (!client.MarkForDelete)
      {
        MyFile << clientToLine(client, ",") << endl;
      }
    }

    MyFile.close();
  }
}
bool DeleteClientByAccountNumber(vector<sClient> &clients, string AccountNumber)
{
  sClient client;
  char Answer = 'n';
  if (findClientByAccountNumber(clients, AccountNumber, client))
  {
    printClientRecord(client);
    cout << "\n\nAre you sure you want delete this client? [y/n]";
    cin >> Answer;
    if (Answer == 'y' || Answer == 'Y')
    {
      MarkClientForDelete(clients, AccountNumber);
      SaveClientsDataToFile(FileName, clients);
      // refresh data
      clients = loadClientsDataFromFile(FileName);
      cout << "\n\nClient deleted successfully";
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    cout << "The client with account number (" << AccountNumber << ") not found.";
  }
  return false;
}

int main()
{
  vector<sClient> clients = loadClientsDataFromFile(FileName);
  // printClientsData(clients);
  // AddClients();
  string AccountNumber = ReadAccountNumber();
  DeleteClientByAccountNumber(clients, AccountNumber);
  system("pause>0");
  return 0;
}
