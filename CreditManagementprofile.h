
#ifndef CREDITSYSTEM_H
#define CREDITSYSTEM_H

#include <string>
#include "DatabaseClient.h"

using namespace std;

class CreditSystem {
private:
int AccountNumber;
bool Application;
int SumofCredit;
int PercentOfYear;
string ApplicationDate;
string EndingDate;
bool ApprovedStatus;
int DurationMonths;
public:

    CreditSystem();

    CreditSystem(
        int AccountNumber,
        int Sum,
        int PercentOfYear,
        string ApplicationDate,
        string EndingDate,
        int DurationMonths
    );

void ApplyForCredit();
bool CanBeApproved();
void AnalyzeEndingDate();
void DisplayCreditInformation();
int FindClient();
bool IsApproved();
}

#endif
