#pragma once
#include"clsScreen.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include<string>
#include<iostream>
class clsCurrencyCalculatorScreen:protected clsScreen
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

	static clsCurrency GetCurrency(string Message)
	{
		cout << Message << endl;
		string CurrencyCode = clsInputValidate::ReadString();

		clsCurrency Currency1 = clsCurrency::FindByCode(CurrencyCode);

		while (Currency1.IsEmpty())
		{
			cout << "\nPlease Enter Currency1 Code: \n";
			CurrencyCode = clsInputValidate::ReadString();

			Currency1 = clsCurrency::FindByCode(CurrencyCode);

		}
		return Currency1;
	}


public:

	static void ShowCurrencyCalcultorScreen()
	{
		
		char Continue = 'y';
		do {
			system("cls");
			_DrawScreenHeader("\tCurrency Calcultor Screen");

			clsCurrency Currency1=GetCurrency( "\n\nPlease Enter Currency1 Code: \n");

			clsCurrency Currency2 = GetCurrency("\n\nPlease Enter Currency2 Code: \n");

			cout << "\n\nEnter Amount to Exchange: ";
			double Amount = clsInputValidate::ReadDblNumber();


			cout << "\nConvert From :\n";
			_PrintCurrency(Currency1);

			cout << "\n Convet To : \n";
			_PrintCurrency(Currency2);
			

			float Result = Currency1.ConvertToOtherCurrency(Amount, Currency2);



			cout << endl << Amount << " " << Currency1.CurrencyCode() << " = " << Result << " " << Currency2.CurrencyCode();

			cout << "\n\nDo you want to perform another calcultation? y/n ? ";
			cin >> Continue;
		} while (Continue == 'Y' || Continue == 'y');

		
	}

};

