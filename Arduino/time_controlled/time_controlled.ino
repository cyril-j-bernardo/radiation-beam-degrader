int serialData = 0;
int ActuatorPosition1 = 0;
int ActuatorPosition2 = 0;

int ErrorFlagState1 = 0;
int ErrorFlagState2 = 0;

const int h1_out1 = 4;
const int h1_out2 = 5;
const int h2_out1 = 6;
const int h2_out2 = 7;

const int Wiper1 = A0;
const int Wiper2 = A1;

const int ErrorFlag1 = 22;
const int ErrorFlag2 = 24;

int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //setting the digital I/O pins for the h-bridge OUTPUTS
  pinMode(h1_out1, OUTPUT);
  pinMode(h1_out2, OUTPUT);
  pinMode(h2_out1, OUTPUT);
  pinMode(h2_out2, OUTPUT);

  pinMode(ErrorFlag1, INPUT);
  pinMode(ErrorFlag2, INPUT);

  analogReadResolution(10);
  ActuatorPosition1 = analogRead(Wiper1);
  ActuatorPosition2 = analogRead(Wiper2);
  if (ActuatorPosition1 > 30)
  {
    digitalWrite(h1_out2, HIGH);
    digitalWrite(h1_out1, LOW);
  }
  if (ActuatorPosition2 > 30)
  {
    digitalWrite(h2_out2, HIGH);
    digitalWrite(h2_out1, LOW);
  }  
}

void loop() {
  analogReadResolution(10);
  ActuatorPosition1 = analogRead(Wiper1);
  Serial.print("  p1  ");
  Serial.print(ActuatorPosition1);
  Serial.print("  ");
  Serial.print("e1  ");
  Serial.print(ErrorFlag1);
  

  analogReadResolution(10);
  ActuatorPosition2 = analogRead(Wiper2);
  Serial.print("  p2  ");
  Serial.print(ActuatorPosition2);
  Serial.print("  e2  ");
  Serial.println(ErrorFlag2);

  if (Serial.available() > 0) {
    serialData = Serial.parseInt();

    if ((serialData & 1) && (ActuatorPosition1 < 30)) {
      digitalWrite(h1_out1, HIGH);
    }
    else {
      digitalWrite(h1_out1, LOW);
    }
    if ( !(serialData & 1) && (ActuatorPosition1 > 900))
    {
      digitalWrite(h1_out2, HIGH);
    }
    else
    {
      digitalWrite(h1_out2, LOW);
    }
    if (( serialData & 2) && (ActuatorPosition2 < 30))
    {
      digitalWrite(h2_out1, HIGH);
    }
    else
    {
      digitalWrite(h2_out1, LOW);
    }
    if ( !(serialData & 2) && (ActuatorPosition2 > 900))
    {
      digitalWrite(h2_out2, HIGH);
    }
    else
    {
      digitalWrite(h2_out2, LOW);
    }
  }
}
