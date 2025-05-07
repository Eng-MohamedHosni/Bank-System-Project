#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindCurrency : protected clsScreen
{

public:
	static void _ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t  Find Currency Screen");

		short Choice;
		do
		{
		cout << "\nFind By: [1] Code or [2] Country ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1,2,"Please Enter Number From 1 To 2 ");
		} while (Choice < 1 || Choice > 2);

		if (Choice == 1)
		{
			cout << "\nPlease Enter CurrenctCode ? ";
			string Code = clsInputValidate::ReadString();

			clsCurrency Currency = clsCurrency::FindByCode(Code);

			if (clsCurrency::IsCurrencyExist(Code))
			{
				cout << "\nCurrency Found :-)\n";
				Currency.PrintCurrency();
			}
			else
			{
				cout << "\nCurrency Not Found :-)\n";
				
			}
			

		}
		else if (Choice == 2)
		{
			cout << "\nPlease Enter Country Name ? ";

			string Country = clsInputValidate::ReadString();
			
			clsCurrency Currency = clsCurrency::FindByCountry(Country);

			if (Currency.IsEmpty())
			{
				cout << "\nCurrency Not Found :-)\n";
			}
			else
			{
				cout << "\nCurrency Found :-)\n";
				Currency.PrintCurrency();
			}

		}
		
	}

	

};

