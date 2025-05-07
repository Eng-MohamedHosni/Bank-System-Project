#pragma once

#include <iostream>
#include <iomanip>
#include "clsScreen.h";
#include "clsInputValidate.h";
#include "clsDepositScreen.h";
#include "clsWithdrawScreen.h";
#include "clsTotalBalancesScreen.h";
#include "clsListUsersScreen.h";
#include "clsAddNewUserScreen.h";
#include "clsDeleteUserScreen.h";
#include "clsUpdateUserScreen.h";
#include "clsFindUserScreen.h";

using namespace std;


class clsManageUsersScreen : protected clsScreen
{
	static short _ReadManageUsersOption()
	{
		cout << setw(37) << left << "" << "Choose what do you wanna do [1 to 6] ? ";

		short Choice = clsInputValidate::ReadIntNumberBetween(1, 6);

		return Choice;
	}

	enum _enManageUsersOptions {
		eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
		eUpdateUser = 4, eFindUser = 5, eMainMenu = 6 
	};

	static void _ShowListUsersScreen()
	{
		//cout << "\nList Users Screen Will Be Here!\n";
		clsListUsersScreen::ShowUsersList();

	}

	static void _ShowAddNewUserScreen()
	{
		//cout << "\nAdd New User Screen Will Be Here!\n";
		clsAddNewUserScreen::ShowAddNewClientScreen();
	}

	static void _ShowDeleteUserScreen()
	{
		//cout << "\nDelete User Screen Will Be Here!\n";
		clsDeleteUserScreen::ShowDeleteUserScreen();

	}

	static void _ShowUpdateUserScreen()
	{
		//cout << "\nUpdate User  Screen Will Be Here!\n";
		clsUpdateUserScreen::ShowUpdateClientScreen();

	}

	static void _ShowFindUserScreen()
	{
		//cout << "\nFind User Screen Will Be Here!\n";
		clsFindUserScreen::ShowFindUserScreen();

	}

	static void _GoBackToManageUsersScreen()
	{
		cout << "\n\nPress Any Key To go Back To Manage Users Screen\n";
		system("pause>0");
		ShowManageUsersScreen();
	}
	

	static void _PerformManageUsersOptions(_enManageUsersOptions ManageUsersOptions)
	{
		switch (ManageUsersOptions)
		{
		case clsManageUsersScreen::eListUsers:
			system("cls");
			_ShowListUsersScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eAddNewUser:
			system("cls");
			_ShowAddNewUserScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eDeleteUser:
			system("cls");
			_ShowDeleteUserScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eUpdateUser:
			system("cls");
			_ShowUpdateUserScreen();
			_GoBackToManageUsersScreen();
			break;
		case clsManageUsersScreen::eFindUser:
			system("cls");
			_ShowFindUserScreen();
			_GoBackToManageUsersScreen();
				break;
		case clsManageUsersScreen::eMainMenu:
			break;
		default:
			break;
		}
	}

public:
	static void ShowManageUsersScreen()
	{
		system("cls");

		if (!CheckAccessRights(clsUser::enPermissions::pManageUsers))
		{
			return;
		}

		_DrawScreenHeader("\t Manage Users Screen");

		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t\t   Manage Users Menu\n";
		cout << setw(37) << left << "" << "===========================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "===========================================\n";


		_PerformManageUsersOptions((_enManageUsersOptions)_ReadManageUsersOption());
	}


};

