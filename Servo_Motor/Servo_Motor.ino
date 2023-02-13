
#include <Servo.h>
Servo servoMain; // Define our Servo
int trigPin = 10;
int echopin = 12;
int distance,pos;
float duration;
float cm;

void setup(){
servoMain.attach(3); // servo on digital pin 10
Serial.begin(9600);  //set the baud rate of serial communication to 9600
pinMode(trigPin, OUTPUT);
pinMode(echopin, INPUT);
}

void loop(){
digitalWrite(trigPin,LOW); //generate square wave at trigger pin
 delayMicroseconds(2);
 digitalWrite(trigPin,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin,LOW);
duration = pulseIn(echopin, HIGH); 
distance=(duration*0.034/2)

         Serial.print("Distance : ");
         Serial.print(distance);
         Serial.println(" cm . ");
 delay(100); 
if(distance<30) 
{ for(pos=0;pos<=110;pos++){
      servoMain.write(pos);
      delay(15);  }
        delay(1000);
        for(pos=110;pos>=0;pos--){
      servoMain.write(pos);
      delay(15);      }
}
else{
servoMain.write(0);
delay(50);}}
