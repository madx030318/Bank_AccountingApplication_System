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
                CurrentAccount = new IdentificationSystem();
                CurrentAccount->AccountNumber = AccountNumber;
                CurrentAccount->ClientName = ClientName;
                CurrentAccount->SocialAccount = SocialAccount;

                File.close();

                return Found;
            
        }
    }

    
}


bool BankingGUI::ValidateLoginInput() {
    if (AccountNumber <= 0) {

        cout << "Your Account is incorrect. Try Again ! " << endl;
        return false;

    }

    if (ClientName.empty()) {
        cout << "Client name cannot be empty." << endl;
        return false;
    }

    if (SocialAccount && SocialUserName.empty())
    {
        cout << "Social username is required." << endl;
        return false;
    }

    return true
}


void BankingGUI::ProcessLogin()
{
    if (!ValidateLoginInput())
    {
        return;
    }

    if (FindAccount())
    {
        LoggedIn = true;

        cout << "Account was found." << endl;
        cout << "Login successful." << endl;
    }
    else
    {
        LoggedIn = false;

        cout << "Account was not found." << endl;
    }
}

void BankingGUI::ShowLoginWindow()
{
    ImGui::Begin("Banking System");

    ImGui::Text("Account Login");

    
    ImGui::Separator();

    ImGui::InputInt(
        "Account Number",
        &AccountNumber
    );

    ImGui::InputText(
        "Client Name",
        &ClientName
    );

    ImGui::Checkbox(
        "Social Account",
        &SocialAccount
    );

    if (SocialAccount)
    {
        ImGui::InputText(
            "Social Username",
            &SocialUserName
        );
    }

    if (ImGui::Button("Login"))
    {
        ProcessLogin();
    }

    ImGui::End();
}

void BankingGUI::Run()
{
    while (!WindowShouldClose)
    {
        if (!LoggedIn)
        {
            ShowLoginWindow();
        }
        else
        {
            ShowBankingWindow();
        }

    }
}

void BankingGUI::Logout()
{
    if (CurrentAccount != NULL)
    {
        delete CurrentAccount;
        CurrentAccount = NULL;
    }

    LoggedIn = false;

    AccountNumber = 0;
    ClientName = "";
    SocialAccount = false;
    SocialUserName = "";

    cout << "User logged out." << endl;
}
