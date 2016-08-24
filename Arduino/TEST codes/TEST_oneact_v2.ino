
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
  

if (serialData & 1)
  {
    if (ActuatorPosition1 < 50)
      {
        digitalWrite(h1_out1, HIGH);
        digitalWrite(h1_out2, LOW);
        Serial.print("10");
       Serial.print("Actuator retracted EXTEND");
      }
    if (ActuatorPosition1 > 910)
      {
        digitalWrite(h1_out1, LOW);
        digitalWrite(h1_out2, LOW);
        Serial.print("00");
        Serial.print("Actuator extended STAY");
      }
  }
else
  {
    if (ActuatorPosition1 < 50)
      {
        digitalWrite(h1_out1, LOW);
        digitalWrite(h1_out2, LOW);
        Serial.print("00");
        Serial.print("Actuator retracted STAY");
      }
    if (ActuatorPosition1 > 910) 
      {
        digitalWrite(h1_out1, LOW);
        digitalWrite(h1_out2, HIGH);
        Serial.print("01");
        Serial.print("Actuator extended RETRACT");
      }
    }
  }
}

 
  
