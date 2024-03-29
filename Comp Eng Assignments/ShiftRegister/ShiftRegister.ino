int latchPin = 11;  // Latch pin of 74HC595 is connected to Digital pin 5
int clockPin = 12; // Clock pin of 74HC595 is connected to Digital pin 6
int dataPin = 10;  // Data pin of 74HC595 is connected to Digital pin 4

byte leds = 0;    // Variable to hold the pattern of which LEDs are currently turned on or off

void setup() 
{
  // Set all the pins of 74HC595 as OUTPUT
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  leds = 0;  // Initially turns all the LEDs off, by giving the variable 'leds' the value 0
  updateShiftRegister();
  delay(500);
  for (int i = 0; i < 8; i++) // Turn all the LEDs ON one by one.
  {
    bitSet(leds, i);    // Set the bit that controls that LED in the variable 'leds'
    updateShiftRegister();
    delay(500);
  }
}


void updateShiftRegister()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
