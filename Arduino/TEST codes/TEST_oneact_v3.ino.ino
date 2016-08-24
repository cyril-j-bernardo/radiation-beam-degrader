
int serialData = 0;
int ActuatorPosition1 = 0;
int ErrorFlagState1 = 0;
const int h1_out1 = 6;
const int h1_out2 = 7;
const int Wiper1 = A0;
const int ErrorFlag1 = 22;

void setup() 
{
 Serial.begin(9600);
  pinMode(h1_out1, OUTPUT);
  pinMode(h1_out2, OUTPUT);
  pinMode(ErrorFlag1, INPUT);
}

void loop() 
{
  //data for position of Actuator 1 on A1
  analogReadResolution(10);     //ADC set to 10 bits
  ActuatorPosition1 = analogRead(Wiper1);
  Serial.print("p1");
  Serial.print(ActuatorPosition1);         //print out the Analog value
  ErrorFlagState1 = digitalRead(ErrorFlag1);
  Serial.print("e1");
  Serial.print(ErrorFlagState1);
  
  
if (Serial.available() > 0)
 {
   serialData = Serial.parseInt();
  
//ACTUATOR 1
if ((serialData & 1) && (ActuatorPosition1 < 50))
 {
   digitalWrite(h1_out1, HIGH);
   Serial.println("1a");
 }
   else 
    {
      digitalWrite(h1_out1, LOW);
      Serial.println("0a");
    }
 // Serial.println(!(serialData & 1));
  if (!(serialData & 1) && (ActuatorPosition1 > 900))
  {
    digitalWrite(h1_out2, HIGH);
    //Serial.println(!(serialData & 1));
    Serial.println("1b");
  }
   else
    {
      digitalWrite(h1_out2, LOW);
      Serial.println("0b");
    }


 }
}
