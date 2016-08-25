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
}

void loop() {
  digitalWrite(h1_out1,HIGH);
  digitalWrite(h1_out2,LOW);
  delay(30000);
  digitalWrite(h2_out1,HIGH);
  digitalWrite(h2_out2,LOW);
  delay(30000);
  digitalWrite(h1_out1,LOW);
  digitalWrite(h1_out2,HIGH);
  delay(30000);
  digitalWrite(h2_out1,LOW);
  digitalWrite(h2_out2,HIGH);
  delay(30000);
}
