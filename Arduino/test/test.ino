int serialData = 0;
int ActuatorPosition2 = 0;

int ErrorFlagState2 = 0;

const int h2_out1 = 6;
const int h2_out2 = 7;

const int Wiper2 = A1;

const int ErrorFlag2 = 24;



void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(h2_out1, OUTPUT);
  pinMode(h2_out2, OUTPUT);

  pinMode(ErrorFlag2, INPUT);

  digitalWrite(h2_out1, LOW);
  digitalWrite(h2_out2, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
