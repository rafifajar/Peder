#include <Servo.h>

Servo myservo;

int pos = 0;    // variable to store the servo position
int isi = 4;

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}


void loop(){
//if (Serial.available() > 0) {
  //isi = Serial.parseInt();
  //Serial.println(isi);
    if (isi == 1) {
      for (pos = 20; pos < 40; pos += 1) // goes from 0 degrees to 180 degrees
      { // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      delay(1000);
      for (pos = 40; pos >= 20; pos -= 1) // goes from 180 degrees to 0 degrees
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      isi = 0;
    }
    if (isi == 2) {
      for (pos = 0; pos < 50; pos += 1) // goes from 0 degrees to 180 degrees
      { // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      delay(1000);
      for (pos = 50; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      isi = 0;
    }
    if (isi == 3) {
      for (pos = 0; pos < 60; pos += 1) // goes from 0 degrees to 180 degrees
      { // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      delay(1000);
      for (pos = 60; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(5);                       // waits 15ms for the servo to reach the position
      }
      isi = 0;
    }
    if (isi == 4) {
      for (pos = 0; pos < 40; pos += 1) // goes from 0 degrees to 180 degrees
      { // in steps of 1 degree
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(1);                       // waits 15ms for the servo to reach the position
      }
      delay(5000);
      for (pos = 40; pos >= 0; pos -= 1) // goes from 180 degrees to 0 degrees
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(1);                       // waits 15ms for the servo to reach the position
      }
      isi = 0;
    }
//} 
  //else {
    //isi = 0;
  //}
}
