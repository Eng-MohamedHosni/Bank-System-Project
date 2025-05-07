#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

class clsFindCurrencyScreen:protected clsScreen
{
	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "Currency Card: \n";
		cout << "___________________________________\n\n";
		cout << "Country    : " << Currency.Country() << endl;
		cout << "Code       : " << Currency.CurrencyCode() << endl;
		cout << "Name       : " << Currency.CurrencyName() << endl;
		cout << "Rate(1$) = : " << Currency.Rate() << endl;
		cout << "___________________________________\n\n";
	}

	static void _ShowResult(clsCurrency Currency)
	{
		if (Currency.IsEmpty())
		{
			cout << "\nCountry was not found \n";
		}
		else
		{  
			cout << "\nCurrency is found :-)\n\n";
			_PrintCurrency(Currency);
		}
	}

	
public:

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\tFind Currency Screen");

		cout << "Find By: [1] Code or [2] Country ? ";
		short Choice = clsInputValidate::ReadShortNumberBetween(1, 2);
		cout << endl;
		if (Choice == 1)
		{

			cout << "\nPlease Enter Currency Code: ";
			string CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

			_ShowResult(Currency);

		}
		else
		{


			cout << "\nPlease Enter Country Name: ";
			string CountryName = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCountry(CountryName);

			_ShowResult(Currency);
		}

	
	}

};

