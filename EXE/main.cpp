#include "BankingGUI.cpp"
#include "CreditManagementprofile.cpp"
#include "DatabaseRegistration.cpp"
#include "BankingInterface.cpp"
#include <fstream>
#include <string>

int main() {
  BankingGUI GUI;
  CreditManagementprofile CreditProfile;
  RegistrationSystem Register;
  IdentificationSystem InputData;

  cin >> AccountNumber;
  cin >>ClientName;
  cin >> SocialAccount;
  cin >> SocialUserName;

  ifstream File("Client database info.txt");

  if (!File.is_open())
    {
        cout << "Could not open condition.txt" << endl;
        return 1;
    }

  string FileAccountNumber;
    string FileClientName;
    string FileSocialAccount;
    string FileSocialUserName;

    bool Found = false;

    while (File >> FileAccountNumber
                >> FileClientName
                >> FileSocialAccount
                >> FileSocialUserName)
    {
        if (FileAccountNumber == AccountNumber &&
            FileClientName == ClientName &&
            FileSocialAccount == SocialAccount &&
            FileSocialUserName == SocialUserName)
        {
            Found = true;
            break;
        }
    }

  if (Found)
    {
        cout << "Account was found." << endl;
    }
    else
    {
        cout << "Account was not found." << endl;
    }


  File.close();
  
  
  

  if (!GUI.Initialize())
    {
        return 1;
    }

  GUI.Run();
  GUI.Shutdown();

}
