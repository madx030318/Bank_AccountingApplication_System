#pragma once
#include <string>
#include "Banking.Interface.cpp"

using namespace std;

class GUI {
private:

    int AccountNumber;
    string ClientName;

    bool SocialAccount;
    string SocialUserName;

    bool LoggedIn;

    IdentificationSystem* CurrentAccount;

    int DepositAmount;
    bool ShowDepositWindow;

public:

    BankingGUI();

    bool Initialize();
    void Run();
    void Shutdown();

    void ShowLoginWindow();
    void ShowBankingWindow();

    bool ValidateLoginInput();
    bool FindAccount();
};

