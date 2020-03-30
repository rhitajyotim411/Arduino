#include<Servo.h>
Servo s;
const int trig=10,echo=12;//UltraSonic
const int l_f=2,l_b=3,r_f=4,r_b=5;//motors

long d_f,d_l,d_r,f=0;//distances

void setup() {
  // put your setup code here, to run once:
  s.attach(9);
  s.write(90);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  
  //motors
  pinMode(l_f,OUTPUT);
  pinMode(l_b,OUTPUT);
  pinMode(r_f,OUTPUT);
  pinMode(r_b,OUTPUT);
}

long dist()
{
  float t,d;
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  
  t=pulseIn(echo,HIGH);
  d=(t/2)*0.0343;

  return (long)d;
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

void forward()
{
  //left motor forward
  digitalWrite(l_f,HIGH);
  digitalWrite(l_b,LOW);
  
  //right motor forward
  digitalWrite(r_f,HIGH);
  digitalWrite(r_b,LOW);

  f=0;
}

void left()
{
  //left motor backwards
  digitalWrite(l_f,LOW);
  digitalWrite(l_b,HIGH);
  
  //right motor forward
  digitalWrite(r_f,HIGH);
  digitalWrite(r_b,LOW);

  delay(500);
  halt();

  f=0;
}

void right()
{
  //left motor forward
  digitalWrite(l_f,HIGH);
  digitalWrite(l_b,LOW);
  
  //right motor backwards
  digitalWrite(r_f,LOW);
  digitalWrite(r_b,HIGH);

  delay(500);
  halt();

  f=0;
}

void back()
{
  //left motor back
  digitalWrite(l_f,LOW);
  digitalWrite(l_b,HIGH);
  
  //right motor back
  digitalWrite(r_f,LOW);
  digitalWrite(r_b,HIGH);

  delay(500);
  halt();

  f=1;
}

void loop() {
  // put your main code here, to run repeatedly:
  d_f=dist();
  if(d_f>20 && f==0)
    forward();
  else
  {
    halt();
    s.write(0);
    delay(250);
    d_r=dist();
    delay(500);
    s.write(90);
    delay(500);
    s.write(180);
    delay(250);
    d_l=dist();
    delay(500);
    s.write(90);
    if(d_l<20 && d_r<20)
      back();
    else if(d_l>d_r)
      left();
    else
      right();
  }
}
