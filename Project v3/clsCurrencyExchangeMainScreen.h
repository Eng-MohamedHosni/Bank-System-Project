#pragma once
#include"clsScreen.h"
#include<iomanip>
#include"clsInputValidate.h"
#include"clsCurrenciesListScreen.h"
#include"clsFindCurrencyScreen.h"
#include"clsUpdateCurrencyScreen.h"
#include"clsCurrencyCalculatorScreen.h"

class clsCurrencyExchangeMainScreen :protected clsScreen
{
private:

	enum enMenueOption { eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrencyCalculator = 4, eMainMenue = 5 };

	static enMenueOption ReadCurrencyExhangeMenueOption()
	{
		short Option = 0;
		cout << setw(37) << "" << "Choose what you want to do? [1 to 5]? ";
		Option = clsInputValidate::ReadShortNumberBetween(1, 5);
		return (enMenueOption)Option;
	}

	static void _ShowListCurrenciesScreen()
	{
		clsCurrenciesListScreen::ShowCurrunciesListScreen();
	}
	static void _ShowFindCurrencyScreen()
	{
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen()
	{
		clsUpdateCurrencyScreen::ShowUpdateCurrencyScreen();
	}
	static void _ShowCurrencyCalculatorScreen()
	{
		clsCurrencyCalculatorScreen::ShowCurrencyCalcultorScreen();
	}
	

	static void _GoBackToCurrencyExhangeMainMenue()
	{
		cout << "\nPress enter to go back to Currencies Main Menue Screen";
		system("pause>0");
		system("cls");
		ShowCurrencyExhangeMainScreen();
	}
	static void _PerformCurrencyExhangeMenue(enMenueOption Option)
	{
		switch (Option)
		{
		case enMenueOption::eListCurrencies:
		{
			system("cls");
			_ShowListCurrenciesScreen();
			_GoBackToCurrencyExhangeMainMenue();
			
		}
		case enMenueOption::eFindCurrency:
			system("cls");
			_ShowFindCurrencyScreen();
			_GoBackToCurrencyExhangeMainMenue();
			break;
		case enMenueOption::eUpdateRate:
			system("cls");
			_ShowUpdateRateScreen();
			_GoBackToCurrencyExhangeMainMenue();
			break;
		case enMenueOption::eCurrencyCalculator:
			system("cls");
			_ShowCurrencyCalculatorScreen();
			_GoBackToCurrencyExhangeMainMenue();
			break;
		case eMainMenue:

			break;
		
		}

	}

public:
 

	static void ShowCurrencyExhangeMainScreen()
	{
		_DrawScreenHeader("\tCurrency Exhange Main Screen");

		cout << setw(37) << "" << "====================================================\n";
		cout << setw(37) << "" << "\t\t  Currency Exhange Menue\n";
		cout << setw(37) << "" << "====================================================\n";
		cout << setw(37) << "" << "\t[1] ListCurrencies.\n";
		cout << setw(37) << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << "" << "\t[5] Main Menue.\n";
		cout << setw(37) << "" << "====================================================\n";
		_PerformCurrencyExhangeMenue(ReadCurrencyExhangeMenueOption());



	}



};

