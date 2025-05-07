#pragma once

#include <iostream>
#include "clsDate.h";

using namespace std;

class clsPeriod
{
	clsDate _StartDate;
	clsDate _EndDate;

public:

	clsPeriod(clsDate StartDate, clsDate EndDate)
	{
		_StartDate = StartDate;
		_EndDate = EndDate;
	}

	static bool IsOverlapPeriod(clsPeriod Period1, clsPeriod Period2)
	{
		if (
			clsDate::CompareDates(Period2._StartDate, Period1._EndDate) == clsDate::enDateCompare::Before
			||
			clsDate::CompareDates(Period2._EndDate, Period1._StartDate) == clsDate::enDateCompare::After
			)
			return 0;

		return 1;
	}

	bool IsOverlapPeriod(clsPeriod Period2)
	{
		return IsOverlapPeriod(*this, Period2);
	}

	void Print()
	{
		cout << "Period Start : ";
		_StartDate.Print();
		
		cout << "Period End : ";
		_EndDate.Print();
	}

};

