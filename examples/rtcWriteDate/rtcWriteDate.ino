#include <Superbe_rtc_DS1307.h>
#include <Wire.h>

Rtc_DS1307 rtc;

void setup() {
  Serial.begin(9600);
  rtc.begin();
  rtc.writeDateTime(2015, 2, 23, 1, 23, 28, 30);
}

void loop() {
  rtc.readDateTime();
  Serial.print(rtc.weekDay);
  Serial.print(",");
  Serial.print(rtc.monthDay);
  Serial.print("/");
  Serial.print(rtc.month);
  Serial.print("/");
  Serial.print(rtc.year);
  Serial.print(" ");
  Serial.print(rtc.hour);
  Serial.print(":");
  Serial.print(rtc.minute);
  Serial.print(":");
  Serial.println(rtc.second);
  delay(1000);
}
