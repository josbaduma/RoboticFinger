/*
 * Robotic Finger
 * This program controls three servo motors
 * It moves throw the x and y axys and uses
 * a finger to push a touch screen
 */
#include <Servo.h>

// Declaring the servos
Servo servo_x;
Servo servo_y;
Servo servo_z;

// Initialize variables
int SERVO_X = 9;
int SERVO_Y = 10;
int SERVO_Z = 11;
int UP = 30;
int DOWN = 60;
int incoming = 0; 
String readString;
char dir;
bool r1 = false;

//Initialize the Arduino
void setup() {
  Serial.begin(9600);  
  servo_x.attach(SERVO_X);
  servo_y.attach(SERVO_Y);
  servo_z.attach(SERVO_Z);
  dir = 'u';
}

void loop() {
 
  while (Serial.available()) {
    char c = Serial.read();  //gets one char from serial buffer
    if(r1){
      readString += c;
    } else {
      dir = c;
      r1 = true;
    }
    delay(2);  //slow looping to allow buffer to fill with next character
  }
  //if (readString.length() >0) {
  if(r1) {
    //Serial.println(readString);  //so you can see the captured string 
    if(dir == 'x'){
      int n = readString.toInt();  //convert readString into a number
      readString=""; //empty for next input
      servo_x.write(n);
    } else if(dir == 'y'){
      int n = readString.toInt();  //convert readString into a number
      readString=""; //empty for next input
      servo_y.write(n);
    } else if(dir == 't') {
      servo_z.write(DOWN);
      delay(100);
      servo_z.write(UP);
    } else if(dir == 'd'){
      servo_z.write(DOWN);
    } else if(dir == 'u'){
      servo_z.write(UP);
    }
    r1 = false;
    
  } 
}
