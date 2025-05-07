#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
class clsUpdateCurrencyScreen:protected clsScreen
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


public:

	static void ShowUpdateCurrencyScreen()
	{
		_DrawScreenHeader("\tUpdate Currency Screen");

		cout << "Please Enter Currency Code: ";
		string CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		if (Currency.IsExist())
		{
			_PrintCurrency(Currency);
			cout << "\n\nAre you sure you want to update the rate of this currency y/n? ";
			char Answer;
			cin >> Answer;
			if (toupper(Answer) == 'Y')
			{
				cout << "\nUpdate Currency Rate:\n";
				cout << "___________________________\n\n";
				cout << "Enter New Rate: ";
				float NewRate = clsInputValidate::ReadFloatNumber();
				Currency.UpdateRate(NewRate);
				_PrintCurrency(Currency);
				cout << endl;
			}
			else
			{
				cout << "Currency code is not found \n";
			}

		}


	}
};

