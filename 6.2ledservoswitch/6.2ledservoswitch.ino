#include <ESP32Servo.h>

#define Button  32
#define LED  21

Servo myservo;
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33
int servoPin = 18;
int pos = 0;

int buttoncount = 0;

bool buttonstate = false;
bool buttonlaststate = false;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  pinMode(Button, INPUT_PULLUP); // set arduino pin to input mode
  pinMode(LED, OUTPUT);  // set arduino pin to output mode

}
// void loop() {
//   for (pos = 0; pos <= 180; pos += 1) {
//     myservo.write(pos);
//     delay(15);
//   }
//   for (pos = 180; pos >= 0; pos -= 1) {
//     myservo.write(pos);
//     delay(15);
//   }
// }

void loop() {
  int buttonstate = digitalRead(Button);  // อ่านค่าปุ่ม
  Serial.println(buttoncount);  // แสดงค่าของปุ่มใน Serial Monitor


  if (buttonstate == LOW && buttonstate != buttonlaststate) {  
    buttoncount++;  
  }

  if(buttoncount == 1){
    digitalWrite(LED, HIGH);  
    myservo.write(180);
  }else{
    digitalWrite(LED, LOW);
    myservo.write(0);
  }
  
  if(buttoncount == 2){
    buttoncount = 0;
  }

  buttonlaststate = buttonstate;

}
