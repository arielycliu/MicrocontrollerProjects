const int a = 6;
const int b = 5;
const int c = 4;
const int d = 3;
const int e = 2;
const int f = 1;
const int g = 0;
int delay_time = 800;
String comdata = "";
int lastLength = 0;


void setup() {

    pinMode(6, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(2, OUTPUT);
    pinMode(1, OUTPUT);
    pinMode(0, OUTPUT);
  
  Serial.begin(9600); //bps
  Serial.println("Input a command (countup, countdown, or any #0-9):");

}

/*
    ___b___    
 a |        | c
   |        |
    ________
   |    e    |
 g |         | d
    _________
         f
*/


void low(void){
  for (int x=0; x <= 6; x++){
    digitalWrite(x, LOW);
  }
}

void num_0(void){
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(1, HIGH);
  digitalWrite(0, HIGH);

}

void loop(){
  if(Serial.available()>0)    
  {  
    comdata = "";
    while (Serial.available() > 0)  
    {        
      comdata += char(Serial.read());
      delay(2);
    }
    Serial.println(comdata);
  }

    if(comdata == "h")
    {
      num_0();
      delay(800);
      low();
    }
    else
    {
      low();
    }


}
