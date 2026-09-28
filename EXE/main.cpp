#include "BankingGUI.cpp"
#include "CreditManagementprofile.cpp"
#include "DatabaseRegistration.cpp"

int main() {
  BankingGUI GUI;
  CreditManagementprofile CreditProfile;
  RegistrationSystem Register;

  if (!GUI.Initialize())
    {
        return 1;
    }

  GUI.Run();
  GUI.Shutdown();

}
