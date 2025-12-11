#pragma once
#include <iomanip>
# include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsDepositeScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTotalBalancesScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"
using namespace std;
class clsTransactionsScreen : protected clsScreen
{
    enum eTransactionsMenuOptions {
        eDeposit = 1, eWithdraw = 2, eTotalBalance = 3,eTransfer=4, eTransferLog=5,eMainMenu=6
    };
    static short _ReadTransactionsMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 6]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");
        return Choice;
    }
   static void _ShowDepositScreen() {
       clsDepositScreen::ShowDepositScreen();
    }
   static void _ShowWithdrawScreen() {
       clsWithdrawScreen::ShowWithdrawScreen();
    }
   static void _ShowToTalBalancesScreen() {
       clsTotalBalancesScreen::ShowTotalBalances();
    }
   static void _ShowTransferScreen() {
       clsTransferScreen::ShowTransferScreen();
   }
   static void _ShowTransferLogScreen() {
       clsTransferLogScreen::ShowTransferRegisterScreen();
   }
   static void _GoBackToTransactionsMenu() {
       cout << "\nPress any key for Transaction menu return";
       system("pause>0");
       ShowTransactionsMenue();
   }
  static  void _PerfromTransactionsMenueOption(eTransactionsMenuOptions TMainMenueOption)
    {
        switch (TMainMenueOption)
        {
        case eTransactionsMenuOptions::eDeposit :
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransactionsMenu();
            break;
        }
        case eTransactionsMenuOptions::eWithdraw : 
            system("cls");
            _ShowWithdrawScreen();
            _GoBackToTransactionsMenu();
            break;

        case eTransactionsMenuOptions::eTotalBalance :
            system("cls");
            _ShowToTalBalancesScreen();
            _GoBackToTransactionsMenu();
            break;

        case eTransactionsMenuOptions::eTransfer:
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransactionsMenu();
            break;
        case eTransactionsMenuOptions::eTransferLog:
            system("cls");
            _ShowTransferLogScreen();
            _GoBackToTransactionsMenu();
            break;
        case eTransactionsMenuOptions::eMainMenu :
        {

        }

        }

    }
public : 
	static void ShowTransactionsMenue() {
        if (!CheckAccessRights(clsUser::enPermissions::pTranactions)) {
            return;
        }
        system("cls");
        _DrawScreenHeader("\t\tTransaction Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tTransaction Menue\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] Deposit.\n";
        cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
        cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
        cout << setw(37) << left << "" << "\t[4] Transfer.\n";
        cout << setw(37) << left << "" << "\t[5] Transfer Log.\n";
        cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromTransactionsMenueOption((eTransactionsMenuOptions)_ReadTransactionsMainMenueOption());
    }
	
};

