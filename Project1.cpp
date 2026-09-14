
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Client address request according to the bank
// There are four clients for testing phase 

int ClientOneAddress(int y)
{
    cout << "Address of #1 to " << &y << endl;
    return y;
}


int ClientTwoAddress(int z)
{
    cout << "Address of #2 to " << &z << endl;
    z = 3;
    return z;
}


int ClientThreeAddress(int* x)
{
    *x = 8;
    return *x;
}


double ClientFourAddress(double& j)
{
    cout << "The Address of #3 is " << &j << endl;
    j = 9;
    return j;
}


void ClientFiveAddress(const vector<int>& numbers)
{
    for (int i = 0; i < numbers.size(); i++)
    {
        cout << numbers[i] << ", ";
    }

    cout << endl;
}


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

    string Services[6] =
    {
        "Add in",
        "Money out",
        "Put on deposit",
        "Transfer money to account",
        "Display Your Accounts",
        "Terminate Account"
    };


    int ClientChoice;
    int Amount;
    int Deposit_Amount;



    



    


   // Interface of services are desiplayed for client of application 
    // After entering the correct password

    cout << "Please choose a service:" << endl;


    for (int k = 0; k < 6; k++)
    {
        cout << k + 1 << ". "
             << Services[k]
             << endl;
    }


    // --------------------------------------------------
    // GET USER CHOICE
    // --------------------------------------------------

    cin >> ClientChoice;


    // --------------------------------------------------
    // CHECK CHOICE
    // --------------------------------------------------
    
while (true) {


    if (ClientChoice >= 1 && ClientChoice <= 6)
    {
        cout << "Selected service: "
             << Services[ClientChoice - 1]
             << endl;
    }
    else
    {
        cout << "The service is invalid. "
             << "Please choose 1 - 6."
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


    default:

        cout << "Invalid service. Please choose 1-6."
             << endl;

        break;
    }


    return 0;
    
    
}



}
