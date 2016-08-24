const int analogPin = 0;
int serialData = 0;
int val = 0;
int led = 13;
int state = 0;

void setup() {
 Serial.begin(9600);  
 pinMode(led, OUTPUT); 
}

void loop() {
  if (Serial.available() > 0 ){
  serialData = Serial.read();
   if (serialData == 'a'){
     val = analogRead(analogPin);
     Serial.println(val);
   }
   else if (serialData == 'b'){
     state = !state;
     digitalWrite(led, state);
   } 
  }
}
