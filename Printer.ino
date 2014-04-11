//Aurduino IDE Based 3D Printer firmware by Dennis Gunia
#define sens_z 3 //sensor z-axis
#define sens_y 4 //sensor y-axis
#define sens_xA 5 //sensor x-axis 1
#define sens_xB 6 //sensor x-axis 2

#define sel_motorcontroller 13 //pin for selecting motor driver
#define sel_extrudercontroller 12 //pin for selecting extruder controller
#define sel_computer 11 //pin for selecting computer

#define rpmm_x 10 // rotations / milimeters
#define rpmm_y 10 // rotations / milimeters
#define rpmm_z 10 // rotations / milimeters

#define temp_extruder_limit 150 // temperature limit for extruder (celsius)
#define temp_plate_limit 60 // temperature limit for base plate (celsius)

int screen_mode = 1; //screen mode for LCD displays
//MODE 1 (16x2)  EXTR_TEMP ; PLATE_TEMP ; POS ; ABS LEVEL ( SYMBOL )
//MODE 2 (20x2)  EXTR_TEMP ; PLATE_TEMP ; POS ; ABS LEVEL ( SYMBOL & Percent)
//MODE 3 (20x4)  EXTR_TEMP ; PLATE_TEMP ; POS ; ABS LEVEL ( SYMBOL & Percent) ; TIME PASSED ; WARNINGS

#define rot_A A0 //rotary opto a
#define rot_B A1 //rotary opto b
#define rot_P A2 //rotary push switch

int temp_extr = 0;
int temo_plat = 0;
int ABS_lvl = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(96000);

  pinMode(sens_xA, OUTPUT);
  pinMode(sens_xB, OUTPUT);
  pinMode(sens_y, OUTPUT);
  pinMode(sens_z, OUTPUT);

  pinMode(sel_motorcontroller, OUTPUT);
  pinMode(sel_extrudercontroller, OUTPUT);
  pinMode(sel_computer, OUTPUT);

  pinMode(rot_A, OUTPUT);
  pinMode(rot_B, OUTPUT);
  pinMode(rot_P, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

}

//moveX (int value) moves the extruder by value (mm)
void moveX(int value) {
  digitalWrite(sel_motorcontroller, HIGH);
  if (value > 0) {
    Serial.write("mov");
    delay(1);
    Serial.write("X");
    delay(1);
    Serial.write(value);

  }
  digitalWrite(sel_motorcontroller, LOW);

}

//moveY (int value) moves the extruder by value (mm)
void moveY(int value) {
  digitalWrite(sel_motorcontroller, HIGH);
  if (value > 0) {
    Serial.write("mov");
    delay(1);
    Serial.write("Y");
    delay(1);
    Serial.write(value);

  }
  digitalWrite(sel_motorcontroller, LOW);

}

//moveZ (int value) moves the extruder by value (mm)
void moveZ(int value) {
  digitalWrite(sel_motorcontroller, HIGH);
  if (value > 0) {
    Serial.write("mov");
    delay(1);
    Serial.write("Z");
    delay(1);
    Serial.write(value);

  }
  digitalWrite(sel_motorcontroller, LOW);

}

void calibrateExtruder() {
  digitalWrite(sel_motorcontroller, HIGH);

  Serial.write("cal");
  delay(1);
  Serial.write("X");
  while (digitalRead(sens_xA) == HIGH) {
    //do nothing
  }
  Serial.write("OK");

  delay(1000);


  Serial.write("cal");
  delay(1);
  Serial.write("Y");
  while (digitalRead(sens_y) == HIGH) {
    //do nothing
  }
  Serial.write("OK");

  delay(1000);


  Serial.write("cal");
  delay(1);
  Serial.write("Z");
  while (digitalRead(sens_z) == HIGH) {
    //do nothing
  }
  Serial.write("OK");


  digitalWrite(sel_motorcontroller, LOW);
}
