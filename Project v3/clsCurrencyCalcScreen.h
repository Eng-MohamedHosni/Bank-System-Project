#pragma once

#include <iostream>
#include "clsInputValidate.h"
#include "clsScreen.h";
#include "clsCurrency.h"
#include "clsString.h"

using namespace std;

class clsCurrencyCalcScreen : protected clsScreen
{

	static void _ExchangeToDiffrantCurrancy(clsCurrency Currency1, clsCurrency Currency2, float Amount)
	{
		cout << "\nConvert From:\n";
		Currency1.PrintCurrency();
		cout << "\nTo Dollar:\n";

		float ExchangeToDollar = Currency1.CalcExchange(clsCurrency::FindByCode("USD"), Amount);

		cout << Amount << " " << clsString::UpperAllString(Currency1.CurrencyCode()) <<
			" = " << ExchangeToDollar << " USD\n\n";

		cout << "Converting From USD To:\n\n";
		Currency2.PrintCurrency();
		cout << "\n\n" << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.CalcExchange(Currency2, ExchangeToDollar)
			<< " " << Currency2.CurrencyCode();
	}

	static void _ExchangeToDollar(clsCurrency Currency1, clsCurrency Currency2,float Amount)
	{
		cout << "\nConvert From:\n";
		Currency1.PrintCurrency();

		cout << "\nTo Dollar:\n\n";

		cout << "\n\n" << Amount << " " << Currency1.CurrencyCode() << " = " << Currency1.CalcExchange(Currency2, Amount)
			<< " " << "USD";
	}

public:
	static void ShowCurrencyCalcScreen()
	{
		char ReEnter = 'Y';
		do
		{
			system("cls");
			_DrawScreenHeader("\tCurrency Calculator Screen");

			string Currency1Code;
			string Currency2Code;

			
			cout << "\nPlease Enter Currency1 Code: \n";
			Currency1Code = clsInputValidate::ReadString();
			
			while (!clsCurrency::IsCurrencyExist(Currency1Code))
			{
			cout << "\n Wrong Code Try Again!\nPlease Enter Currency1 Code: \n";
			Currency1Code = clsInputValidate::ReadString();

			}

			clsCurrency Currency1 = clsCurrency::FindByCode(Currency1Code);
			
			cout << "\nPlease Enter Currency2 Code: \n";
			Currency2Code = clsInputValidate::ReadString();
			
			while (!clsCurrency::IsCurrencyExist(Currency2Code))
			{
			cout << "\n Wrong Code Try Again!\nPlease Enter Currency2 Code: \n";
			Currency2Code = clsInputValidate::ReadString();

			}
			clsCurrency Currency2 = clsCurrency::FindByCode(Currency2Code);

			float Amount;
			cout << "\nEnter Amount To Exchange: ";
			Amount = clsInputValidate::ReadFloatNumber();

			if (clsString::UpperAllString(Currency2Code) != "USD")
			{
				_ExchangeToDiffrantCurrancy(Currency1, Currency2, Amount);
			}
			else
			{
				_ExchangeToDollar(Currency1,Currency2,Amount);
			}

			cout << "\n\nDo You Wanna Perform Another Calculation? [Y/n] ? ";
			cin >> ReEnter;

		} while (toupper(ReEnter) == 'Y');
	}

};

