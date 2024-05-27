#include <iostream>
#include <string>
using namespace std;
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
  getline(cin, theString);
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
int main()
{
  cout << clientToLine(ReadNewClient(), "#||#") << endl;
  return 0;
}
