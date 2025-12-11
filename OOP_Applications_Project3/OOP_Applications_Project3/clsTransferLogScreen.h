#pragma once
#include "clsScreen.h"
#include "clsBankClient.h"
#include "iomanip"
#include "iostream"
class clsTransferLogScreen  : protected clsScreen
{
private:

    static void PrintTransferRegisterRecordLine(clsBankClient::stTransferRegisterRecord TRL)
    {

        cout << setw(8) << left << "" << "| " << setw(23) << left << TRL.datetime;
        cout << "| " << setw(8) << left << TRL.Source_Account;
        cout << "| " << setw(8) << left << TRL.Destination_Account;
        cout << "| " << setw(8) << left << TRL.balance;
        cout << "| " << setw(10) << left << TRL.Source_Balance;
        cout << "| " << setw(10) << left << TRL.Destination_Balance;
        cout << "| " << setw(8) << left << TRL.user;

    }

public:

    static void ShowTransferRegisterScreen()
    {
       /* if (!CheckAccessRights(clsUser::enPermissions::pLogingRegsiter)) {
            return;
        }*/

        vector <clsBankClient::stTransferRegisterRecord> vTransferRegisterRecord = clsBankClient::GetTransferRegisterList();

        string Title = "\tTransfer Log List Screen";
        string SubTitle = "\t\t(" + to_string(vTransferRegisterRecord.size()) + ") Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(23) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;


        if (vTransferRegisterRecord.size() == 0)
            cout << "\t\t\t\tNo Logins Available In the System!";
        else

            for (clsBankClient::stTransferRegisterRecord Record :vTransferRegisterRecord )
            {

                PrintTransferRegisterRecordLine(Record);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

    }
};

