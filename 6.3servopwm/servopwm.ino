
const int servo = 18;
const int Button = 32;

const int freq = 50;
const int resolution = 8;

int buttoncount = 1;
bool buttonstate = false;
bool buttonlaststate = false;

void setup() {

  Serial.begin(9600);
  
  pinMode(Button, INPUT); 
  pinMode(servo, OUTPUT);  
  ledcAttach(servo, freq, resolution);

}

void loop() {
  int buttonstate = digitalRead(Button);  // อ่านค่าปุ่ม
  Serial.println(buttoncount);  // แสดงค่าของปุ่มใน Serial Monitor

  if (buttonstate == LOW && buttonstate != buttonlaststate) {  
    buttoncount++;  
  }

  if(buttoncount == 1){
    ledcWrite(servo,  13);
  }

  if(buttoncount == 2){
    ledcWrite(servo,19);
  }
  
  if(buttoncount == 3){
    ledcWrite(servo, 26);
  }

  if(buttoncount == 4){
    buttoncount = 1;
  }

  buttonlaststate = buttonstate;

}