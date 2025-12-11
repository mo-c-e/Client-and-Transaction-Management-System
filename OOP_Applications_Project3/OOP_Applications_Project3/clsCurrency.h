#pragma once
#include "iostream"
#include <vector>
#include <fstream>
#include "clsString.h"
using namespace std;
class clsCurrency
{
private : 
	enum enMode {
		EmptyMode = 0 ,UpdateMode = 1
	};
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;
	clsCurrency(enMode Mode, string Country, string Currencycode, string CurrencyName, float Rate) {
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = Currencycode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}
	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{
		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.Country() + Seperator;
		stCurrencyRecord += Currency._CurrencyCode + Seperator;
		stCurrencyRecord += Currency._CurrencyName + Seperator;
		stCurrencyRecord += to_string(Currency._Rate);
		return stCurrencyRecord;
	}
	static clsCurrency _ConvertLinetoCurrencyObject(string line, string sep = "#//#") {
		vector <string> Text = clsString::Split(line, sep);
		return clsCurrency(enMode::UpdateMode, Text[0], Text[1], Text[2], stod(Text[3]));
	}
	static vector <clsCurrency>  _LoadCurrencyDataFromFile() {
		vector <clsCurrency> vCurrencys;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencys;


	}
	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrency) {

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		if (MyFile.is_open())
		{
			string DataLine;
			for (clsCurrency C : vCurrency)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;
			}

			MyFile.close();

		}
	}
	void _Update() {
		vector <clsCurrency> vCurrency = _LoadCurrencyDataFromFile();
		for (int i = 0; i < vCurrency.size(); i++) {
			if (vCurrency[i]._CurrencyCode == _CurrencyCode) {
				vCurrency[i] = *this;
				break;
			}
		}
		_SaveCurrencyDataToFile(vCurrency);
	}
	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}
public : 
	
	bool IsEmpty() {
		return(_Mode==enMode::EmptyMode);
	}
	string Country() {
		return _Country;
	}
	string CurrencyCode() {
		return _CurrencyCode;
	}
	string CurrencyName() {
		return _CurrencyName;
	}
	float Rate() {
		return _Rate;
	}
	void UpdateRate(float NewRate) {
		_Rate = NewRate;
		_Update();
	}
	static clsCurrency FindByCode(string CurrencyCode) {
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.CurrencyCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}
		return _GetEmptyCurrencyObject();
	}
	static clsCurrency FindByCountry(string Country) {
		Country = clsString::UpperAllString(Country);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::UpperAllString(Currency.Country()) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();
	}
	static bool IsCurrencyExsit(string CurrencyCode) {
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.IsEmpty());
	}
	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencyDataFromFile();
	}
	float ConvertToUSD(float Amount)
	{
		return (float)(Amount / Rate());
	}
	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		float AmountInUSD = ConvertToUSD(Amount);

		if (Currency2.CurrencyCode() == "USD")
		{
			return AmountInUSD;
		}

		return (float)(AmountInUSD * Currency2.Rate());

	}

};

