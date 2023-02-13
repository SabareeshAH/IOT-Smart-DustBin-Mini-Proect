#include <LiquidCrystal.h>

LiquidCrystal lcd(6 , 7, 5, 4, 3, 2);
const int trigPin = 11;
const int echoPin = 10;
long duration;
int distanceCm, distanceInch, fill;

void setup() {
  
lcd.begin(16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);

Serial.begin(9600);
}

void loop() {
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);
distanceCm= duration*0.034/2;
distanceInch = duration*0.0133/2;
fill=1;
fill=(distanceCm)*100;
fill/=30;
fill-=100;

if(fill<0){
  fill*=-1;
}

         Serial.print("Distance : ");
         Serial.print(distanceCm);
         Serial.print(" cm .    Level : ");
         Serial.println(fill);
delay(2000);

lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
lcd.print("SMART DUSTBIN");
delay(10);
lcd.setCursor(0,1);
lcd.print("LEVEL: ");
lcd.print(fill);
lcd.print("%");
delay(10);

}
