#pragma once

#include <vector>
#include <iostream>
#include "clsUser.h"
#include <fstream>
#include <iomanip>
#include "clsTransferScreen.h"
#include "clsBankClient.h"

using namespace std;

class clsTransferLogScreen :protected clsScreen
{



   

    static void PrintTransferLogUserPart(clsBankClient::stTransferLog Record)
    {
        cout  <<setw(8)<<"" << "| " << Record.DateTime;
        cout << "| " << left << setw(8) << Record.FromAccNumber;
        cout << "| " << left << setw(8) << Record.ToAccNumber;
        cout << "| " << left << setw(8) << Record.Amount;
        cout << "| " << left << setw(10) << Record.FromAccBanlance;
        cout << "| " << left << setw(10) << Record.ToAccBalance;
        cout << "| " << left << setw(8) << Record.UserName;
    }

public :
	static void ShowTransferLogScreen()
	{
        vector<clsBankClient::stTransferLog>vRecords = clsBankClient::LoadTransferLogRecordsFromFile();
        _DrawScreenHeader("\tTransfer Log List Screen","("+to_string(vRecords.size())+") Record(s).");

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(20) << "Date/Time";
        cout << "| " << left << setw(8) << "s.Acct";
        cout << "| " << left << setw(8) << "d.Acct";
        cout << "| " << left << setw(8) << "Amount";
        cout << "| " << left << setw(10) << "s.Balance";
        cout << "| " << left << setw(10) << "d.Balance";
        cout << "| " << left << setw(8) << "User";

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
        if (vRecords.size() == 0)
        {
            cout << setw(10) << "" << "There is no Transfer Log in the system\n";
        }
        else
        {
            for (clsBankClient::stTransferLog& R : vRecords)
            {
                PrintTransferLogUserPart(R);
                cout<< endl;
            }
        }
        
	}

};

