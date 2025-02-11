// the number of the LED pin
const int ledPin = 21;  // 16 corresponds to GPIO16
const int Button = 32;

// setting PWM properties
const int freq = 1000;
const int resolution = 8;
 
int buttoncount = 0;
int dutyCycle = 0;

bool buttonstate = false;
bool buttonlaststate = false;

void setup(){
  // attach the channel to the GPIO to be controlled
  ledcAttach(ledPin, freq, resolution);
  pinMode(Button,INPUT);
  Serial.begin(9600);

}
 
void loop(){

  buttonstate = digitalRead(Button);
  if(digitalRead(Button) == LOW && buttonstate != buttonlaststate){
    buttoncount++;    
  }

  if(buttoncount == 6){
    buttoncount = 0;
  }

  dutyCycle = buttoncount * 51;
  Serial.println(buttoncount);


  ledcWrite(ledPin, dutyCycle);   
  buttonlaststate = buttonstate;
}