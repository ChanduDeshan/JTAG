const int LED1pin = 4;
const long onDuration = 1000;// OFF time for LED

int LED1State =LOW;// initial state of LED

long rememberTime=0;// this is used by the code

void setup() {
  pinMode(LED1pin,OUTPUT);// define LEDpin as output
  digitalWrite(LED1pin,LED1State);// set initial state
}



void loop() {

  TCK();
  
  }


//*************************************************************************************************************************
void TCK(){
  if( LED1State ==LOW )
 {
    if( (millis()- rememberTime) >= onDuration){   
    LED1State = HIGH;// change the state of LED
    rememberTime=millis();// remember Current millis() time
    LED1State = LOW;
    }
 }

 digitalWrite(LED1pin,LED1State);// turn the LED ON or OFF

  
  }

//*****************************************************************************************************************************
