int value=0;
float conv=5.0/1024.0;
float v=0;
float answer=0;
float vmax=0;
float vmin=0;
int i=3;
void setup() 
{
Serial.begin(9600);
pinMode(2, OUTPUT);
pinMode(8, OUTPUT);
pinMode(11, OUTPUT);
Serial.println("Game begin:");
value=analogRead(A0);
v=value*conv;
}

void loop() 
{
Serial.println(v);
if(Serial.available()>0)
{
  delay(5000);
  answer=Serial.read();
  digitalWrite(2, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
 vmax=v+0.5;
 vmin=v-0.5;
 if(answer>vmin && answer<vmax)
 {
  Serial.println("GOOD ANSWER");
  for(int j=0; j<3; j++)
  {
  digitalWrite(2, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  delay(10);
}
  i=i+1;
 }
  else
  {
    Serial.println("BAD ANSWER");
    i=i-1;
  }

if(i<2)
{
  Serial.println("YOU LOSE");
  delay(500000);
}
else if(i=2)
{
  Serial.println("TRY AGAIN");
  for(int j=0; j<2; j++)
  {
  digitalWrite(2, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  delay(300);
}
}
else if(i=4)
{
  Serial.println("YOU WIN!");
  for (int j=0; j< 5; j++)
  {
  digitalWrite(2, HIGH);
  digitalWrite(8, HIGH);
  digitalWrite(11, HIGH);
  delay(100);
  digitalWrite(2, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  delay(100);
}
delay(500000);
}
}
else
{
   digitalWrite(2, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
}
}
