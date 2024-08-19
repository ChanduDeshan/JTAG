

TaskHandle_t Task1;
TaskHandle_t Task2;

// LED pins
String x;
int n=10;
int m=10;


String data;
char d1;
char d2;

const int TCK = 13;
const int TMS = 14;
const int TDI = 12;
int TDO = 2;
bool TDO_value=0;


void setup() {
  Serial.begin(115200);
  // initialize digital pin ledPin as an output.
  pinMode(TCK, OUTPUT);
  pinMode(TDO, INPUT);
  pinMode(TMS, OUTPUT);
  pinMode(TDI, OUTPUT);
  

  //create a task that will be executed in the Task1code() function, with priority 1 and executed on core 0
  xTaskCreatePinnedToCore(
                    Task1code,   /* Task function. */
                    "Task1",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task1,      /* Task handle to keep track of created task */
                    0);          /* pin task to core 0 */                  

  //create a task that will be executed in the Task2code() function, with priority 1 and executed on core 1
  xTaskCreatePinnedToCore(
                    Task2code,   /* Task function. */
                    "Task2",     /* name of task. */
                    10000,       /* Stack size of task */
                    NULL,        /* parameter of the task */
                    1,           /* priority of the task */
                    &Task2,      /* Task handle to keep track of created task */
                    1);          /* pin task to core 1 */
    
}

//Task1code: blinks an LED every 1000 ms
void Task1code( void * pvParameters ){
  //Serial.print("Task1 running on core ");
  //Serial.println(xPortGetCoreID());

  for(;;){
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
      case 'B':
      LOAD_INSTRUCTION_BYPASS();
      break;
      case 'R':
      test_logic_rest_tms();
      break;
      case 'E':
      LOAD_INSTRUCTION_EXTEST();
      break; 
      case 'S':
      SEND_INSTRUCTION_EXTEST();
      break; 
      case 'O':
      OUTPUT_DATA_EXTEST();
      break;
      }
      
    }
  } 
}

//Task2code: blinks an LED every 700 ms
void Task2code( void * pvParameters ){
  //Serial.print("Task2 running on core ");
  //Serial.println(xPortGetCoreID());

  for(;;){
    TDO_sig();
  }
}

void loop() {
  
}

void delay2(){
  delay(150);
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
  vTaskDelete(Task2);
   }
 //*************************************************************************************************
void EXTEST_IR(){     //Load instruction Shif IR register 
  for(int counter = 1; counter<=n; counter++){
    digitalWrite(TMS,LOW);
    digitalWrite(TDI, LOW);
    clock1();
    //Serial.println("0");
    delay1();
   
    }
  }
 //*************************************************************************************************

 void EXTEST_DR(){     //Load instruction Shif IR register 
  for(int counter = 1; counter<=m; counter++){
    digitalWrite(TMS,LOW);
    digitalWrite(TDI, LOW);
    clock1();
    //Serial.println("0");
    delay1();
   
    }
  }
 //**************************************************************************************************
 void EXTEST_DR_ONLY(){     //Load instruction Shif IR register 
  for(int counter = 1; counter<=m; counter++){
    digitalWrite(TMS,LOW);
    bool TDO_value=digitalRead(TDO);
    Serial.println(TDO_value);
    clock1();
    delay1();
   
    }
  }

 //**************************************************************************************************

void BYPASS(){
  for(int counter = 1; counter<=n; counter++){
    digitalWrite(TDI,HIGH );
    clock1();
    //Serial.println("1");
    delay1();
    
    }
  }
 //**************************************************************************************************

 void LOAD_INSTRUCTION_EXTEST(){
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
  EXTEST_IR();                 //-------(all 00000000->>>>Total Lenth of instrution Reg of all chips on the board)
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
  }
//****************************************************************************************************************
void OUTPUT_DATA_EXTEST(){
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();                  
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.print("0");
  delay1();
  EXTEST_DR_ONLY();                 //-------(all 00000000->>>>Total Lenth of instrution Reg of all chips on the board)
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
  }
//**************************************************************************************************************

void SEND_INSTRUCTION_EXTEST(){                 
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
  EXTEST_DR();                 //-------(known BIT pattern that going to input through the TDI and tdi size is depend on the Size of the DATA registers )
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  //Serial.print("1");
  delay1();
  digitalWrite(TMS, HIGH);   //-------1
  clock1();
  //Serial.print("1");
  delay1();
  delay1();
  delay1();
  delay1();
  //vTaskDelete(Task2);
  }
//*****************************************************************************************************************
 void LOAD_INSTRUCTION_BYPASS(){
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.println("0");
  delay1();                  
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.println("1");
  delay1();    
  digitalWrite(TMS, HIGH);  //-------1 
  clock1();
  //Serial.println("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.println("0");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.println("0");
  delay1();
  BYPASS();                 //-------(all 111111->>>>Total Lenth of instrution Reg of all chips on the board)
  digitalWrite(TMS, HIGH);  //-------1
  clock1();
  //Serial.println("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  //Serial.println("1");
  delay1();
  digitalWrite(TMS, HIGH);   //------1
  clock1();
  //Serial.println("1");
  delay1();
  digitalWrite(TMS, LOW);   //-------0
  clock1();
  //Serial.println("0");
  delay1();
  delay1();
  delay1();
  vTaskDelete(Task2);
  }
 //******************************************************************************************************************
void TDO_sig(){
   bool TDO_value=digitalRead(TDO);
   bool clk=digitalRead(TCK);
   if(clk == 1){
   Serial.println(TDO_value);
   delay2();
   
   }
 }
 //*******************************************************************************************************************
