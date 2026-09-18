#include "CreditManagamentprofile.h"
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <ctime>

using namespace std;

CreditSystem::CreditSystem() {  // - The default parameters for system , will be differentitanted depend of client;

  AccountNumber = 0;
  Application = false;
  Sum = 0;
  PercentofYear = 0;
  ApplicationDate = " ";
  EndingDate = " ";
  ApprovedStatus = false;
  DurationMonths = 0;
  
}

CreditSystem::CreditSystem(int CreditSystem& Parama) {
    AccountNumber = Parama.AccountNumber,
    Sum = Parama.Sum,
    PercentOfYear = Parama.PercentOfYear,
    ApplicationDate = Parama.ApplicationDate,
    DurationMonths = Parama.DurationMonths
      }


void CreditSystem::ApplyForCredit()
{
    Application = true;

    cout << "Credit application submitted."
         << endl;
}

bool CreditSystem::CanBeApproved()
{
    if (Application == true &&
        Sum > 0 &&
        PercentOfYear > 0 &&
        DurationMonths > 0)
    {
        Approved = true;

        return true;
    }

    Approved = false;

    return false;
}

void AnalyzeEndingDate() {
  int Year;
  int Month;
  int Day;

  char Separator;

  stringstream Date(ApplicationDate);

  Date >> Year >> Separator >> Month >> Separator >> Day;

  Month += DurationMonths;

  while (Month > 12)
    {
        Month -= 12;
        Year++;
    }

  stringstream Result;

  Result << Year << "-";

  if (Month < 10) {
    Result << "0";
  }

  if (Day < 10) {
    Result << "0";
  }

  Result << Day;

  EndingDate = Result.str();

  

}


