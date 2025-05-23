#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsMainScreen.h";
#include "clsUser.h";

class clsListUsersScreen : protected clsScreen
{
	static void _PrintUsersInfo(clsUser User)
	{
		cout << setw(8) << left << "" << "| " << setw(15) << left << User.UserName;
		cout << "| " << setw(20) << left << User.FullName();
		cout << "| " << setw(12) << left << User.Phone;
		cout << "| " << setw(20) << left << User.Email;
		cout << "| " << setw(10) << left << User.Password;
		cout << "| " << setw(12) << left << User.Permissions;
	}

public:

	static void ShowUsersList()
	{

		vector<clsUser> vUsers = clsUser::GetUsersList();

		string Title = "User List Screen";
		string SubTitle = "( " + to_string(vUsers.size()) + " ) User(s).";

		clsScreen::_DrawScreenHeader(Title, SubTitle);

		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

		cout << setw(8) << left << "" << "| " << left << setw(15) << "Username";
		cout << "| " << left << setw(20) << "Full Name";
		cout << "| " << left << setw(12) << "Phone";
		cout << "| " << left << setw(20) << "Email";
		cout << "| " << left << setw(10) << "Password";
		cout << "| " << left << setw(12) << "Permission";
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;


		if (vUsers.size() == 0)
		{
			cout << "\n\t\t\t\tNO Users Availble in the system!\n";
		}
		else
		{

			for (clsUser& User : vUsers)
			{
				_PrintUsersInfo(User);
				cout << endl;
			}
		}
		cout << setw(8) << left << "" << "\n\t_______________________________________________________";
		cout << "_________________________________________\n" << endl;

	}


};
