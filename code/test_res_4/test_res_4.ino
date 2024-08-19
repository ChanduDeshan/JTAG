/*
  Blink
*/

String x;
int n=10;


String data;
char d1;
char d2;

const int TCK = 13;
int TDO = 2;
const int TMS = 14;
const int TDI = 12;
int TDO_value=0;





// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);
  // initialize digital pin ledPin as an output.
  pinMode(TCK, OUTPUT);
  pinMode(TDO, INPUT);
  pinMode(TMS, OUTPUT);
  pinMode(TDI, OUTPUT);
  
}


void delay1(){
  delay(100);
  }
//********************************************************************
void clock1_stop() {           //test clok stop funtion 
  digitalWrite(TCK, LOW);   
         
}
//*************************************************************************

// the loop function runs over and over again forever
void clock1() {
  digitalWrite(TCK, HIGH);   // turn the LED on (HIGH is the voltage level)
  //Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TCK, LOW);
  //Serial.print(0);           // turn the LED off by making the voltage LOW
  
 
}
//********************************************************************************
void test_logic_rest_tms(){
  //This TMS 11111 means at the begining TEST LOGIC RESET Position
  
  digitalWrite(TMS, HIGH); // turn the LED on (HIGH is the voltage level)//-----1
  clock1();
  Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW 
  clock1();
  Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//-----1
  clock1();
  Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW
  clock1();
  Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//------1 
  clock1();
  Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW
  clock1();
  Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//------1
  clock1();
  Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW
  clock1();
  Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//------1
  clock1();
  Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);    // turn the LED off by making the voltage LOW
  clock1();
  Serial.print(0);
  delay1();
   }
 //*************************************************************************************************
void EXTEST(){
  for(int counter = 1; counter<=n; counter++){
    digitalWrite(TDI, LOW);
    clock1();
    Serial.println("0");
    delay1();
   
    }
  }
 //*************************************************************************************************

void BYPASS(){
  for(int counter = 1; counter<=n; counter++){
    digitalWrite(TDI,HIGH );
    clock1();
    Serial.println("1");
    delay1();
    
    }
  }
 //**************************************************************************************************

 void LOAD_INSTRUCTION_EXTEST(){
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();                  
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  Serial.print("1");
  delay1();    
  digitalWrite(TMS, HIGH);  //-------1 
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();
  EXTEST();                 //-------(all 00000000->>>>Total Lenth of instrution Reg of all chips on the board)
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();
  }
//*****************************************************************************************************************
 void LOAD_INSTRUCTION_BYPASS(){
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();                  
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  Serial.print("1");
  delay1();    
  digitalWrite(TMS, HIGH);  //-------1 
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();
  BYPASS();                 //-------(all 111111->>>>Total Lenth of instrution Reg of all chips on the board)
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  Serial.print("0");
  delay1();
  }
 //******************************************************************************************************************
void TDO_sig(){
   int TDO_value=digitalRead(TDO);
   Serial.print(TDO_value);
   delay1();
  
 
  }
 //*******************************************************************************************************************
void loop(){
    clock1();
  if(Serial.available()){
    data = Serial.readString();
    d1=data.charAt(0); //data. char atposition 0 
    switch(d1){        // select action based on first  character 
      case 'A':
      clock1();
      break;
      case 'a':
      clock1_stop();
      break;
      case 'b':  //first caharacter is an S =set servo angle 
      BYPASS();
      break;
      case 'e':
      EXTEST();
      break;
      case 'B':
      LOAD_INSTRUCTION_BYPASS();
      break;
      case 'R':
      test_logic_rest_tms();
      break;
      case 'E':
      LOAD_INSTRUCTION_EXTEST();
      break;  
      }
      
    }
  
  
  
  }


  
