#pragma once
#include <sstream>
#include <iostream>
#include <cassert>

const int MIN_DAYS = 0;
const int MAX_DAYS = 2932896;
const int MIN_YEAR = 1970;
const int MAX_YEAR = 9999;
const int QUANTITY_DAYS_LEAP_YEAR = 366;
const int QUANTITY_DAYS_YEAR = 365;
const int QUANTITY_DAYS_FEBRUARY_LEAP_YEAR = 29;
const int QUANTITY_MONTH = 12;
const int WEEKDAY_MIN_DAY = 4;
const int QUANTITY_WEEKDAY = 7;
const int CENTURY = 100;
const int MULTIPLICITY_LEAP_YEAR = 4;
const int MULTIPLICITY_CENTURY_LEAP_YEAR = 400;

enum class Month
{
	JANUARY = 1,
	FEBRUARY,
	MARCH,
	APRIL,
	MAY,
	JUNE,
	JULY,
	AUGUST,
	SEPTEMBER,
	OCTOBER,
	NOVEMBER,
	DECEMBER
	/*JAMAL */
};

enum class WeekDay
{
	SUNDAY = 0,
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY
};

class CDate
{
public:
	CDate(unsigned day, Month month, unsigned year);

	CDate(unsigned timestamp = 0);

	unsigned GetDay() const;

	Month GetMonth() const;

	unsigned GetYear() const;

	WeekDay GetWeekDay() const;

	/*	 возвращает информацию о корректности хранимой даты.
		 Например, после вызова CDate date(99, static_cast<Month>(99), 10983);
	     или после:
	 	 CDate date(1, January, 1970); --date;
		 метод date.IsValid() должен вернуть false;
	*/

	bool IsValid()const;

	CDate& operator++();
	CDate& operator--();

	CDate operator++(int i);
	CDate operator--(int i);

	CDate operator+(int i);
	CDate operator-(int i);
	int operator-(CDate const& date);

	CDate& operator+=(int i);
	CDate& operator-=(int i);

	bool operator==(CDate const& date) const;
	bool operator!=(CDate const& date) const;
	bool operator<=(CDate const& date) const;
	bool operator<(CDate const& date) const;
	bool operator>(CDate const& date) const;
	bool operator>=(CDate const& date) const;

private:
	int m_days;
	bool m_valid;

	unsigned CountQuantityDaysInMonth(Month month) const;
	int CountDaysInYears(int year) const;
	int CountDaysInMonths(Month month, int year) const;
	bool CheckRangeDaysMonth(unsigned day, Month month, unsigned year);
	bool CheckLeapYear(int year) const;
};

std::ostream& operator<<(std::ostream& stream, CDate& date);
std::istream& operator>>(std::istream& stream, CDate& date);
