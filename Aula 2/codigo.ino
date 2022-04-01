const int led = 3;
const int pot = 0;

void setup()
{
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int var = analogRead(pot);
  int var2 = map(var, 0, 1023, 0, 255);
  analogWrite(led, var2);
    Serial.println("pot: ");
   Serial.println(var);
   Serial.println("map: ");
   Serial.println(var2);
   Serial.println(""
                 );
  delay(100);
}
