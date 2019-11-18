//All the code here has been given to us except for what is in hte forward slash section.

//example
/////////////////////////////////////////////////////////////////////////////////////////////////
look for something like this and this is where I implemeted the code.
/////////////////////////////////////////////////////////////////////////////////////////////////

#include <Servo.h>
#include <SoftwareSerial.h>
Servo myservo; // create servo object to control a servo
/////////////////////////////////////////////////////////////
SoftwareSerial mySerial(11,9); //sending and recieveing      
/////////////////////////////////////////////////////////////
  int valX;
  int valY;
  int valJB;
  int valBB;
  
  int joypinY = 6;
  int joypinX = 7;
  int joybuttonpin = 12;
  int buttonpin = 13;
  
void setup() {
  //myservo.attach(6); // attatches the servo on pin 6 to the servo object

  pinMode(joybuttonpin, INPUT_PULLUP); //initializing button as input, set the internal pull up resistor, unpressed is HIGH
  pinMode(buttonpin, INPUT);
  mySerial.begin(57600);
  Serial.begin(57600);

}
 /////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() {
  //analogRead() Reads the value from the specified analog pin. 
  valX = analogRead(joypinX); // reads the value of the potentiometer (value between 0 and 1023)
  valY = analogRead(joypinY);
  valJB = digitalRead(joybuttonpin);
  valBB = digitalRead(buttonpin);
  //digitalRead() Reads the value from a specified digital pin, either HIGH or LOW.

Serial.println("bluh");

  valX = map(valX, 0, 1023, 0, 255); // scale it to use it with the servo (value between 0 and 180)
  valY = map(valY, 0, 1023, 0, 255);
  mySerial.print('A');  // this signifies the start of the serial code
  mySerial.print(char(valX)); //we print the values by typecasting it to a char with all mySerial.print()
  mySerial.print(char(valY));
  mySerial.print(char(valJB));
  mySerial.print(char(valBB));
  mySerial.print('Z'); // this signifies the end of the serial code
  delay(15);
  Serial.println("end of function");
 
  ///////////////////////////////////////////////////////////////////////////////////////////////////////// 
  
 }
