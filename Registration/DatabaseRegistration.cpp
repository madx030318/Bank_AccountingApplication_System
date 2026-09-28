#include "DatabaseRegistration.h"
#include <iostream>
#include <fstream>

using namespace std;

ClientDatabase::ClientDatabase()
{
  DatabaseFile = "Client database info.txt";
}

ClientDatabase::ClientDatabase(string FileName)
{
  DatabaseFile = FileName;
}

void ClientDatabase::AddClient(const IdentificationSystem& Client)
{
  ofstream Database(DatabaseFile.c_str(), ios::app);

  if (!Database.isopen()) {

    cout << "Database could not be opened" << endl;
    return;

    
  }

  Database << "AccountNumber : " << Client.AccountNumber << endl;
  Database << "ClientName : " << Client.ClientName << endl;
  Database << "AccountStatus: " << (Client.AccountStatus ? "Active" : "Terminated") << endl;
  Database << "Balance: " << Client.Balance << endl;
  Database << "DepositBalance: " << Client.Deposit_Balance << endl;
  Database << "QRSymbols: " << Client.QRSymbols << endl;
  Database << "SocialAccount: " << (Client.SocialAccount ) << endl;
  Database << "SocialUsername: " << Client.SocialUsername << endl;

    Database << "----------------------------------------"
             << endl;

    Database.close();
}

void ClientDatabase::DisplayDatabase() {
  ifstream Database(DatabaseFile.c_str());
  if (!Database.is_open()) {
    cout << "Database could not be opened." << endl;
    return;
  }

  string Line;
  while (getline(Database, Line)) {
    cout << Line << endl;
  }

  Database.close();
}

void ClientDatabase::AddClient(const IdentificationSystem& Client)
{
    lock_guard<mutex> Lock(DatabaseMutex);

    ofstream Database(DatabaseFile.c_str(), ios::app);

    if (!Database.is_open())
    {
        cout << "Database could not be opened." << endl;
        return;
    }

    // write client information

    Database.close();
}

}
