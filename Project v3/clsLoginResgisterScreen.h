#pragma once
#include"clsScreen.h"
#include"clsUser.h"
#include<iomanip>
#include"clsString.h"

#include"clsUser.h"


class clsLoginResgisterScreen :protected clsScreen
{


	static void _PrintLoginRecordPart(clsUser::stRegisterRecord Record)
	{
		
		cout <<setw(10)<<"" << "| " << setw(25) << left << Record.DateTime;
		cout << "| " << setw(25) << left << Record.UserName;
		cout << "| " << setw(25) << left << Record.Password;
		cout << "| " << setw(25) << left << Record.Permissions;
	}

public:

	static void ShowLoginRegisterScreen()
	{
		if (!CheckAccessRights(clsUser::pLoginRegisters))
		{
			return;
		}

		_DrawScreenHeader("\tLogin Register Screen");

		cout <<setw(10)<<"" << "----------------------------------------------------------------------------------------------\n";
		cout <<setw(10)<<"" << "| " << setw(25) << left << "Date/Time";
		cout << "| " << setw(25) << left << "UserName";
		cout << "| " << setw(25) << left << "Password";
		cout << "| " << setw(25) << left << "Permissions";
		cout << setw(12) << "" << "----------------------------------------------------------------------------------------------\n";

		vector<clsUser::stRegisterRecord>vRegister =clsUser::_GetLoginRegisterList();

		for (clsUser::stRegisterRecord& R : vRegister)
		{
			_PrintLoginRecordPart(R);
			cout << endl;
		}
	}
	
};

