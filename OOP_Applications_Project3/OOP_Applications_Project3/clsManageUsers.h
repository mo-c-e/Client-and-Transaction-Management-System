#pragma once
#include <iostream>
#include <iomanip>
#include "clsInputValidate.h"
#include "clsScreen.h"
#include "clsListUsersScreen.h"
#include "clsAddNewUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"
#include "clsFindUserScreen.h"
using namespace std;
class clsManageUsers : protected clsScreen
{
private:
    enum enUsersMenueOptions {
        eListUsers = 1, eAddNewUser = 2, eDeleteUser = 3,
        eUpdateUser = 4, eFindUser = 5,eMainMenu=6
    };

    static short _ReadUserMenuOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }

    static  void _GoBackToUserMenue()
    {
        cout << setw(37) << left << "" << "\n\tPress any key to go back to User Menu...\n";
        system("pause>0");
        ShowUserMenu();
    }

    static void _ShowAllUsersScreen()
    {
        clsListUsersScreen::ShowUsersList();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void _ShowDeleteUserScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
       
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
       
    }

    static void _ShowEndScreen()
    {
        cout << "\nEnd Screen Will be here...\n";

    }

    static void _PerfromUserMenuOption(enUsersMenueOptions UserMenuOption)
    {
        switch (UserMenuOption)
        {
        case enUsersMenueOptions::eListUsers :
        {
            system("cls");
            _ShowAllUsersScreen();
            _GoBackToUserMenue();
            break;
        }
        case enUsersMenueOptions::eAddNewUser :
            system("cls");
            _ShowAddNewUserScreen();
            _GoBackToUserMenue();
            break;

        case enUsersMenueOptions::eDeleteUser :
            system("cls");
            _ShowDeleteUserScreen();
            _GoBackToUserMenue();
            break;

        case enUsersMenueOptions::eUpdateUser:
            system("cls");
            _ShowUpdateUserScreen();
            _GoBackToUserMenue();
            break;

        case enUsersMenueOptions::eFindUser:
            system("cls");
            _ShowFindUserScreen();
            _GoBackToUserMenue();
            break;
        case enUsersMenueOptions::eMainMenu:
        {

        }
        }

    }



public:

    static void ShowUserMenu()
    {
        if (!CheckAccessRights(clsUser::enPermissions::pManageUsers)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\tManage Users Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tManage Users Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Users.\n";
        cout << setw(37) << left << "" << "\t[2] Add New User.\n";
        cout << setw(37) << left << "" << "\t[3] Delete User.\n";
        cout << setw(37) << left << "" << "\t[4] Update User Info.\n";
        cout << setw(37) << left << "" << "\t[5] Find User.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromUserMenuOption((enUsersMenueOptions)_ReadUserMenuOption());
    }
};

