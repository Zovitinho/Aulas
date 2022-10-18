#define ledV1 2
#define ledA1 3
#define ledV2 4
#define ledA2 5
#define ledV3 6


long tecladoA5 = 0;



void setup()
{
Serial.begin(9600);
}

void loop()
{
  tecladoA5 = analogRead(A5);
  Serial.println(tecladoA5);
  delay(100);
  
  //LED 1
  if(tecladoA5 == 205)
  {
    digitalWrite(ledV1, 1);
      
  }else{
    digitalWrite(ledV1, 0);
  }
  
  //LED 2
  if(tecladoA5 == 256)
  {
    digitalWrite(ledA1, 1);
      
  }else{
    digitalWrite(ledA1, 0);
  }
  
  //LED 3
  if(tecladoA5 == 341)
  {
    digitalWrite(ledV2, 1);
      
  }else{
    digitalWrite(ledV2, 0);
  }
  
  //LED 4
  if(tecladoA5 == 511)
  {
    digitalWrite(ledA2, 1);
      
  }else{
    digitalWrite(ledA2, 0);
  }
  
  //LED 5
  if(tecladoA5 == 1023)
  {
    digitalWrite(ledV3, 1);
      
  }else{
    digitalWrite(ledV3, 0);
  }

       
}

//Botão 1 == 205
//Botão 2 == 256
//Botão 3 == 341
//Botão 4 == 511
//Botão 5 == 1023
