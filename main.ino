int EXTRUDER = 13;
int PLATE = 12;
int FAN = 11;


void setup() {
  // put your setup code here, to run once:
  pinMode(EXTRUDER , OUTPUT);
  pinMode(PLATE , OUTPUT);
  pinMode(FAN , OUTPUT);
  digitalWrite(EXTRUDER, HIGH);
  digitalWrite(PLATE, HIGH);
  digitalWrite(FAN, HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:

}
