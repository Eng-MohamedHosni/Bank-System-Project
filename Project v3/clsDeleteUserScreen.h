#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsPerson.h"
#include "clsUser.h"
#include "clsInputValidate.h"

class clsDeleteUserScreen :protected clsScreen
{

private:

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

public:
    static void ShowDeleteUserScreen()
    {

        _DrawScreenHeader("\tDelete User Screen");

        string Username = "";

        cout << "\nPlease Enter Username: ";
        Username = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(Username))
        {
            cout << "\nUsername is not found, choose another one: ";
            Username = clsInputValidate::ReadString();
        }

        clsUser User = clsUser::Find(Username);
        
        _PrintUser(User);

        cout << "\nAre you sure you want to delete this User y/n? ";

        char Answer = 'n';
        cin >> Answer;

        if (Answer == 'y' || Answer == 'Y')
        {


            if (User.Delete())
            {
                cout << "\nUser Deleted Successfully :-)\n";
                _PrintUser(User);
            }
            else
            {
                cout << "\nError User Was not Deleted\n";
            }
        }
    }

};

