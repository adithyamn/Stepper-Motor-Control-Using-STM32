

#include <Stepper.h>                         
#define STEPS 32                             
const int speedm = PA4;                      
Stepper stepper(STEPS, PA0, PA2, PA1, PA3);
int angle_rot = 0;                                
void setup()                                
{
  Serial.begin(9600);                        
  pinMode(speedm, INPUT);                   
}

void loop()                                   
{
  if (Serial.available() >0 )  
  {               
    angle_rot = Serial.parseInt();                 
    int speedcntrl = analogRead(speedm);             
   int cntrl = map(speedcntrl, 0, 4096, 0, 1023); 
    stepper.setSpeed(cntrl);                
    stepper.step(angle_rot);                          
 }}
