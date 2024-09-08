#include<SoftwareSerial.h>

SoftwareSerial voice(7,8);

//motors
const int l_f=3,r_f=5;
const int l_b=2,r_b=4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  voice.begin(9600);
  while(!Serial){}
}

String text()
{
  String s="";
  while(voice.available())
  {
    delay(10);
    s+=(char)voice.read();
  }
  return s;
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
  analogWrite(l_f,105);
  digitalWrite(l_b,LOW);
  
  //right motor forward
  analogWrite(r_f,120);
  digitalWrite(r_b,LOW);
}

void left(String l)
{
  //left motor stops
  analogWrite(l_f,120);
  digitalWrite(l_b,HIGH);
  
  //right motor forward
  analogWrite(r_f,255);
  digitalWrite(r_b,LOW);

  if(l=="left")
  {
    delay(460);
    halt();
  }
}

void right(String r)
{
  //left motor forward
  analogWrite(l_f,255);
  digitalWrite(l_b,LOW);
  
  //right motor stops
  analogWrite(r_f,120);
  digitalWrite(r_b,HIGH);

  if(r=="right")
  {
    delay(460);
    halt();
  }
}


void back()
{
  //left motor back
  analogWrite(l_f,163);
  digitalWrite(l_b,HIGH);
  
  //right motor back
  analogWrite(r_f,150);
  digitalWrite(r_b,HIGH);
}

void loop() {
  // put your main code here, to run repeatedly:
  String readBT=text();
  if(readBT!="")
  {
    Serial.println(readBT);
    if(readBT=="forward")
      forward();
    else if(readBT=="left" || readBT=="left_b")
      left(readBT);
    else if(readBT=="right" || readBT=="right_b")
      right(readBT);
    else if(readBT=="backward")
      back();
    else
      halt();
  }
}
