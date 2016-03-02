// # Editor     : Lauren from DFRobot
// # Date       : 17.02.2012

// # Product name: L298N motor driver module DF-MD v1.3
// # Product SKU : DRI0002
// # Version     : 1.0

// # Description:
// # The sketch for using the motor driver L298N
// # Run with the PWM mode

// # Connection:
// #        M1 pin  -> Digital pin 4
// #        E1 pin  -> Digital pin 5
// #        M2 pin  -> Digital pin 7
// #        E2 pin  -> Digital pin 6
// #        Motor Power Supply -> Centor blue screw connector(5.08mm 3p connector)
// #        Motor A  ->  Screw terminal close to E1 driver pin
// #        Motor B  ->  Screw terminal close to E2 driver pin
// # 
// # Note: You should connect the GND pin from the DF-MD v1.3 to your MCU controller. They should share the GND pins.
// #

int Ehr = 6;
int Mhr = 7;

int Evr = 5;                         
int Mvr = 4;

int Ehl = 14;                         
int Mhl = 9;

int Evl = 15;                         
int Mvl = 8;                           

void setup() 
{ 
    pinMode(Mhr, OUTPUT);   
    pinMode(Mvl, OUTPUT);
    pinMode(Mhl, OUTPUT);
    pinMode(Mvr, OUTPUT); 
} 

void loop() 
{ 
  int value;
  //for(value = 0 ; value <= 255; value+=5) 
  { 
    digitalWrite(Mhr,LOW);   
    digitalWrite(Mvl,LOW); 
    digitalWrite(Mvr,LOW);
    digitalWrite(Mhl,LOW);      
    analogWrite(Ehr, 255);   //PWM Speed Control
    analogWrite(Evl, 255);   //PWM Speed Control
    analogWrite(Evr, 255);   //PWM Speed Control
    analogWrite(Ehl, 255);   //PWM Speed Control
   
    delay(3000);
    
    analogWrite(Ehr, 0);   //PWM Speed Control
    analogWrite(Evl, 0);   //PWM Speed Control
    analogWrite(Evr, 0);   //PWM Speed Control
    analogWrite(Ehl, 0);   //PWM Speed Control 
    while(1)
    {
      
    }
  }  
}

