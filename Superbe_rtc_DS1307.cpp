/*
	Superbe_rtcDS1307.cpp - Library for using DS1307 RTC
	Created by Gael from superbe.be, 23/02/2015
*/

#include "Arduino.h"
#include "Superbe_rtc_DS1307.h"
#include <Wire.h>

Rtc_DS1307::Rtc_DS1307() {
}

void Rtc_DS1307::begin() {
	Wire.begin();
}

void Rtc_DS1307::readTime() {
	Wire.beginTransmission(DS1307_ADDRESS);
	Wire.write(byte(0x00));
	Wire.endTransmission();
	Wire.requestFrom(DS1307_ADDRESS, 3);
	second = _bcdToDec(Wire.read());
	minute = _bcdToDec(Wire.read());
	hour = _bcdToDec(Wire.read() & 0b111111);
}

void Rtc_DS1307::readDateTime() {
	Wire.beginTransmission(DS1307_ADDRESS);
	Wire.write(byte(0x00));
	Wire.endTransmission();
	Wire.requestFrom(DS1307_ADDRESS, 7);
	second = _bcdToDec(Wire.read());
	minute = _bcdToDec(Wire.read());
	hour = _bcdToDec(Wire.read() & 0b111111);
	weekDay = _bcdToDec(Wire.read());
	monthDay = _bcdToDec(Wire.read());
	month = _bcdToDec(Wire.read());
	year = _bcdToDec(Wire.read());
}

void Rtc_DS1307::writeTime(int _hour, int _minute, int _second) {
	Wire.beginTransmission(DS1307_ADDRESS);
	Wire.write(byte(0x00));
	Wire.write(_decToBcd(_second));
	Wire.write(_decToBcd(_minute));
	Wire.write(_decToBcd(_hour));
	Wire.write(byte(0x00));
	Wire.endTransmission();
}

void Rtc_DS1307::writeDateTime(int _year, int _month, int _monthDay, int _weekDay, int _hour, int _minute, int _second) {
	Wire.beginTransmission(DS1307_ADDRESS);
	Wire.write(byte(0x00));
	Wire.write(_decToBcd(_second));
	Wire.write(_decToBcd(_minute));
	Wire.write(_decToBcd(_hour));
	Wire.write(_decToBcd(_weekDay));
	Wire.write(_decToBcd(_monthDay));
	Wire.write(_decToBcd(_month));
	Wire.write(_decToBcd(_year));
	Wire.write(byte(0x00));
	Wire.endTransmission();
}

byte Rtc_DS1307::_bcdToDec(byte val) {
	// convert binary coded decimal to normal decimal numbers
	return ((val/16*10) + (val%16));
}

byte Rtc_DS1307::_decToBcd(byte val) {
  return ((val/10*16) + (val%10));
}