
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "CreditManagementprofile.h"

using namespace std;

class IdentificationSystem
{
public:

    int AccountNumber;
    string ClientName;
    int Balance;
    int Deposit_Balance;
    string AccountOperations;
    string MainMenu;
    bool AccountStatus;
    string Password;
    bool bHasPassword;
    bool bIsBlocked;
    string QRSymbols;
    int SocialAccount;
    string SocialUserName;
    int SocialBalance;
    bool Application;
    int SumofCredit;
    int PercentOfYear;
    string ApplicationDate;
    string EndingDate;
    bool ApprovedStatus;
    int DurationMonths;


    // Assignment operator
    IdentificationSystem& operator=(const IdentificationSystem& Other)
    {
        AccountNumber = Other.AccountNumber;
        ClientName = Other.ClientName;
        Balance = Other.Balance;
        Deposit_Balance = Other.Deposit_Balance;
        AccountOperations = Other.AccountOperations;
        MainMenu = Other.MainMenu;
        AccountStatus = Other.AccountStatus;
        Password = Other.Password;
        bHasPassword = Other.bHasPassword;
        bIsBlocked = Other.bIsBlocked;
        QRSymbols = Other.QrSymbols;
        SocialAccount = Other.SocialAccount;
        SocialUserName = Other.SocialUserName;
        SocialBalance = Other.SocialBalance;
        Application = Other.Application;
        SumofCredit = Other.SumofCredit;
        PercentOfYear = Other.PercentOfYear;
        ApplicationDate = Other.ApplicationDate;
        EndingDate = Other.EndingDate;
        ApprovedStatus = Other.ApprovedStatus;
        DurationMonths = Other.DurationMonths;

        return *this;
    }


    // Get account number
    int GetAccountN()
    {
        cout << "Client Number is " << AccountNumber << endl;
        return AccountNumber;
    }


    // Get client name
    string GetClientN()
    {
        cout << "The Client Name is " << ClientName << endl;
        return ClientName;
    }


    // Get balance
    int GetBalance()
    {
        cout << "The Client's Balance " << Balance << endl;
        return Balance;
    }


    // Check whether account is active
    bool IsActive()
    {
        cout << "AccountStatus - " << AccountStatus << endl;
        return AccountStatus;
    }


    // Check whether account is eliminated
    bool IsEliminateAccount()
    {
        return AccountStatus;
    }


    int GetSocialAccount()
{
    cout << "Here is your Social Account ---> " << SocialAccount << endl;
    return SocialAccount;

}

   string GetSocialName()
{
    cout << "The name of actual pocessed account ---- "  > SocialUserName << endl;
    return SocialUserName;

}


};

bool ClientEnterPassword(IdentificationSystem& Account)
{
    string PasswordInput;

    cout << "Please enter your password: ";
    cin >> PasswordInput;

    if (PasswordInput == Account.Password)
    {
        return true;
    }

    return false;
}

void GenerateQRCode() 
{
    long long code = 4448889993211LL;

    return to_string(code);
}

int SumofCredit() {

    if (Application == true & ApprovedStatus == true)
    {
        return SumofCredit;

    }

}

// --------------------------------------------------
// MAIN
// --------------------------------------------------

int main()
{
    // --------------------------------------------------
    // TEST ACCOUNT
    // --------------------------------------------------



    vector<IdentificationSystem> Testing;


    IdentificationSystem Client1;

    Client1.AccountNumber = 1003;
    Client1.ClientName = "Tyler";
    Client1.AccountStatus = true;
    Client1.Balance = 5000;
    Client1.Deposit_Balance = 0;
    Client1.Password = "Tyler1991**";
    Client1.bHasPassword = true;
    Client1.bIsBlocked = false;
    long long code = 4455331224LL;
    Client1.QRSymbols = to_string(code);
    Client1.SocialAccount = 8000;
    Client1.SocialUserName = &Client1.ClientName;
    Client1.CreditApplicationStatus = false;
    Client1.CreditAmount = 0;
    Credit1.CreditPeriod = "0/0/0";


    Testing.push_back(Client1);




    IdentificationSystem* CurrentAccount = NULL;


    for (int i = 0; i < Testing.size(); i++)
    {
        IdentificationSystem& Account = Testing[i];

        if (Account.GetAccountN() == 1003)
        {
            CurrentAccount = &Account;
            break;
        }
    }


    if (CurrentAccount == NULL)
    {
        cout << "There is a mistake. No such account exists."
             << endl;

        return 0;
    }

    for (int k = 0; k < Testing.size(); k++) {
        IdentificationSystem& Account = Testing[k];
        if (Account.GetSocialAccount() == 8000) {
            CurrentAccount = &Account;
            break;
            
    }
    }

    if (CurrentAccount == NULL) 
    {
        cout << "There is no such social account. " << endl;
        return 0;
    }

    // After the implenmentation of oop the system must identify the user via password authentification

    id (CurrentAccount->bHasPassword)
        {
        if (!ClientEnterPassword(*CurrentAccount))
        {
            cout << "Incorrect Password. You are blocked by system. " << endl;
            return 0;
        }
    }


    // Implementation of menu services section

    string Services[10] =
    {
        "Add in",
        "Money out",
        "Put on deposit",
        "Transfer money to account",
        "Display Your Accounts",
        "Terminate Account",
        "QR Code Generation",
        "Social Account Personal",
        "Credit Info",
        "Pay Credit"
    };


    int ClientChoice;
    int Amount;
    int Deposit_Amount;
    int Social_Amount;
    int RemainingCreditSum;
    



    



    


   // Interface of services are desiplayed for client of application 
    // After entering the correct password

    cout << "Please choose a service:" << endl;


    for (int k = 0; k < 10; k++)
    {
        cout << k + 1 << ". "
             << Services[k]
             << endl;
    }


    // Client inputs his choice

    cin >> ClientChoice;


    // Check choice system implementatiob
    
while (true) {


    if (ClientChoice >= 1 && ClientChoice <= 10)
    {
        cout << "Selected service: "
             << Services[ClientChoice - 1]
             << endl;
    }
    else
    {
        cout << "The service is invalid. "
             << "Please choose 1 - 10."
             << endl;

        return 0;
    }



    switch (ClientChoice)
    {


    case 1:

        cout << "Please enter the amount you want to add in: ";

        cin >> Amount;


        CurrentAccount->Balance += Amount;


        cout << "The amount is processed."
             << endl;

        cout << "Your balance -> "
             << CurrentAccount->Balance
             << endl;

        break;


  
    case 2:

        cout << "Please enter the amount you want to withdraw: ";

        cin >> Amount;


        CurrentAccount->Balance -= Amount;


        cout << "The amount is processed."
             << endl;

        cout << "Your balance -> "
             << CurrentAccount->Balance
             << endl;

        break;


    case 3:

        cout << "Please enter the amount you want to put on deposit: ";

        cin >> Deposit_Amount;


        CurrentAccount->Deposit_Balance += Deposit_Amount;


        cout << "The deposit is processed."
             << endl;

        cout << "The deposit balance is "
             << CurrentAccount->Deposit_Balance
             << endl;

        break;


    case 4:

        cout << "Please enter the account number to transfer money to: ";

        int TransferAccount;

        cin >> TransferAccount;


        cout << "Transfer account: "
             << TransferAccount
             << endl;

        break;


    case 5:

        cout << "Displaying your accounts..."
             << endl;


        for (int i = 0; i < Testing.size(); i++)
        {
            IdentificationSystem& Account = Testing[i];


            cout << "Account: "
                 << Account.AccountNumber

                 << " | Client: "
                 << Account.ClientName

                 << " | Balance: "
                 << Account.Balance
                 
                 << " | Deposit Account: " 
                 << Account.Deposit_Balance

                 << endl;
        }

        break;


  
    case 6:

        cout << "Are you sure you want to terminate your account? ";

        char ClientAnswer;

        cin >> ClientAnswer;


        if (ClientAnswer == 'y' || ClientAnswer == 'Y')
        {
            CurrentAccount->AccountStatus = false;

            cout << "Account was terminated."
                 << endl;
        }
        else
        {
            cout << "Account termination cancelled."
                 << endl;
        }

        break;


    case 7:
        CurrentAccount->QRSymbols = GenerateQRCode();
        cout << "Please view your QR Code" << CurrentAccount->QRSymbols << endl;

        break;


    case 8:
        CurrentAccount->SocialAccount = GetSocialAccount();
        cout << "The SocialAccountInfo << Account.SocialBalance << endl;

    case 9:
        CurrentAccount->CreditSystem = DisplayCreditInformation();
        cout << "_____YOUR CREDIT INFORMATION INFO____" << endl << Account.CreditSystem() << endl;

    case 10:
        if (CurrentAccount->Balance >= 0 || CurrentAccount->Balance <= 0) {

            cin >> Balance;

            int RemainingSum = CurrentAccount->SumofCredit - Balance;

            cout << "You just pay -> " << Account.Balance << endl;

            cout << "The sum remaining for closing credit" << RemainingSum << endl;


        }
        

        


    default:

        cout << "Invalid service. Please choose 1-6."
             << endl;

        break;
    }


    return 0;
    
    
}



}
