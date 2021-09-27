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
  for (int y=0; y <= 6; y++){
    pinMode(y, OUTPUT);
  }
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
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);

}

void num_1(void){
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void num_2(void){
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num_3(void){
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}

void num_4(void){
  digitalWrite(a, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
}

void num_5(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
}

void num_6(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num_7(void){
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
}

void num_8(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
  digitalWrite(f, HIGH);
  digitalWrite(g, HIGH);
}

void num_9(void){
  digitalWrite(a, HIGH);
  digitalWrite(b, HIGH);
  digitalWrite(c, HIGH);
  digitalWrite(d, HIGH);
  digitalWrite(e, HIGH);
}

void countup(void){
  num_0();
  delay(delay_time);
  low();

  num_1();
  delay(delay_time);
  low();

  num_2();
  delay(delay_time);
  low();

  num_3();
  delay(delay_time);
  low();

  num_4();
  delay(delay_time);
  low();

  num_5();
  delay(delay_time);
  low();

  num_6();
  delay(delay_time);
  low();

  num_7();
  delay(delay_time);
  low();

  num_8();
  delay(delay_time);
  low();

  num_9();
  delay(delay_time);
  low();
}

void countdown(void){
  num_9();
  delay(delay_time);
  low();

  num_8();
  delay(delay_time);
  low();

  num_7();
  delay(delay_time);
  low();

  num_6();
  delay(delay_time);
  low();

  num_5();
  delay(delay_time);
  low();

  num_4();
  delay(delay_time);
  low();

  num_3();
  delay(delay_time);
  low();

  num_2();
  delay(delay_time);
  low();

  num_1();
  delay(delay_time);
  low();

  num_0();
  delay(delay_time);
  low();
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
    if(comdata == "countup")
    {
      countup();
    }
    else if(comdata == "countdown")
    {
      countdown();
    }
    else if(comdata == "0")
    {
      num_0();
      delay(delay_time);
      low();
    }
    else if(comdata == "1")
    {
      num_1();
      delay(delay_time);
      low();
    }
    else if(comdata == "2")
    {
      num_2();
      delay(delay_time);
      low();
    }
    else if(comdata == "3")
    {
      num_3();
    }
    else if(comdata == "4")
    {
      num_5();
    }
    else if(comdata == "6")
    {
      num_6();
    }
    else if(comdata == "7")
    {
      num_7();
    }
    else if(comdata == "0")
    {
      num_0();
    }
    else if(comdata == "8")
    {
      num_8();
    }
    else if(comdata == "9")
    {
      num_9();
    }
    else
    {
      low();
    }


}
