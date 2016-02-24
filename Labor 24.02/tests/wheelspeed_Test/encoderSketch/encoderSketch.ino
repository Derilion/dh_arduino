// # 
// # Editor     : Lauren from DFRobot
// # Date       : 17.01.2012

// # Product name: Wheel Encoders for DFRobot 3PA and 4WD Rovers
// # Product SKU : SEN0038

// # Description:
// # The sketch for using the encoder on the DFRobot Mobile platform

// # Connection:
// #        left wheel encoder  -> Digital pin 2
// #        right wheel encoder -> Digital pin 3
// #

#define pinVL 3
#define pinVR 2
#define pinHL 18
#define pinHR 19
#define LEFT 0
#define RIGHT 1

long coder[2] = {
  0,0};
int lastSpeed[2] = {
  0,0};  
int interruptVL = digitalPinToInterrupt(pinVL);
int interruptVR = digitalPinToInterrupt(pinVR);

void setup(){
  Serial.begin(9600);                            //init the Serial port to print the data
  Serial.println("Initialising...");
  attachInterrupt(interruptVL, LwheelSpeed, CHANGE);    //init the interrupt mode for the digital pin 2
  attachInterrupt(interruptVR, RwheelSpeed, CHANGE);   //init the interrupt mode for the digital pin 3
  Serial.println("Starting...");
}

void loop(){

  static unsigned long timer = 0;                //print manager timer

  if(millis() - timer > 100){                   
    Serial.print("Coder value: ");
    Serial.print(coder[interruptVL]);
    Serial.print("[Left Wheel] ");
    Serial.print(coder[interruptVR]);
    Serial.println("[Right Wheel]");

    lastSpeed[interruptVL] = coder[interruptVL];   //record the latest speed value
    lastSpeed[interruptVR] = coder[interruptVR];
    coder[interruptVL] = 0;                 //clear the data buffer
    coder[interruptVR] = 0;
    timer = millis();
  }

}


void LwheelSpeed()
{
  coder[interruptVL] ++;  //count the left wheel encoder interrupts
  Serial.println("left wheel triggered");
}


void RwheelSpeed()
{
  coder[interruptVR] ++; //count the right wheel encoder interrupts
  Serial.println("right wheel triggered");
}


