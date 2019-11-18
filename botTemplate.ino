//All the code here has been given to us except for what is in hte forward slash section.

//example

/////////////////////////////////////////////
code
//////////////////////////////////////////////
#include <SoftwareSerial.h>
#include <Servo.h>

byte dataVals[6];
byte controllerVals[4];
int failSafe = 1;
int i;
unsigned long t1;
unsigned long t2;
unsigned long t3;
unsigned long t4;
unsigned long t5;
unsigned long t6;
int toggle = 0;
Servo myservo;

SoftwareSerial mySerial(8,9);

void setup()
{
  mySerial.begin(57600);
  Serial.begin(57600);

//  void receiving(int, int); // Receive Function 
}

void loop()
{
 //need to call receiving function after filled in 
/* void recieving(int, int); //check this right after
}

void receiving(int servoValStart, int servoValStop)
{*/
   if(mySerial.available() > 0)       //Get the number of bytes (characters) available for reading from the serial port. This is data arrived and stored in the serial receive buffer (holds 64 bytes).
  {
    t1 = millis();                    //First timeout time check
    dataVals[0] = mySerial.read();
    delay(0);  //Put short delays after each read to allow time for the next byte to appear
    if(dataVals[0] == 'A')
    {
      delay(0);
      for(i = 1; i < 5; i++)          //Reads in the 4 values from the controller
      {
        dataVals[i] = mySerial.read();
        delay(0); //delay()  the program for the amount of time (in milliseconds) specified as parameter. (There are 1000 milliseconds in a second.)
      }
      dataVals[5] = mySerial.read();    //read() reads incoming serial data
      if(dataVals[5] == 'Z')
      {
        failSafe = 0;                //failsafe set to not triggered
        for(i=0;i<4;i++)
        {
          controllerVals[i] = dataVals[i+1]; //becomes the array with the values we care about
        }
      }
      else              //failsafe triggered if 1st byte is not 'A'
      {
        failSafe = 1;
      }
    }
    else                //failsafe triggered if 6th byte is not 'Z'
    {
      failSafe = 1;
    }
  }
  t2 = millis();        //Second timeout time check
  if(t2 - t1 > 200)     //Triggers failsafe if serial data hasn't been received for 200ms
  {
    failSafe = 1;
    Serial.println("also no");
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A5, 0);
  }
  if(failSafe == 0)     //failsafe not triggered
  {
    t4 = millis();
    if(t4 - t3 > 0)
    {
      t3 = millis();
      Serial.println("It works!");
      for(i=0;i<4;i++)      {
        Serial.println(controllerVals[i], DEC);
      }

      //////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      //Put drive code here
      //Use controllerVals array
      
      ///the code within the if and else if statements is what makes the tanker bot move forward, backward, tunr left and right
      if(controllerVals[0] > 200)
      {
        // this will make the tanker bot move forward

        //left side
        analogWrite( A1, 255); //front left #include <SoftwareSerial.h>
#include <Servo.h>

byte dataVals[6];
byte controllerVals[4];
int failSafe = 1;
int i;
unsigned long t1;
unsigned long t2;
unsigned long t3;
unsigned long t4;
unsigned long t5;
unsigned long t6;
int toggle = 0;
Servo myservo;

SoftwareSerial mySerial(8,9);

void setup()
{
  mySerial.begin(57600);
  Serial.begin(57600);

//  void receiving(int, int); // Receive Function 
}

void loop()
{
 //need to call receiving function after filled in 
/* void recieving(int, int); //check this right after
}

void receiving(int servoValStart, int servoValStop)
{*/
   if(mySerial.available() > 0)       //Get the number of bytes (characters) available for reading from the serial port. This is data arrived and stored in the serial receive buffer (holds 64 bytes).
  {
    t1 = millis();                    //First timeout time check
    dataVals[0] = mySerial.read();
    delay(0);  //Put short delays after each read to allow time for the next byte to appear
    if(dataVals[0] == 'A')
    {
      delay(0);
      for(i = 1; i < 5; i++)          //Reads in the 4 values from the controller
      {
        dataVals[i] = mySerial.read();
        delay(0); //delay()  the program for the amount of time (in milliseconds) specified as parameter. (There are 1000 milliseconds in a second.)
      }
      dataVals[5] = mySerial.read();    //read() reads incoming serial data
      if(dataVals[5] == 'Z')
      {
        failSafe = 0;                //failsafe set to not triggered
        for(i=0;i<4;i++)
        {
          controllerVals[i] = dataVals[i+1]; //becomes the array with the values we care about
        }
      }
      else              //failsafe triggered if 1st byte is not 'A'
      {
        failSafe = 1;
      }
    }
    else                //failsafe triggered if 6th byte is not 'Z'
    {
      failSafe = 1;
    }
  }
  t2 = millis();        //Second timeout time check
  if(t2 - t1 > 200)     //Triggers failsafe if serial data hasn't been received for 200ms
  {
    failSafe = 1;
    Serial.println("also no");
    analogWrite(A1, 0);
    analogWrite(A2, 0);
    analogWrite(A3, 0);
    analogWrite(A5, 0);
  }
  if(failSafe == 0)     //failsafe not triggered
  {
    t4 = millis();
    if(t4 - t3 > 0)
    {
      t3 = millis();
      Serial.println("It works!");
      for(i=0;i<4;i++)      {
        Serial.println(controllerVals[i], DEC);
      }

      ///////////////////////////////////////////////////////////////////////////////////////////////
      //Put drive code here
      //Use controllerVals array
      if(controllerVals[0] > 200)
      {
        //move forward

        //left side track of the thanker bot
        analogWrite( A1, 255); //front left track side of the tanker bot as well as the motor
        analogWrite( A2, 0); //back

        //right side 
       analogWrite( A5, 255); //front
       analogWrite( A3, 0); //back
       Serial.println("forwards");
      }
      else if(controllerVals[0] < 50)
      {
        //move backwards

        //left side 
         analogWrite(A1, 0); //front 
         analogWrite(A2, 255); //back

        //right side 
         analogWrite(A5, 0); //front 
         analogWrite(A3,255); // back*/
         Serial.println("backwards");
      }
      else if(controllerVals[1] > 200)
      {
        //clockwise

        //left side
         analogWrite(A1, 255); //front
         analogWrite(A2, 0); //back

         //ride side
         analogWrite(A5, 0); //front
         analogWrite(A3, 255); //back
         Serial.println("turn right");
      }
      else if(controllerVals[1] < 50)
      {
        //counter clock wise
        
        //left side
         analogWrite(A1, 0); //front 
         analogWrite(A2, 255); //back

        //right side
         analogWrite(A5, 255); //front
         analogWrite(A3, 0); //back*/
         Serial.println("turn left");
      }
      else
      {
       analogWrite(A1, 0); //brake dude said by minecraft kid
       analogWrite(A2, 0);
       analogWrite(A3, 0);
       analogWrite(A5, 0);
       Serial.println("stopped");
      }
     /////////////////////////////////////////////////////////////////////////////////////////////////   
      
      t5 = millis();
      if(controllerVals[3] == 0)
      {
        if(t5 - t6 > 500)
        {
          t6 = millis();
          if(toggle == 1)
          {
//            myservo.write(servoValStart); //this line will need to be changed if using servo
            toggle = 0;
          }
          else
          {
//            myservo.write(servoValStop);
            toggle = 1;
          }
        }
      }
    }
  else                 
  {
    Serial.println("no");
    /*analogWrite(6, 0);
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);*/
  }
  delay(10);
  }
}
        analogWrite( A2, 0); //back left

        //right side 
       analogWrite( A5, 255); //front
       analogWrite( A3, 0); //back
       Serial.println("forwards");
      }
      else if(controllerVals[0] < 50)
      {
        //this will meake the tanker bot move backwards

        //this is the left side track of the tanker bot
         analogWrite(A1, 0); //front 
         analogWrite(A2, 255); //back

        //this would be the right sid right side 
         analogWrite(A5, 0); //front right side motor
         analogWrite(A3,255); // back right side of the motor
         Serial.println("backwards");
      }
      else if(controllerVals[1] > 200)
      {
        //clockwise

        //left side
         analogWrite(A1, 255); //front
         analogWrite(A2, 0); //back

         //ride side
         analogWrite(A5, 0); //front
         analogWrite(A3, 255); //back
         Serial.println("turn right");
      }
      else if(controllerVals[1] < 50)
      {
        //counter clock wise
        
        //left side
         analogWrite(A1, 0); //front 
         analogWrite(A2, 255); //back

        //right side
         analogWrite(A5, 255); //front
         analogWrite(A3, 0); //back*/
         Serial.println("turn left");
      }
      else
      {
       analogWrite(A1, 0); //These analogWrite(A#, 0) will allow the tanker bot to break.
       analogWrite(A2, 0);
       analogWrite(A3, 0);
       analogWrite(A5, 0);
       Serial.println("stopped");
      }
     ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
      
      t5 = millis();
      if(controllerVals[3] == 0)
      {
        if(t5 - t6 > 500)
        {
          t6 = millis();
          if(toggle == 1)
          {
//            myservo.write(servoValStart); //this line will need to be changed if using servo
            toggle = 0;
          }
          else
          {
//            myservo.write(servoValStop);
            toggle = 1;
          }
        }
      }
    }
  else                 
  {
    Serial.println("no");
    /*analogWrite(6, 0);
    analogWrite(9, 0);
    analogWrite(10, 0);
    analogWrite(11, 0);*/
  }
  delay(10);
  }
}
