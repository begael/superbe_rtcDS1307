#include <Superbe_rtc_DS1307.h>
#include <Wire.h>

Rtc_DS1307 rtc;

void setup() {
  rtc.begin();
  Serial.begin(9600);
}

void loop() {
  rtc.readTime();
  Serial.print(rtc.hour);
  Serial.print(":");
  Serial.print(rtc.minute);
  Serial.print(":");
  Serial.println(rtc.second);
  delay(1000);
}
