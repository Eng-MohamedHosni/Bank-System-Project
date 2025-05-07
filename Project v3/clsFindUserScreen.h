#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsFindUserScreen :protected clsScreen
{

    static void _PrintUser(clsUser User)
    {
        cout << "\nUser Card:";
        cout << "\n___________________";
        cout << "\nFirstName      : " << User.FirstName;
        cout << "\nLastName       : " << User.LastName;
        cout << "\nFull Name      : " << User.FullName();
        cout << "\nEmail          : " << User.Email;
        cout << "\nPhone          : " << User.Phone;
        cout << "\nUsername       : " << User.UserName;
        cout << "\nPassword       : " << User.Password;
        cout << "\nPermissions     : " << User.Permissions;
        cout << "\n___________________\n";

    }

public :

    static void ShowFindUserScreen()
    {

        _DrawScreenHeader("\tFind User Screen");

        string Username;

        cout << "\nPlease Enter Username: ";

        Username = clsInputValidate::ReadString();

        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose another one: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(Username);

        if (!User.IsEmpty())
        {
            cout << "\nUser Found :-)\n";
        }
        else
        {
            cout << "\nUser Was not Found :-(\n";
        }

        _PrintUser(User);

    }

};

