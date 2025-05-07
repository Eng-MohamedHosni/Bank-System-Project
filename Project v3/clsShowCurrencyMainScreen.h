#pragma once


#include <iostream>
#include <string>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrenciesScreen.h";
#include "clsFindCurrency.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalcScreen.h";

using namespace std;

class clsShowCurrencyMainScreen : protected clsScreen
{


    enum enCurrencyMenueOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3,
        eCurrencyCalculator = 4, eMainMenu = 5
    };

    static short _ReadCurrencyMenueOptions()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5 ");
        return Choice;
    }

    static void _ShowListCurrenciesScreen()
    {
        //cout << "\nList Currencies Screen Will Be Here\n";

        clsListCurrenciesScreen::ShowCurrenciesListScreen();
    }

    static void _ShowFindCurrencyScreen()
    {
        //cout << "\nFind Currency Screen Will Be Here\n";
        clsFindCurrency::_ShowFindCurrencyScreen();
    }

    static void _ShowUpdateRateScreen()
    {
        //cout << "\nUpdate Rate Screen Will Be Here\n";
        clsUpdateRateScreen::ShowUpdateRateScreen();
    }

    static void _ShowCurrencyCalculatorScreen()
    {
        //cout << "\nCurrency Calculator Screen Will Be Here\n";
        clsCurrencyCalcScreen::ShowCurrencyCalcScreen();
    }

    static void _GoBackToCurrancyMainScreen()
    {
        cout << "\nPress Any Key To Go Back To Currancy Main Screen\n";
        system("pause>0");
        ShowCurrancyMainScreen();
    }

    static void _PerfromCurrencyMenueOptions(enCurrencyMenueOptions CurrencyMenueOptions)
    {
        switch (CurrencyMenueOptions)
        {
        case clsShowCurrencyMainScreen::eListCurrencies:
            system("cls");
            _ShowListCurrenciesScreen();
            _GoBackToCurrancyMainScreen();

            break;
        case clsShowCurrencyMainScreen::eFindCurrency:
            system("cls");
            _ShowFindCurrencyScreen();
            _GoBackToCurrancyMainScreen();

            break;
        case clsShowCurrencyMainScreen::eUpdateRate:
            system("cls");
            _ShowUpdateRateScreen();
            _GoBackToCurrancyMainScreen();

            break;
        case clsShowCurrencyMainScreen::eCurrencyCalculator:
            system("cls");
            _ShowCurrencyCalculatorScreen();
            _GoBackToCurrancyMainScreen();
            break;
        case clsShowCurrencyMainScreen::eMainMenu:

            break;
        default:
            break;
        }
    }

public:
    static void ShowCurrancyMainScreen()
    {
        system("cls");

        _DrawScreenHeader("   Currancy Exhange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\tCurrancy Exhange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyMenueOptions((enCurrencyMenueOptions)_ReadCurrencyMenueOptions());

    }

};

