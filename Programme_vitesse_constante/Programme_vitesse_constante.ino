#include <Servo.h>

Servo myservo;  //Déclare un nouveau servomoteur nommé myservo
int pos = 0;   //Position initiale du servo
#define PAUSE 5000  //Symbolise la pause en ms entre chaque mouvements du servo


void setup() 
{
  myservo.attach(9);  //Attache myservo au pin 9
  delay(5000);
}

void loop() {

 myservo.write(78); //on va à 78° soit 1880 tr/min
 delay(PAUSE);     // on attend 5000ms=5s
 myservo.write(0); // on va à 0° soit 0 tr/min
 delay(PAUSE);     // on attend 5000ms=5s
}

