//intializes all the integers used in the program as 0
//serialData is the integer for the data being recieved from 
//the labview GUI
//from actuator 1 to actuator 8
int serialData = 0;
int ActuatorPosition1 = 0;
int ActuatorPosition2 = 0;
int ActuatorPosition3 = 0;
int ActuatorPosition4 = 0;
int ActuatorPosition5 = 0;
int ActuatorPosition6 = 0;
int ActuatorPosition7 = 0;
int ActuatorPosition8 = 0;

//initializing ErrorFlag states for each actuator as an integer 
//and intializing the starting values to 0
//we need 8 for each actuator
int ErrorFlagState1 = 0;
int ErrorFlagState2 = 0;
int ErrorFlagState3 = 0;
int ErrorFlagState4 = 0;
int ErrorFlagState5 = 0;
int ErrorFlagState6 = 0;
int ErrorFlagState7 = 0;
int ErrorFlagState8 = 0;

//assigning the Digital I/O pins used an corresponding pin on the Arduino
//each Actuator needs TWO dedicated output pins
const int h1_out1 = 4;
const int h1_out2 = 5;
const int h2_out1 = 6;
const int h2_out2 = 7;
const int h3_out1 = 8;
const int h3_out2 = 9;
const int h4_out1 = 10;
const int h4_out2 = 11;
const int h5_out1 = 12;
const int h5_out2 = 13;
const int h6_out1 = 14;
const int h6_out2 = 15;
const int h7_out1 = 16;
const int h7_out2 = 17;
const int h8_out1 = 18;
const int h8_out2 = 19;

//The input analog pin coming from each actuator
//this is WIPER from the internal potentiometer on the actuator
//used to read the position of the Actuator
//we need 8 analog pins as well, one for each actuator
const int Wiper1 = A0;
const int Wiper2 = A1;
const int Wiper3 = A2;
const int Wiper4 = A3;
const int Wiper5 = A4;
const int Wiper6 = A5;
const int Wiper7 = A6;
const int Wiper8 = A7;

//The digital I/O's from the Arduino used for the ErrorFlag output
//this is coming from the H-bridge errorflag and going to the RED LED
//on the PCB and the errorflag on the labview GUI
//need 8 dedicated output pins for each actuator
const int ErrorFlag1 = 22;
const int ErrorFlag2 = 24;
const int ErrorFlag3 = 26;
const int ErrorFlag4 = 29;
const int ErrorFlag5 = 30;
const int ErrorFlag6 = 32;
const int ErrorFlag7 = 34;
const int ErrorFlag8 = 36;

//where the program setup begins
void setup() 
{
  
  Serial.begin(9600);
  //setting the digital I/O pins for the h-bridge OUTPUTS
  pinMode(h1_out1, OUTPUT);
  pinMode(h1_out2, OUTPUT);
  pinMode(h2_out1, OUTPUT);
  pinMode(h2_out2, OUTPUT);
  pinMode(h3_out1, OUTPUT);
  pinMode(h3_out2, OUTPUT);
  pinMode(h4_out1, OUTPUT);
  pinMode(h4_out2, OUTPUT);
  pinMode(h5_out1, OUTPUT);
  pinMode(h5_out2, OUTPUT);
  pinMode(h6_out1, OUTPUT);
  pinMode(h6_out2, OUTPUT);
  pinMode(h7_out1, OUTPUT);
  pinMode(h7_out2, OUTPUT);
  pinMode(h8_out1, OUTPUT);
  pinMode(h8_out2, OUTPUT);

//setting the H-bridge ErrorFlag pins as INPUTS
  pinMode(ErrorFlag1, INPUT);
  pinMode(ErrorFlag2, INPUT);
  pinMode(ErrorFlag3, INPUT);
  pinMode(ErrorFlag4, INPUT);
  pinMode(ErrorFlag5, INPUT);
  pinMode(ErrorFlag6, INPUT);
  pinMode(ErrorFlag7, INPUT);
  pinMode(ErrorFlag8, INPUT);
}

//where the program actually begins
void loop() 
{
//***ACTUATOR1************************************************************************************
//ActuatorPosition1 is the integer holding the position of Actuator 1
//this is printed with a 'p1' in front of the actuator position number so 
//that we can differentiate it from the rest of the other actuators in labview
//KNOW THAT THIS IS EXTREMELY NECCESSARY
  analogReadResolution(10);     //ADC set to 10 bits
  ActuatorPosition1 = analogRead(Wiper1);
  Serial.print("p1");                      //p1 for labview reading purposes
  Serial.print(ActuatorPosition1);         //print out the actuator position Analog value
//ErrorFlagState1 holds the digital output from the H-bridge and is outputting that from 
//the arduino
//we print the 'e1' in front so that we are able to differentiate from
//the rest of the actuators in Labview
  ErrorFlagState1 = digitalRead(ErrorFlag1);
  Serial.print("e1");                      //e1 for labview reading purposes
  Serial.print(ErrorFlagState1);           //print out ErrorFlag digital value for Actuator 1

  



//***ACTUATOR2************************************************************************************
//the rest of the Actuator's will have the same exact code as actuator 1 
//but with differnt 'p#' printed out in front of the Actuator Position
//this is so that when labview reads the data for the Actuator Position, it will be able to 
//know which Actuator position it belongs to and OUTPUT to the GUI accordingly
  analogReadResolution(10);                //ADC set to 10 bits
  ActuatorPosition2 = analogRead(Wiper2);
  Serial.print("p2");                      //p2 for labview reading purposes
  Serial.print(ActuatorPosition2);         //print out the Analog value
  ErrorFlagState2 = digitalRead(ErrorFlag2);
  Serial.print("e2");                      //e2 for labview reading purposes
  Serial.print(ErrorFlagState2);           //print out ErrorFlag digital value for Actuator 2
  
//***ACTUATOR3************************************************************************************
  analogReadResolution(10);                //ADC set to 10 bits
  ActuatorPosition3 = analogRead(Wiper3);
  Serial.print("p3");                      //p3 for labview reading purposes
  Serial.print(ActuatorPosition3);         //print out the Analog value for Actuator 3
  ErrorFlagState3 = digitalRead(ErrorFlag3);
  Serial.print("e3");                      //e3 for labview reading purposes
  Serial.print(ErrorFlagState3);           //print out ErrorFlag digital value for Actuator 3
  
//***ACTUATOR4*************************************************************************************
  analogReadResolution(10);                //ADC set to 10 bits
  ActuatorPosition4 = analogRead(Wiper4);
  Serial.print("p4");
  Serial.print(ActuatorPosition4);         //print out the Analog value
  ErrorFlagState4 = digitalRead(ErrorFlag4);
  Serial.print("e4");
  Serial.print(ErrorFlagState4);  

  //ACTUATOR5************************************************************************************
  analogReadResolution(10);                //ADC set to 10 bits
  ActuatorPosition5 = analogRead(Wiper5);
  Serial.print("p5");
  Serial.print(ActuatorPosition5);         //print out the Analog value
  ErrorFlagState5 = digitalRead(ErrorFlag5);
  Serial.print("e5");
  Serial.print(ErrorFlagState5);

//ACTUATOR6************************************************************************************
  analogReadResolution(10);                //ADC set to 10 bits
  ActuatorPosition6 = analogRead(Wiper6);
  Serial.print("p6");
  Serial.print(ActuatorPosition6);         //print out the Analog value
  ErrorFlagState6 = digitalRead(ErrorFlag6);
  Serial.print("e6");
  Serial.print(ErrorFlagState6);

//ACTUATOR7************************************************************************************
  analogReadResolution(10);                //ADC set to 10 bits
  ActuatorPosition7 = analogRead(Wiper7);
  Serial.print("p7");
  Serial.print(ActuatorPosition7);         //print out the Analog value
  ErrorFlagState7 = digitalRead(ErrorFlag7);
  Serial.print("e7");
  Serial.print(ErrorFlagState7);

  //ACTUATOR8************************************************************************************
  analogReadResolution(10);                //ADC set to 10 bits
  ActuatorPosition8 = analogRead(Wiper8);
  Serial.print("p8");
  Serial.print(ActuatorPosition8);         //print out the Analog value
  ErrorFlagState8 = digitalRead(ErrorFlag8);
  Serial.print("e8");
  Serial.println(ErrorFlagState8);
  

  /*
  //SEND OUT ACTUATOR 1
    if ((serialData == '1') && (ActuatorPosition1 < 30) && (ActuatorPosition2 < 30)){ 
      digitalWrite(h1_out1, HIGH);
      digitalWrite(h1_out2, LOW);
      digitalWrite(h2_out1, LOW);
      digitalWrite(h2_out2, LOW);
      
      //state = !state;
      //digitalWrite(led, state);
      //Serial.println(" Actuator1 EXTEND");
    }
    if ((serialData == '1') && (ActuatorPosition1 < 30) && (ActuatorPosition2 > 900)){
      digitalWrite(h1_out1, HIGH);
      digitalWrite(h1_out2, LOW);
      digitalWrite(h2_out1, LOW);
      digitalWrite(h2_out2, HIGH);
      
    }
    //SEND OUT ACTUATOR 2
     if ((serialData == '2') && (ActuatorPosition1 < 30) && (ActuatorPosition2 < 30)){
      digitalWrite(h2_out1, HIGH);
      digitalWrite(h1_out2, LOW);
     }
     if ((serialData == '2') && (ActuatorPosition1 > 900) && (ActuatorPosition2 < 30)){
      digitalWrite(h2_out1, HIGH);
      digitalWrite(h1_out2, LOW);
      digitalWrite(h1_out1, LOW);
      digitalWrite(h1_out2, HIGH);
     }
*/


/*
if (serialData & 1)
  {
    if (ActuatorPosition1 < 30)
      {
      digitalWrite(h1_out1, HIGH);
      digitalWrite(h1_out2, LOW);
      }
    else if (ActuatorPosition1 > 900)
      {
      digitalWrite(h1_out1, LOW);
      digitalWrite(h1_out2, LOW);
      }

  }
else 
  {
    
  }
*/

//This portion allows the 'thickness data' sent from Labview GUI through the Serial port
//to be read by the arduino(hence the > 0, it will only read when data is available)
//"Serial.parseInt" parses the String recieved from Labview to become an integer
//so that Arduino can use the number
if (Serial.available() > 0)
{
  serialData = Serial.parseInt();


//****ACTUATOR 1************************************************************************************
//This logic is based off of digital logic. *You can find more info on this in the word doc*
//Basically it is outputting all the possible logics to the H-bridge to control the actuator's
//position(extend,retract,hold)
//if the "thickness data" recieved from labview is "AND" with a '1', and it is true and the 
//actuatorposition is less than 30(meaning it is retracted) then it will print out a logic '1'(HIGH)
//if this is false, then it will print out a logic '0'(LOW)
  if ((serialData & 1) && (ActuatorPosition1 < 30))
  {
    digitalWrite(h1_out1, HIGH);
   // for testing purposes: Serial.println("1a");
  }
    else 
    {
      digitalWrite(h1_out1, LOW);
      //for testing purposes: Serial.println("0a");
    }
 //this is the second part of the h-bridge logic
 //if the "thickness serialData" coming from labview is "ANDed" with a '1', then it will output
 //the opposite since there is a "NOT" out in front, then this result is "ANDed" with 
 //the actuatorposition(extended)since greater than 900. 
 //If this is a TRUE result, then it will outuput a '1'(HIGH), otherwise
 //it will output a '0'(LOW)
 //*MORE EXPLAINED IN WORD DOC*
  if (!(serialData & 1) && (ActuatorPosition1 > 900))
  {
    digitalWrite(h1_out2, HIGH);
   // Serial.println("1b");
  }
    else
    {
      digitalWrite(h1_out2, LOW);
     // Serial.println("0b");
    }
//end ACTUATOR 1*****************************************************************************************


 
//********ACTUATOR 2**************************************************************************************
//This code is almost an exact repeat of the Actuator1 above code but slightly different
//Since we are using an 8 bit binary format to control the outputs of the actuators
//*EXPLAINED IN WORD DOC*
//Actuator2 is controled by the second LSB and based off of this
//whether it needs to be OUTPUTTED our just stay put
//instead of "ANDing" the serialData with '1' it is anded with a 2
//for the second binary value (0000 0010)
//the rest of the logic is the same
  if ((serialData & 2) && (ActuatorPosition2 < 30))
  {
    digitalWrite(h2_out1, HIGH);
    Serial.println("it worked");
  }
  else 
  {
    digitalWrite(h2_out1, LOW);
  }
  if (!(serialData & 2) && (ActuatorPosition2 > 900))
  {
    digitalWrite(h2_out2, HIGH);
  }
  else
  {
    digitalWrite(h2_out2, LOW);
  }
  
//ACTUATOR 3************************************************************************************
//this is the same as above except it is "ANDed" with  '4' for the 3rd LSB(0000 0100)
  if ((serialData & 4) && (ActuatorPosition3 < 30))
  {
    digitalWrite(h3_out1, HIGH);
  }
    else 
    {
      digitalWrite(h3_out1, LOW);
    }
  if (!(serialData & 4) && (ActuatorPosition3 > 900))
  {
    digitalWrite(h3_out2, HIGH);
  }
    else
    {
      digitalWrite(h3_out2, LOW);
    }

//**ACTUATOR 4************************************************************************************
//same but "ANDed" with '8' for the 4th LSB (0000 1000)
  if ((serialData & 8) && (ActuatorPosition4 < 30))
  {
    digitalWrite(h4_out1, HIGH);
  }
    else 
    {
      digitalWrite(h4_out1, LOW);
    }
  if (!(serialData & 8) && (ActuatorPosition4 > 900))
  {
    digitalWrite(h4_out2, HIGH);
  }
    else
    {
      digitalWrite(h4_out2, LOW);
    }

//**ACTUATOR 5************************************************************************************
//same but "ANDed" with '16' for the 5th LSB (0001 0000)
  if ((serialData & 16) && (ActuatorPosition5 < 30))
  {
    digitalWrite(h5_out1, HIGH);
  }
    else 
    {
      digitalWrite(h5_out1, LOW);
    }
  if (!(serialData & 16) && (ActuatorPosition5 > 900))
  {
    digitalWrite(h5_out2, HIGH);
  }
    else
    {
      digitalWrite(h5_out2, LOW);
    }

//ACTUATOR 6************************************************************************************
//same but "ANDed" with a '32' for the 6th LSB (0010 0000)
  if ((serialData & 32) && (ActuatorPosition6 < 30))
  {
    digitalWrite(h6_out1, HIGH);
  }
    else 
    {
      digitalWrite(h6_out1, LOW);
    }
  if (!(serialData & 32) && (ActuatorPosition6 > 900))
  {
    digitalWrite(h6_out2, HIGH);
  }
    else
    {
      digitalWrite(h6_out2, LOW);
    }

//ACTUATOR 7************************************************************************************
//same but "ANDed" with '64' for the 7th LSB (0100 0000)
  if (((serialData & 64)?1:0) && (ActuatorPosition7 < 30))
  {
    digitalWrite(h7_out1, HIGH);
  }
    else 
    {
      digitalWrite(h7_out1, LOW);
    }
  if (!(serialData & 64) && (ActuatorPosition7 > 900))
  {
    digitalWrite(h7_out2, HIGH);
  }
    else
    {
      digitalWrite(h7_out2, LOW);
    }

//ACTUATOR 8************************************************************************************
//same but "ANDed" with '128' for the MSB (1000 0000)
  if ((serialData & 128) && (ActuatorPosition8 < 30))
  {
    digitalWrite(h8_out1, HIGH);
  }
    else 
    {
      digitalWrite(h8_out1, LOW);
    }
  if (!(serialData & 128) && (ActuatorPosition8 > 900))
  {
    digitalWrite(h8_out2, HIGH);
  }
    else
    {
      digitalWrite(h8_out2, LOW);
    }
  
 }
}

