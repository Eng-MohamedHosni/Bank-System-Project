#pragma once

#include <iostream>
#include "clsScreen.h"
#include "clsUser.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

using namespace std;


class clsTransferScreen : protected clsScreen
{
	

	static string _ReadAccountNumber()
	{
		string AccountNumber1;
		AccountNumber1 = clsInputValidate::ReadString();

		while (!(clsBankClient::IsClientExist(AccountNumber1)))
		{
			cout << "Account Number is Not exists Please enter a valid one ? ";
			cin >> AccountNumber1;
		}
		return AccountNumber1;

	}
	
	static void _PrintClient(clsBankClient Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name   : " << Client.FullName();
		cout << "\nAcc. Number : " << Client.AccountNumber();
		cout << "\nBalance     : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}

public :
	
	static void ShowTransferScreen()
	{
		_DrawScreenHeader("\tTransfer Screen");

		cout << "Please Enter Account Number to Transfer From :";
		string AccountNumber1 = _ReadAccountNumber();
		
			clsBankClient FromClient = clsBankClient::Find(AccountNumber1);
			_PrintClient(FromClient);


		cout << "\nPlease Enter Account Number to Transfer To :";
		string AccountNumber2 = _ReadAccountNumber();

		clsBankClient ToClient = clsBankClient::Find(AccountNumber2);
		_PrintClient(ToClient);

		
		cout << "\nEnter Transfer Amount? ";
		double Amount=clsInputValidate::ReadDblNumber();

		char Answer;
		cout << "\nAre you sure you want to perform this operation ?y/n? ";
		cin >> Answer;

		if (tolower(Answer) == 'y')
		{
			while (!FromClient.Transfer(ToClient, Amount))
			{
				cout << "\nAmount Exceeds the available Balance, Enter another Amount ? ";
				cin >> Amount;


			}
			cout << "\nOperation was done";
		}
		else
		{
			cout << "\nOperation was cancelled";
			return;
		}
		


		_PrintClient(FromClient);

		cout << endl;
		_PrintClient(ToClient);


	}
};

