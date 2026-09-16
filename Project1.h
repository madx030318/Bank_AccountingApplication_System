#ifndef REGISTRATIONSYSTEM_H
#define REGISTRATIONSYSTEM_H

using namespace std;

class RegistrationSystem
{
private:

    string DatabaseFile;

public:

    RegistrationSystem();

    RegistrationSystem(string FileName);

    void RegisterClient(IdentificationSystem& Client);

    void AddClientToDatabase(const IdentificationSystem& Client);

    bool AccountExists(int AccountNumber);

};
