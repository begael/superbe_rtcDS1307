# superbe_rtcDS1307
Arduino Library for the RTC DS1307
it needs Wire Library

Available:
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
