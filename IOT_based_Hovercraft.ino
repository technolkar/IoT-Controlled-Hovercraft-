//This code is written by Technolokar and it is used for making the IoT based Hovercraft using the Nodemcu and Realy module.

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include<Servo.h>

Servo servo;

char auth[] = "XIcNwmqvfflgAwIwB5OVHK2V08S-XcVu"; // unique token taken from blynk app
char ssid[] = "octa145"; // Hotspot Name 
char pass[] = "techo123"; //hotspot password

#define BLYNK_PRINT Serial
#define ENB D3      //ENB
#define MOTORB_1 D4 //IN3
#define MOTORB_2 D5 //IN4
#define MOTORB_3 D1 //IN1
#define MOTORB_4 D2 //IN2
#define Relay_1 D8 //IN1
#define Relay_2 D3 //IN2
#define Relay_3 D6 //IN3
#define Relay_4 D7 //IN4


// SETUP
void setup()
{

  pinMode(ENB, OUTPUT);
  pinMode(MOTORB_1, OUTPUT);
  pinMode(MOTORB_2, OUTPUT);
  pinMode(MOTORB_3, OUTPUT);
  pinMode(MOTORB_4, OUTPUT);
  pinMode(Relay_1,OUTPUT);
  pinMode(Relay_2,OUTPUT);
  pinMode(Relay_3,OUTPUT);
  pinMode(Relay_4,OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
  servo.attach(15);
  
 // digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);
  
  // Start serial communication
  Serial.begin(9600);

  // Connect Blynk
  Blynk.begin(auth, ssid, pass);

}


// FORWARD (Black DC Motor)
BLYNK_WRITE(V4) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving forward");

    digitalWrite(ENB,HIGH);

    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,HIGH);
  }
  else {
    Serial.println("Stop");

    digitalWrite(ENB,LOW);

    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
// BACKWARD (Black DC Motor)
BLYNK_WRITE(V5) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving backward");

    digitalWrite(ENB,HIGH);

    digitalWrite(MOTORB_1,HIGH);
    digitalWrite(MOTORB_2,LOW);
  }
  else {
    Serial.println("Stop");

    digitalWrite(ENB,LOW);

    digitalWrite(MOTORB_1,LOW);
    digitalWrite(MOTORB_2,LOW);
  }
}
// FORWARD (3rd DC Motor)
BLYNK_WRITE(V6) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving forward");

    digitalWrite(ENB,HIGH);

    digitalWrite(MOTORB_3,LOW);
    digitalWrite(MOTORB_4,HIGH);
  }
  else {
    Serial.println("Stop");

    digitalWrite(ENB,LOW);

    digitalWrite(MOTORB_3,LOW);
    digitalWrite(MOTORB_4,LOW);
  }
}
// BACKWARD (3rd DC Motor)
BLYNK_WRITE(V7) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving backward");

    digitalWrite(ENB,HIGH);

    digitalWrite(MOTORB_3,HIGH);
    digitalWrite(MOTORB_4,LOW);
  }
  else {
    Serial.println("Stop");

    digitalWrite(ENB,LOW);

    digitalWrite(MOTORB_3,LOW);
    digitalWrite(MOTORB_4,LOW);
  }
}
//RELAY 1
BLYNK_WRITE(V0) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving backward");

    

    digitalWrite(Relay_1,HIGH);

  }
  else {
    Serial.println("Stop");

 

    digitalWrite(Relay_1,LOW);
    
  }
}
//RELAY 2
BLYNK_WRITE(V1) {
  int button = param.asInt(); // read button
  if (button == 1) {
    digitalWrite(Relay_2,HIGH);

  }
  else {
    digitalWrite(Relay_2,LOW);
    
  }
}
//RELAY 3
BLYNK_WRITE(V2) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving backward");



    digitalWrite(Relay_3,HIGH);

  }
  else {
    Serial.println("Stop");


    digitalWrite(Relay_3,LOW);
    
  }
}
//RELAY 4
BLYNK_WRITE(V3) {
  int button = param.asInt(); // read button
  if (button == 1) {
    Serial.println("Moving backward");



    digitalWrite(Relay_4,HIGH);

  }
  else {
    Serial.println("Stop");



    digitalWrite(Relay_4,LOW);
    
  }
}
// MAIN CODE
void loop()
{
  Blynk.run();
  {
    servo.write(param.asInt());
  }
 BLYNK_WRITE(V2)
 {
  servo.write(0);
 }
 BLYNK_WRITE(V3)
 {
  servo.write(90);
 }
{
  Blynk.run();
}
