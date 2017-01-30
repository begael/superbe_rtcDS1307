/*
	Superbe_rtc_DS1307.h - Library for using DS1307 RTC
	Created by Gael from superbe.be, 23/02/2015
*/

#ifndef Superbe_rtc_DS1307_h
#define Superbe_rtc_DS1307_h

#define DS1307_ADDRESS 0x68

#include "Arduino.h"

class Rtc_DS1307 {
	public:
		Rtc_DS1307();
		void begin();
		void readTime();
		void readDateTime();
		void writeTime(int _hour, int _minute, int _second);
		void writeDateTime(int _year, int _month, int _monthDay, int _weekDay, int _hour, int _minute, int _second);
		int second;
		int minute;
		int hour;
		int weekDay;
		int monthDay;
		int month;
		int year;		
	private:
		byte _bcdToDec(byte val);
		byte _decToBcd(byte val);
};

#endif