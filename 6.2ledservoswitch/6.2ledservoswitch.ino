#include <ESP32Servo.h>

#define Button  32
#define LED  21

Servo myservo;
// Recommended PWM GPIO pins on the ESP32 include 2,4,12-19,21-23,25-27,32-33
int servoPin = 18;
int pos = 0;

void setup() {
  Serial.begin(115200);
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
  int buttonState = digitalRead(Button);  // อ่านค่าปุ่ม
  Serial.println(buttonState);  // แสดงค่าของปุ่มใน Serial Monitor

  if (buttonState == LOW) {  // เมื่อปุ่มถูกกด (LOW เพราะใช้ pull-up)
    digitalWrite(LED, HIGH);  // เปิดไฟ LED

    // ขยับเซอร์โวจาก 0 ถึง 180 องศาและกลับ
    for (pos = 0; pos <= 180; pos++) {
      myservo.write(pos);
      delay(15);
    }
    for (pos = 180; pos >= 0; pos--) {
      myservo.write(pos);
      delay(15);
    }
  } else {
    digitalWrite(LED, LOW); // ปิดไฟ LED เมื่อปุ่มไม่ถูกกด
  }
}