#pragma once
#include "Global.h"
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUser.h"
#include "clsMainScreen.h"
class clsLogScreen : protected clsScreen
{
	static bool _Login() {
		bool LogInpermission=false;
		string username, passwrod;
		int counter = 0;
		do {
			if (LogInpermission) {
				counter++;
				cout << "Invalid Username/Password\n";
				cout << "You have " << (3 - counter)  <<" Trials to Login " << endl;
			}
			if (counter==3) {
				cout << "\n You are Locked after 3 trials \n\n";
				return false;
			}
			cout << "\nEnter Username : ";
			username = clsInputValidate::ReadString();
			cout << "\nEnter Password : ";
			passwrod = clsInputValidate::ReadString();
			CurrentUser = clsUser::Find(username,passwrod);
			LogInpermission = CurrentUser.IsEmpty();
		} while (LogInpermission);
		
		CurrentUser.RegisterLogIn();
	  	clsMainScreen::ShowMainMenue();
		return true;
	}
public :
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\t Login Screen");

		return _Login();
	}
};

