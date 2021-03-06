# COFFEE CLOCK
Tired of not knowing when the last pot of coffee was made,
I developed a clock that only refreshes when a button is pressed.

A button on the top of the device sends the order to refresh the time displayed
on the LCD display, that will be frozen until the button is pressed again.
A side switch changes the time to account for daylight savings.

## Components
### Electronics
* Arduino Uno (_Miuzei Super Starter Kit_)
* DateTime Module (_WayinTop 2pcs DS3231 AT24C32 IIC RTC_)
* Push button (_SMAKN Big Button Color Button Module_)
* LCD (_HiLetgo 2pcs HD44780 1602 LCD Display Module DC 5V 16x2 Character LCM Blue Blacklight_)
* Switch on/off (_Gikfun MTS102 2 Position 3 Pins Mini Toggle Switch_)

### 3D printing
The case and lid were printed on a _CREALITY ENDER-3 V2 3D PRINTER_ using a
filament _PSG PLA+ 1.75MM GRAY_.

### Modeling
The case and lid were modeled using Blender (https://www.blender.org) for MacOS.

## Assembly
The wires and components were either soldered or cramped together:
![assembly diagram showing where to connect components and using which ports](https://github.com/cesarak2/coffeeclock/blob/main/schematics_CoffeClock.png?raw=true)

## Software
* The date and time was set up using a program from www.HowToMechatronics.com by Dejan Nedelkovski.
* The final code was made using the Arduino software (_https://www.arduino.cc/en/software_) in C++ and uploaded to the Arduino controller via USB.
