#include <Superbe_rtc_DS1307.h>
#include <Wire.h>

Rtc_DS1307 rtc;

void setup() {
  rtc.begin();
  Serial.begin(9600);
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
