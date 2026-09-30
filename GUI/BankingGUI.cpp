#include "BankingGUI.h"
#include <iostream>
#include <fstream>

using namespace std;

BankingGUI::BankingGUI()
{
    AccountNumber = 0;

    ClientName = "";

    SocialAccount = false;

    SocialUserName = "";

    LoggedIn = false;

    CurrentAccount = NULL;
}

bool BankingGUI::FindAccount()
{
    ifstream File("Client database info.txt");

    if (!File.is_open())
    {
        cout << "Could not open client database." << endl;
        return false;
    }

    string FileAccountNumber;
    string FileClientName;
    string FileSocialAccount;
    string FileSocialUserName;
bool Found = false;

    string InputAccountNumber =
        to_string(AccountNumber);

    string InputSocialAccount =
        SocialAccount ? "true" : "false";

    while (File >> FileAccountNumber
                >> FileClientName
                >> FileSocialAccount
                >> FileSocialUserName)
    {
        if (FileAccountNumber == InputAccountNumber &&
            FileClientName == ClientName &&
            FileSocialAccount == InputSocialAccount &&
            FileSocialUserName == SocialUserName)
            {
            Found = true;
            break;
        }
    }

    File.close();

    return Found;
}
