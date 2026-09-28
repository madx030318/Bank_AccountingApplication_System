#include "BankingNotificationWorkflow.h"
#include <fstream>
#include <string>

using namespace std;

void ShowNotification(const string& Message) {
  ofstream NotificationFile("BankingNotificationTemplates", ios::app);

  if (!NotificationFile.isopen())
  {

    return;

  }

  NotificationFile << Message << endl;

  NotificationFile.close();
};

