String data1;
char d1;
#include<Servo.h>;
String x; //hold the servo angle
int servoval;//number servo to turn
Servo s1; //servo


void setup(){
  Serial.begin(9600); 
  pinMode(2,OUTPUT);
  s1.attach(23);//out put 9 servo channnel
  
  }
void loop(){
   if(Serial.available()){
    data1=Serial.readString();
    d1=data1.charAt(0);
    switch(d1){
      case 'A':
      digitalWrite(2,HIGH);
      break;
      case 'B':
      digitalWrite(2,LOW);
      break;
      case 'S':
      x=data1.substring(1);
      servoval=x.toInt();//convert value to number 
      s1.write(servoval);
      delay(100);
      break;
      
      
      
      
      }
    }
    
  }
