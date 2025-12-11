#pragma once
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsListCurrencies.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateRateScreen.h"
#include "clsCurrencyCalculator.h"
#include <iomanip>
class clsCurrencyExchangeScreen : protected clsScreen
{
    enum eCurrencyExchangeMenuOptions {
        eListCurrencies = 1, eFindCurrency = 2, eUpdateRate = 3, eCurrnecyCalculator = 4,eMainMenu = 5
    };
    static short _ReadCurrencyExchangeMainMenueOption()
    {
        cout << setw(37) << left << "" << "Choose what do you want to do? [1 to 5]? ";
        short Choice = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");
        return Choice;
    }
    static void _ShowListCurrencies() {
        clsListCurrencies::ShowCurrenciesListScreen();
    }
    static void _ShowFindCurrency() {
        clsFindCurrencyScreen::ShowFindCurrencyScreen();
    }
    static void _ShowUpdateRate(){
        clsUpdateRateScreen::ShowUpdateRateScreen();
        }
    static void _ShowCurrencyCalculator() {
        clsCurrencyCalculator::ShowCurrencyCalculatorScreen();
    }
    static void _GoBackToCurrencyExchangeMenu() {
        cout << "\nPress any key for Currency Exchange menu return";
        system("pause>0");
        ShowCurrencyExchangeMenu();
    }
    static  void _PerfromCurrencyExhangeMenuOption(eCurrencyExchangeMenuOptions Options)
    {
        switch (Options)
        {
        case eCurrencyExchangeMenuOptions::eListCurrencies:
        {
            system("cls");
            _ShowListCurrencies();
            _GoBackToCurrencyExchangeMenu();
            break;
        }
        case eCurrencyExchangeMenuOptions::eFindCurrency:
            system("cls");
            _ShowFindCurrency();
            _GoBackToCurrencyExchangeMenu();
            break;

        case eCurrencyExchangeMenuOptions::eUpdateRate:
            system("cls");
            _ShowUpdateRate();
            _GoBackToCurrencyExchangeMenu();
            break;

        case eCurrencyExchangeMenuOptions::eCurrnecyCalculator:
            system("cls");
            _ShowCurrencyCalculator();
            _GoBackToCurrencyExchangeMenu();
            break;
      
        case eCurrencyExchangeMenuOptions::eMainMenu:
        {

        }

        }

    }
public:
    static void ShowCurrencyExchangeMenu() {
       /* if (!CheckAccessRights(clsUser::enPermissions::pExchangeCurrency)) {
            return;
        }*/
        system("cls");
        _DrawScreenHeader("Currancy Exchange Main Screen");

        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menu\n";
        cout << setw(37) << left << "" << "===========================================\n";
        cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
        cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
        cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
        cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfromCurrencyExhangeMenuOption((eCurrencyExchangeMenuOptions)_ReadCurrencyExchangeMainMenueOption());
    }
};

