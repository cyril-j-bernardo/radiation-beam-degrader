int serialData = 0;
const int Wiper1 = A0;
const int h1_out1 = 6;
const int h1_out2 = 7;
const int ErrorFlag1 = 22;
int ErrorFlagState1 = 0;
int ActuatorPosition1 = 0;
//char buffer[] = {' ',' ',' ',' ',' ',' ',' '}; // Receive up to 7 bytes

void setup() 
{
  Serial.begin(9600);
  pinMode(h1_out1, OUTPUT);
  pinMode(h1_out2, OUTPUT);
  pinMode(ErrorFlag1, INPUT);
}


void loop() 
{
/*
 if (Serial.available() > 0) // Wait for characters
 {
 Serial.readBytesUntil('n', buffer, 7);
 int serialData = atoi(buffer);
 }
 //Serial.println(serialData);


 if (Serial.available() > 0) 
 {
 serialstringdata = Serial.readString();
 //int serialData = atoi(serialstringdata);
 }
 Serial.println(serialstringdata);
*/

//ACTUATOR1
  analogReadResolution(10);     //ADC set to 10 bits
  ActuatorPosition1 = analogRead(Wiper1);
  Serial.print("p1");
  Serial.print(ActuatorPosition1);         //print out the Analog value
  ErrorFlagState1 = digitalRead(ErrorFlag1);
  Serial.print("e1");
  Serial.print(ErrorFlagState1);
 
/*
  if (Serial.available() > 0)
   {
    serialData = Serial.read();
    //Serial.print(serialData);
*/

  if (Serial.available() > 0)
  {
   serialData = Serial.parseInt();
   //Serial.print(serialData);
  
  
    if ((serialData == 10) && (ActuatorPosition1 < 60))
    {
     // Serial.print(ActuatorPosition1);
     // Serial.println("OUTPUT 10");
      digitalWrite(h1_out1, HIGH);
      digitalWrite(h1_out2, LOW); 
    }
    if ((serialData == 10) && (ActuatorPosition1 > 910))
    {
      //Serial.print(ActuatorPosition1);
      //Serial.println("OUTPUTa 00");
      digitalWrite(h1_out1, LOW);
      digitalWrite(h1_out2, LOW); 
    }

    if ((serialData == 0) && (ActuatorPosition1 > 910))
    {
     // Serial.print(ActuatorPosition1);
      //Serial.println("OUTPUT 01");
      digitalWrite(h1_out1, LOW);
      digitalWrite(h1_out2, HIGH); 
    }
    if ((serialData == 0) && (ActuatorPosition1 < 60))
    {
      //Serial.print(ActuatorPosition1);
      //Serial.println("OUTPUTb 00");
      digitalWrite(h1_out1, LOW);
      digitalWrite(h1_out2, LOW); 
    }
  }
}


