#pragma once

#include<iostream>
#include<string>
#include "clsString.h"
#include <vector>
#include <fstream>


class clsCurrency
{
private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };
	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float _Rate;


	static clsCurrency _ConvertLineToCurrencyObject(string Line)
	{

		vector<string>vString = clsString::Split(Line, "#//#");
		return clsCurrency(enMode::UpdateMode, vString[0], vString[1], vString[2]
			, stof(vString[3]));

	}

	static string _ConvertCurrencyObjectToLine(clsCurrency Currency, string Separator = "#//#")
	{
		string Line="";
		Line += Currency.Country() + Separator;
		Line += Currency.CurrencyCode() + Separator;
		Line += Currency.CurrencyName() + Separator;
		Line += to_string(Currency.Rate());
		return Line;
	}
	
	static vector<clsCurrency> _LoadCurrenciesDataFromFile()
	{
		vector<clsCurrency> vCurrencies;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);
		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				vCurrencies.push_back(_ConvertLineToCurrencyObject(Line));
			}
			MyFile.close();
		}
		return vCurrencies;

	}

	static void _SaveCurrencyDataToFile(vector<clsCurrency> vCurrency)
	{
		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out | ios::app);
		if (MyFile.is_open())
		{
			for (clsCurrency C : vCurrency)
			{

				string Line = _ConvertCurrencyObjectToLine(C);
				MyFile << Line << endl;
			}
		}
	}

public:

	clsCurrency(enMode Mode, string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return(_Mode == enMode::EmptyMode);
	}

	string Country()
	{
		return _Country;
	}
	string CurrencyCode()
	{
		return _CurrencyCode;
	}
	string CurrencyName()
	{
		return _CurrencyName;
	}

	float Rate()
	{
		return _Rate;
	}

	
	void _Update()
	{
		vector<clsCurrency>vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (C.CurrencyCode() == this->CurrencyCode())
			{
				C = *this ;
				_SaveCurrencyDataToFile(vCurrencies);
				break;
			}
		}
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;

		_Update();
		
	}

	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperAllString(CurrencyCode);
		vector<clsCurrency>vCurrencies=_LoadCurrenciesDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{

			if (clsString::UpperAllString( C.CurrencyCode()) == CurrencyCode)
			{
				return C;
			}
		}
		return _GetEmptyObject();
	}

	static clsCurrency _GetEmptyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

	static clsCurrency FindByCountry(string Country)
	{
		Country = clsString::UpperAllString(Country);
		vector<clsCurrency>vCurrencies = _LoadCurrenciesDataFromFile();

		for (clsCurrency& C : vCurrencies)
		{
			if (clsString::UpperAllString(C.Country()) == Country)
			{
				return C;
			}
		}
		return _GetEmptyObject();
	}

	static bool IsCurrencyExist(string CurrencyCode)
	{
		clsCurrency Currency = FindByCode(CurrencyCode);

		return (!Currency.IsEmpty());

	}

	

	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrenciesDataFromFile();
	}

	bool IsExist()
	{
		return (!this->IsEmpty());
	}

	float ConvertToUSD(float Amount)
	{
		return (float)(Amount /Rate());
	}


	float ConvertToOtherCurrency(float Amount, clsCurrency Currency2)
	{
		if (Currency2.CurrencyCode() == "USD")
		{
			return ConvertToUSD(Amount);
		}

		return (float)ConvertToUSD(Amount) * Currency2.Rate();
	}
	


};



