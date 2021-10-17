/*
  AUTHOR: CESAR KRISCHER,
    https://github.com/cesarak2
  DATE: BEGINNING OF 2021
  
  COFFEE CLOCK ARDUINO PROGRAM
  USED FOR REFRESHING TIME/DATE ONLY WHEN PRESSING A BUTTON

  PHYSICAl MODULES USED: LCD SCREEN, PUSH BUTTON, SWITCH ON/OFF AND RTC

  TO SET THE DAY AND TIME, IT WAS USED A THIRD PARTY PROGRAM:
  * Arduino DS3231 Real Time Clock Module Tutorial
  * Crated by Dejan Nedelkovski,
  * www.HowToMechatronics.com
  * DS3231 Library made by Henning Karlsen which can be found and downloaded from his website, www.rinkydinkelectronics.com.

  REFERENCE FOR FIRST DEVELOPMENT:
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button

*/


#include <DS3231.h>        // includes the datetime module

#include <LiquidCrystal.h> // includes the LiquidCrystal Library

DS3231 rtc(SDA, SCL);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Creates an LC object. Parameters: (rs, enable, d4, d5, d6, d7) 

const int buttonPin = 7; // the port number of the pushbutton pin that updates the date/time
const int switchPin = 8; // the port number of the switch for daylight savings
int buttonState = 0; // variable for reading the pushbutton status
int switchState = 0; // variable for reading the switch status

Time t; // this t will be the source of time and date down below.
int hour_to_display = 0;

void setup() {
  rtc.begin(); // Initialize the rtc object
  lcd.begin(16, 2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display } 
  pinMode(buttonPin, INPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(115200);
}

// The program is a constant loop that checks if the button is being pressed and refreshes the datetime t variable.
// The LCD is constantly refreshed with the datetime t, so clicking the button makes them [t and LCD] refresh instantly.
// To avoid updating the daylight savings time twice a year, it was installed a switch on the side of the coffee clock
// that simply adds 1 to the current hour when is on. The t is then displayed on the screen as the new time.

void loop() {
  lcd.setCursor(0, 0);
  lcd.print("Coffee made at  "); //first line of the LCD. Two extra spaces to force the display to always show blank.

  // reads the state of the pushbutton (refresh) and switch (daylight savings) values:
  buttonState = digitalRead(buttonPin);
  switchState = digitalRead(switchPin);

  // checks if the pushbutton is pressed and updates t. If it is, the buttonState is LOW:
  if (buttonState == LOW) {
    t = rtc.getTime();
  }
  // checks for daylight savings and adds (or not) an extra hour to t. Note that
  // this is independent from t being refreshed.
  if (switchState == HIGH) {
    //Serial.print(" switch is on, ");
    hour_to_display = t.hour + 1;
  } else {
    hour_to_display = t.hour;
    //Serial.print(" switch is off, ");
  }
  // this forces cleaning the screen for a variable with one digit that comes after
  // a variable with two digits.
  if (hour_to_display < 10) { // if hour is below 10, add extra 0
    lcd.setCursor(0, 1);
    lcd.print("0");
    lcd.setCursor(1, 1);
    lcd.print(hour_to_display);
  } else {
    lcd.setCursor(0, 1);
    lcd.print(hour_to_display);
  }

  lcd.setCursor(2, 2); // time separation
  lcd.print(":");

  // this forces cleaning the screen for a variable with one digit that comes after
  // a variable with two digits.
  if (t.min < 10) { // if minutes is below 10, add extra 0
    lcd.setCursor(3, 1);
    lcd.print("0");
    lcd.setCursor(4, 1);
    lcd.print(t.min);
  } else {
    lcd.setCursor(3, 1);
    lcd.print(t.min);
  }

  lcd.setCursor(5, 1); // date and time separation
  lcd.print(" on ");

  // this forces cleaning the screen for a variable with one digit that comes after
  // a variable with two digits.
  if (t.mon < 10) { // if month is below 10, add extra 0
    lcd.setCursor(9, 1);
    lcd.print("0");
    lcd.setCursor(10, 1);
    lcd.print(t.mon);
  } else {
    lcd.setCursor(9, 1);
    lcd.print(t.mon);
  }

  lcd.setCursor(11, 1); // date separation
  lcd.print("/");

  // this forces cleaning the screen for a variable with one digit that comes after
  // a variable with two digits.
  if (t.date < 10) { // if day is below 10, add extra 0
    lcd.setCursor(12, 1);
    lcd.print("0");
    lcd.setCursor(13, 1);
    lcd.print(t.date);
  } else {
    lcd.setCursor(12, 1);
    lcd.print(t.date);
  }

  lcd.setCursor(14, 1); // to force a blank space in case of malfunction
  lcd.print("  ");
  //Serial.print(t.hour); //test button
  //Serial.print(" button is not pressed "); //test button
  if (switchState == HIGH) {
    //Serial.print(" dayligth savings on || ");
  } else {
    //Serial.print(" dayligth savings on || ");
  }
  delay(10);
}
