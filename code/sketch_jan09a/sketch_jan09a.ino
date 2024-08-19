String x;
String q;
//String n1=4;
//String m1=141;
int n =4;// n1.toInt() ;
int m =141;// m1.toInt(); 
int i=32;




String data;
char d1;
char d2;

const int TCK = 13;
const int TMS = 14;
const int TDI = 12;
int TDO = 2;
bool TDO_value=0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // initialize digital pin ledPin as an output.
  pinMode(TCK, OUTPUT);
  pinMode(TDO, INPUT);
  pinMode(TMS, OUTPUT);
  pinMode(TDI, OUTPUT);
  

}

void loop() {
  // put your main code here, to run repeatedly:

    if(Serial.available()){
    data = Serial.readString();
    d1=data.charAt(0); //data. char atposition 0 
    switch(d1){        // select action based on first  character 
      case 'A':
      clock1();
      break;
      case 'a':
     //lock1_stop();
      break;
      case 'b':  //first caharacter is an S =set servo angle 
   // BYPASS();
      break;
      case 'B':
   // LOAD_INSTRUCTION_BYPASS();
      break;
      case 'R':
      test_logic_rest_tms();
      break;
      case 'E':
 //   LOAD_INSTRUCTION_EXTEST();
      break; 
      case 'S':
 //   SEND_INSTRUCTION_EXTEST();
      break; 
      case 'O':
 //   OUTPUT_DATA_EXTEST();
      break;
      case 'y':
      x=data.substring(1);
      n=x.toInt();
      break;
      case 'z':
      q=data.substring(1);
      m=q.toInt();
      break;
      case 'I':
//    LOAD_ID_reg();
      break;
      case 'D':
 //   GET_IDCODE();
      break;
      case 'C':
  //    CAPTURE_SCAN_OUT();
      break;
       }
      
    }
  }
 //****************************************************************************************************************************
void delay1(){
  delay(100);
  }
//******************************************************************************************************************************************
void clock1() {
  digitalWrite(TCK, HIGH);   // turn the LED on (HIGH is the voltage level)
  //Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TCK, LOW);
  //Serial.print(0);           // turn the LED off by making the voltage LOW
  
 }

//*********************************************************************************************************************************************
void test_logic_rest_tms(){
  //This TMS 11111 means at the begining TEST LOGIC RESET Position
  
  digitalWrite(TMS, HIGH); // turn the LED on (HIGH is the voltage level)//-----1
  clock1();
  //Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW 
  clock1();
  //Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//-----1
  clock1();
  //Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW
  clock1();
  //Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//------1 
  clock1();
  //Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW
  clock1();
  //Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//------1
  clock1();
  //Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);// turn the LED off by making the voltage LOW
  clock1();
  //Serial.print(0);
  delay1();
  digitalWrite(TMS, HIGH);   // turn the LED on (HIGH is the voltage level)//------1
  clock1();
  //Serial.print(1);
  delay1();                  // wait for a second
  digitalWrite(TMS, LOW);    // turn the LED off by making the voltage LOW
  clock1();
  //Serial.print(0);
  delay1();
  delay1();
  delay1();
  delay1();
  Serial.println("Test Reset Mode DONE...........");
  
//*********************************************************************************************************************************************
void LOAD_ID_reg(){
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();                  
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.print("1");
  delay1();    
  digitalWrite(TMS, HIGH);  //-------1 
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  void LOAD_ID_reg(){
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();                  
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.print("1");
  delay1();    
  digitalWrite(TMS, HIGH);  //-------1 
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  digitalWrite(TMS, LOW);   //-------0
  digitalWrite(TDI, LOW);   //-------0
  clock1();
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  digitalWrite(TDI, LOW);   //-------0
  clock1();
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  digitalWrite(TDI, LOW);   //-------0
  clock1();
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  digitalWrite(TDI,HIGH);   //-------1
  clock1();
  delay1();
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
  delay1();
  delay1();
  delay1();
  //vTaskDelete(Task2);
  Serial.println("Lode id Instruction Done.........");
  }
 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
  delay1();
  delay1();
  delay1();
  //vTaskDelete(Task2);
  Serial.println("Lode id Instruction Done.........");
  }
  /*
//*******************************************************************************************************
void GET_IDCODE(){                 
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.print("1");
  delay1();    
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
  iDcode_IR();                 //-------(known BIT pattern that going to input through the TDI and tdi size is depend on the Size of the DATA registers )
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("1");
  delay1();
  delay1();
  delay1();
  delay1();
  //vTaskDelete(Task2);
  Serial.println("chip id code done..............");
}

//*****************************************************************************************************************************

//***************************************************************************************************************************
*/
