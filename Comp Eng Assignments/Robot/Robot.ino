// Set variables for sensors and leds
const int IRSensorRight = A5;
const int LEDRight = 2;
const int IRSensorLeft = A0;
const int LEDLeft = 13;

// Set ir sensor black color values
int leftSensorBlack = 150;
int rightSensorBlack = 150; 

// Using L293D
// Set variables for motor pins
//Motor Right
const int motorRightFor  = 9; // Pin  7 of L293
const int motorRightBack  = 10;  // Pin  2 of L293
//Motor Left
const int motorLeftFor  = 5;  // Pin 14 of L293
const int motorLeftBack  = 6;  // Pin 10 of L293

// Set motor speeds
int motorHigh = 160;
int motorSlow = 100;
int motorOff = 0;

void setup() {
    // Set LED and IR sensor pins 
    pinMode(IRSensorRight, INPUT);
    pinMode(LEDRight, OUTPUT);
    pinMode(IRSensorLeft, INPUT);
    pinMode(LEDLeft, OUTPUT);
    Serial.begin(9600); // init serial monitor at port 9600
  
    // Set motor pins as output
    pinMode(motorRightFor, OUTPUT);
    pinMode(motorRightBack, OUTPUT);
    pinMode(motorLeftFor, OUTPUT);
    pinMode(motorLeftBack, OUTPUT);
}

void loop() {
  int statusSensorRight = analogRead(IRSensorRight); // get input from sensors
  int statusSensorLeft = analogRead(IRSensorLeft);
  
//  Serial.println(statusSensorLeft); // print out sensor values to serial monitor
  Serial.println(statusSensorRight); 

  // CASE 1: Both sensors on black -> STOP
  if (statusSensorRight >= rightSensorBlack && statusSensorLeft >= leftSensorBlack){
    digitalWrite(LEDRight, HIGH); // set led high since on black line
    digitalWrite(LEDLeft, HIGH);
    analogWrite(motorRightFor, motorOff);  // set motors to low
    analogWrite(motorRightBack, motorOff);
    analogWrite(motorLeftFor, motorOff);
    analogWrite(motorLeftBack, motorOff); 
  }

  // CASE 2: Both sensors on white -> STRAIGHT FORWARD
  else if (statusSensorRight < rightSensorBlack && statusSensorLeft < leftSensorBlack){
    digitalWrite(LEDRight, LOW); // set led low since on white board
    digitalWrite(LEDLeft, LOW);
    analogWrite(motorRightFor, motorHigh);  // set right motor to forward on
    analogWrite(motorRightBack, motorOff);
    analogWrite(motorLeftFor, motorHigh); // set left motor to forward on
    analogWrite(motorLeftBack, motorOff);
  }
  
  // CASE 3: Right sensor on black -> turn right
  else if (statusSensorRight >= rightSensorBlack && statusSensorLeft < leftSensorBlack){
    digitalWrite(LEDRight, HIGH); // set led high to indicate black line
    digitalWrite(LEDLeft, LOW);
    analogWrite(motorRightBack, motorHigh); // move right wheel backward
    analogWrite(motorRightFor, motorOff);
    analogWrite(motorLeftFor, motorHigh);
    analogWrite(motorLeftBack, motorOff); // move left wheel forward
  }

  // CASE 4: Left sensor on black -> turn left
  else if (statusSensorRight < rightSensorBlack && statusSensorLeft >= leftSensorBlack){
    digitalWrite(LEDRight, LOW);
    digitalWrite(LEDLeft, HIGH); // set led high to indicat black line
    analogWrite(motorRightFor, motorHigh); // move right wheel forward
    analogWrite(motorRightBack, motorOff);
    analogWrite(motorLeftFor, motorOff);
    analogWrite(motorLeftBack, motorHigh); // move left wheel backward
  }
  
}
