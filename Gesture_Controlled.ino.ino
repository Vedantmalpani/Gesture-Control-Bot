int motorL[] = {3,2};
int motorR[] = {5,4};
const int zpin = A1;
const int ypin = A2;
const int xpin = A3;
const int powerpin = A4;
const int groundpin = A5;
void setup() {
  Serial.begin(9600);

  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);

  pinMode(groundpin,OUTPUT);
  pinMode(powerpin,OUTPUT);
  digitalWrite(groundpin,LOW);
  digitalWrite(powerpin,HIGH);
}

void loop() {
  int x = analogRead(xpin);
  int y = analogRead(ypin);
  int z = analogRead(zpin);
  Serial.println("xpin\typin");

  Serial.print(analogRead(xpin));
  Serial.print("\t");
  Serial.print(analogRead(ypin));
  Serial.print("\n");

  if(x<410 && x>380 && y>335 && y<380)
  {
    Serial.println("Moving Backward");
    bck();
  }
  else if(x>380 && x<410 && y>430 && y<405)
  {
    fwd();
  }
  else if(x>340 && x<385 && y<430 && y>405)
  {
    Serial.println("Moving Right");
    right();
  }
  else if(x>430 && x<460 && y>400 && y<430)
  {
    Serial.println("Moving Left");
    left();
  }
  else
  {
    Serial.println("Not Moving");
    nomove();
  }
}
void fwd()
{
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);
}
void bck()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);
}
void left()
{
  digitalWrite(motorR[0],HIGH);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],HIGH);
}
void right()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],HIGH);
  digitalWrite(motorL[0],HIGH);
  digitalWrite(motorL[1],LOW);
}
void nomove()
{
  digitalWrite(motorR[0],LOW);
  digitalWrite(motorR[1],LOW);
  digitalWrite(motorL[0],LOW);
  digitalWrite(motorL[1],LOW);
}

