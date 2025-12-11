#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
class clsUpdateRateScreen : protected clsScreen
{
private :
	static void _CurrencyCard(clsCurrency Currency) {
		cout << "\nCurrency Card:\n";
		cout << "_____________________________\n";
		cout << "\nCountry    : " << Currency.Country();
		cout << "\nCode       : " << Currency.CurrencyCode();
		cout << "\nName       : " << Currency.CurrencyName();
		cout << "\nRate(1$) = : " << Currency.Rate();

		cout << "\n_____________________________\n";

	}
public:
	static void ShowUpdateRateScreen() {
		char choice = 'y';
		_DrawScreenHeader("\t  Update Rate Screen");
		cout << "Please Enter Currency Code ?";
		string CurrenyCode = clsInputValidate::ReadString();
		clsCurrency user1 = clsCurrency::FindByCode(CurrenyCode);
		if (!user1.IsEmpty()) {
			_CurrencyCard(user1);
			cout << "\nAre You Sure You Want To Update The Rate Of This Currency ? y/n ";
			cin >> choice;
			if (choice == 'y' || choice == 'Y') {
				cout << "\nUpdate Currency Rate : " << endl;
				cout << "---------------------------\n";
				cout << "Enter New Rate : ";
				float NewRate = clsInputValidate::ReadFloatNumber();
				user1.UpdateRate(NewRate);
				cout << "\nCurrency Rate Updated Successfully :-)\n";
				_CurrencyCard(user1);
			}
				
		}
		else {
			cout << "\nNot Found Currency ";
		}
	}
};

