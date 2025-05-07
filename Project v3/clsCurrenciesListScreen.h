#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"iomanip"

class clsCurrenciesListScreen:protected clsScreen
{

	static void _PrintCountryPart(clsCurrency Currency)
	{
		cout << setw(7) << "" << "| " << setw(35) << left << Currency.Country();
		cout << "| " << setw(9) << left << Currency.CurrencyCode();
		cout << "| " << setw(40) << left << Currency.CurrencyName();
		cout << "| " << setw(14) << left << Currency.Rate()<<"\n";
	}

public:

	static void ShowCurrunciesListScreen()
	{
		vector<clsCurrency>vCurreneies= clsCurrency::GetCurrenciesList();
		_DrawScreenHeader("\tCurrencies List Screen", "(" + to_string(vCurreneies.size()) + ") Currency.");
		
		cout << setw(7) << "" << "----------------------------------------------------------------------------------------------------------------\n";
		cout << setw(7) << "" << "| " << setw(35) << left << "Country";
		cout << "| " << setw(9) << left << "Code";
		cout << "| " << setw(40) << left << "Name";
		cout << "| " << setw(14) << left << "Rate/(1$) |\n";
		cout << setw(7) << "" << "--------------------------------------------------------------------------------------------------------------\n";


		for (clsCurrency C : vCurreneies)
		{
			_PrintCountryPart(C);
		}

   
 	}

};

