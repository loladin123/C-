/*
 * Class Date, implementation.
 * The next() function in this implementation cannot handle leap years.
 */
#include "stdafx.h"
#include "date.h"
#include <cassert>
#include <ctime>   /* for C routines time and localtime */
#include <iostream>
#include <utility> /* for swap */

using namespace std;

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

int Date::get_year() const {
	return year;
}

int Date::get_month() const {
	return month;
}

int Date::get_day() const {
	return day;
}

void Date::next() {
	switch (get_day()) {
	case 31:
		day = 1;
		if (get_month() == 12)
			++year, month = 1;
		break;
	case 30:
		if (get_month() == 4 || get_month() == 6 || get_month() == 9 || get_month() == 11)
			++month, day = 1;
		else
			++day;
		break;
	case 28:
		if (get_month() == 2)
			++month, day = 1;
		else
			++day;
		break;
	default:
		++day;
	}
}


void print(const Date& d) {
	cout << d.get_year() << "-";
	if (d.get_month() < 10) {
		cout << "0";
	}
	cout << d.get_month() << "-";
	if (d.get_day() < 10) {
		cout << "0";
	}
	cout << d.get_day();
}

bool operator<(const Date& d1, const Date& d2) {
	return (d1.get_year() < d2.get_year()) ||
	(d1.get_year() == d2.get_year() && d1.get_month() < d2.get_month()) ||
	(d1.get_year() == d2.get_year() && d1.get_month() == d2.get_month()
	 && d1.get_day() < d2.get_day());
	
}


int months_to_days(int m) {
	int daysPerMonth[] = { 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
	if (m != 1)
		return daysPerMonth[m - 2];
	else
		return 0;

}
int distance(const Date& d1, const Date& d2) {
	if (d1 < d2)
		return ((365 * d2.get_year()) + months_to_days(d2.get_month()) + d2.get_day()) - ((365 * d1.get_year()) + months_to_days(d1.get_month()) + d1.get_day());
	else
		return ((365 * d1.get_year()) + months_to_days(d1.get_month()) + d1.get_day()) - ((365 * d2.get_year()) + months_to_days(d2.get_month()) + d2.get_day());

}
