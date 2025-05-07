#pragma once
#include <iostream>
#include <iomanip>
#include <ctime>
#include "clsUtil.h"
#include "clsMainScreen.h"
#include "clsScreen.h"
#include "clsUser.h"
#include "Global.h"

using namespace std;

class clsLoginScreen : protected clsScreen
{

	static bool _Login()
	{
		bool LoginFailed = false;
		int Trials = 3;
		do
		{
			if (LoginFailed)
			{
				Trials--;
				cout << "\nInvalid Username/Password\n";
				cout << "You have " << Trials << " Trials to login.\n";
				if (Trials == 0)
				{
					cout << "\nYou are Locked after " << Trials << " failed trails!\n";
					return 0;
				}
			}

			string Username;
			string Password;

			cout << "\nEnter Username: ";
			Username = clsInputValidate::ReadString();

			cout << "\nEnter Password: ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(Username, Password);

			LoginFailed = CurrentUser.IsEmpty();

		} while (LoginFailed);

		CurrentUser.RegisterLogIn();

		clsMainScreen::ShowMainMenue();
		
		return 1;
	}

public:
	static bool ShowLoginScreen()
	{

		system("cls");
		_DrawScreenHeader("Login Screen");
		return _Login();
	}
};
