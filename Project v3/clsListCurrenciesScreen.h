#pragma once

#include <iostream>
#include <iomanip>
#include <fstream>
#include "clsUser.h"
#include "clsScreen.h"
#include "clsCurrency.h"


using namespace std;


class clsListCurrenciesScreen : protected clsScreen
{

    static void _PrintCurrencyRecordLine(clsCurrency Currency)
    {

        cout << setw(8) << left << "" << "| " << setw(30) << left << Currency.Country();
        cout << "| " << setw(7) << left << Currency.CurrencyCode();
        cout << "| " << setw(40) << left << Currency.CurrencyName();
        cout << "| " << setw(20) << left << Currency.Rate();

    }

public:
    static void ShowCurrenciesListScreen()
    {

        if (!CheckAccessRights(clsUser::enPermissions::pCurrencyExchanges))
        {
            return;// this will exit the function and it will not continue
        }

        vector <clsCurrency> vCurrencies = clsCurrency::GetCurrenciesList();
        string Title = "\t  Currencies List Screen";
        string SubTitle = "\t    (" + to_string(vCurrencies.size()) + ") Currency(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(30) << "Country";
        cout << "| " << left << setw(7) << "Code";
        cout << "| " << left << setw(40) << "Name";
        cout << "| " << left << setw(20) << "Rate";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;

        if (vCurrencies.size() == 0)
            cout << "\t\t\t\tNo Currencies Available In the System!";
        else

            for (clsCurrency Currency : vCurrencies)
            {

                _PrintCurrencyRecordLine(Currency);
                cout << endl;
            }

        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "_________________________________________\n" << endl;
    }

};

