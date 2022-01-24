
// Using L293D
// Set variables for pins
//Motor Right
const int motorRightFor  = 9; // Pin  7 of L293
const int motorRightBack  = 10;  // Pin  2 of L293
//Motor Left
const int motorLeftFor  = 5;  // Pin 14 of L293
const int motorLeftBack  = 6;  // Pin 10 of L293

void setup() { 
    // Set motor pins as output
    pinMode(motorRightFor, OUTPUT);
    pinMode(motorRightBack, OUTPUT);
    pinMode(motorLeftFor, OUTPUT);
    pinMode(motorLeftBack, OUTPUT);
}

void loop() {
    digitalWrite(motorRightFor, LOW);
    digitalWrite(motorRightBack, LOW);


}
