const int l_s=8,r_s=7;//ir sensors
int l_v,r_v;//values of ir sensors

const int l_f=2,l_b=3,r_f=4,r_b=5;//motors

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
  digitalWrite(l_f,HIGH);
  digitalWrite(l_b,LOW);
  
  //right motor forward
  digitalWrite(r_f,HIGH);
  digitalWrite(r_b,LOW);
}

void left()
{
  //left motor stops
  digitalWrite(l_f,LOW);
  digitalWrite(l_b,LOW);
  
  //right motor forward
  digitalWrite(r_f,HIGH);
  digitalWrite(r_b,LOW);
}

void right()
{
  //left motor forward
  digitalWrite(l_f,HIGH);
  digitalWrite(l_b,LOW);
  
  //right motor stops
  digitalWrite(r_f,LOW);
  digitalWrite(r_b,LOW);
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
