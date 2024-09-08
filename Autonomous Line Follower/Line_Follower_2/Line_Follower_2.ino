const int l_s=8,r_s=7;//ir sensors
int l_v,r_v;//values of ir sensors

const int l_f=3,l_b=2,r_f=5,r_b=4;//motors

void setup() {
  //ir sensors
  pinMode(l_s,INPUT);
  pinMode(r_s,INPUT);

  //motors
  pinMode(l_f,OUTPUT);
  pinMode(l_b,OUTPUT);
  pinMode(r_f,OUTPUT);
  pinMode(r_b,OUTPUT);
}

void forward()
{
  //left motor forward
  analogWrite(l_f,255);
  digitalWrite(l_b,LOW);
  
  //right motor forward
  analogWrite(r_f,255);
  digitalWrite(r_b,LOW);
}

void left()
{
  //left motor stops
  analogWrite(l_f,120);
  digitalWrite(l_b,HIGH);
  
  //right motor forward
  analogWrite(r_f,255);
  digitalWrite(r_b,LOW);
}

void right()
{
  //left motor forward
  analogWrite(l_f,255);
  digitalWrite(l_b,LOW);
  
  //right motor stops
  analogWrite(r_f,120);
  digitalWrite(r_b,HIGH);
}

void halt()
{
  //left motor stops
  digitalWrite(l_f,LOW);
  digitalWrite(l_b,LOW);
  
  //right motor stops
  digitalWrite(r_f,LOW);
  digitalWrite(r_b,LOW);
}

void loop() {
  //values read
  l_v=digitalRead(l_s);
  r_v=digitalRead(r_s);

  //instructions
  if(l_v==HIGH && r_v==HIGH)
    forward();
  else if(l_v==LOW && r_v==HIGH)
    left();
  else if(l_v==HIGH && r_v==LOW)
    right();
  else
    halt();
}
