#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsCurrency.h"

using namespace std;

class clsUpdateRateScreen : protected clsScreen
{

public:
	static void ShowUpdateRateScreen()
	{
		_DrawScreenHeader("Update Currency Screen");

		string CurrencyCode;

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		Currency.PrintCurrency();

		char Confirm;
		cout << "\nAre You Sure You Want To Update The Rate OF This Currency [Y/n] ? ";

		cin >> Confirm;

		if (toupper(Confirm) == 'Y')
		{
			cout << "\nUpdate Currency Rate:\n";
			cout << "_____________________________\n";
			
			float NewRate;
			cout << "\nEnter New Rate: ";
			NewRate = clsInputValidate::ReadFloatNumber();
			
			Currency.UpdateRate(NewRate);

			cout << "\nCurrency Rate Updated Sucessfully :-)\n";

			Currency.PrintCurrency();
		}
	}

};

