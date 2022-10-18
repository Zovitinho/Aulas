//Pinos
#define sensorTEMPERATURA A0
#define sensorFORCA A1
#define sensorLDR A2
#define sensorPIR 2
#define sensorFLEXIVEL A3

//Varíaveis
long tecladoA5 = 0;
long cm = 0;
float temperatura = 0;
int valorforca = 0;
int luminosidade = 0;
int flexibilidade = 0;



void setup()
{
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}


void loop()
{
  tecladoA5 = analogRead(A5);
  
  
  //Sensor distancia
  long cm = 0.01723 * readUltrasonicDistance(13, 12);
 
  //Sensor de Temperatura
  float temperatura = ((analogRead(A0) * (5.0/1024))-0.5)/0.01;

  
  
         //1//    
  //Sensor de Distância
  if(tecladoA5 == 205)
  {
    Serial.print("Distancia: ");
    Serial.print(cm);
    Serial.println(" cm");
  }
  
  
         //2//
  //Sensor de Temperatura
  if(tecladoA5 == 256)
  {
    Serial.print("Temperatura: ");
    Serial.print(temperatura);
    Serial.println("Graus Celsius");
  }
  
  
        //3//
  //Sensor de Força
  if(tecladoA5 == 341)
  {
    valorforca = analogRead(A1) ;
    Serial.print("Forca: ");
    Serial.print(valorforca);
    Serial.println(" Newtons");
  }
  
  
        //4//
  //Sensor FOTORRESISTLDR)
  if(tecladoA5 == 511)
  {
    luminosidade = analogRead(A2); 
    Serial.print("Luminosidade: ");
    Serial.print(luminosidade); 
    Serial.println(" Luz");
  } 
  
  
  //5//
  //Sensor PIR
  if(tecladoA5 == 1023)
  {
    flexibilidade = analogRead(A3);
    Serial.print("Flexibilidade: ");
    Serial.println(flexibilidade);
    
    flexibilidade = map(flexibilidade, 700, 900, 0, 255);

  }
  
  
  
  
   

}

//Botão 1 == 205
//Botão 2 == 256
//Botão 3 == 341
//Botão 4 == 511
//Botão 5 == 1023














                     //Sensor distancia
long readUltrasonicDistance(int triggerPin, int echoPin)
{
  pinMode(triggerPin, OUTPUT);  // Clear the trigger
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  // Sets the trigger pin to HIGH state for 10 microseconds
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  // Reads the echo pin, and returns the sound wave travel time in microseconds
  return pulseIn(echoPin, HIGH);
}

