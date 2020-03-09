#include <Servo.h> 
Servo myservo; 

int pos = 0;                           //Position initial du servo à 0°

void setup() 
{ 
  myservo.attach(9);                  //Servo relié à la broche 9
} 
 
void loop() 
{ 
  for(pos = 0; pos < 180; pos += 5)   //Servo se déplace de 0 degré à 180 degré par pas de 5°
  {
    myservo.write(pos);               //Transmettre à la variable 'pos' la position
    delay(10);                        //Attendre 10ms pour que le servo atteigne la position  
  } 
  for(pos = 180; pos >= 1; pos -= 5)  //Servo se déplace de 180 degré à 0 degré par pas de 5°
  {
    myservo.write(pos);               //Transmettre à la variable 'pos' la position
    delay(10);                        //Attendre 10ms pour que le servo atteigne la position 
  } 
}


