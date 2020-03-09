// controle le servo pour qu'il fasse un mouvement de 0 a 68 degrès, donne une vitesse constante et le moteur fait un mouvement de 69 à 0 degrés
#include <Servo.h>

Servo myservo;  // crée un objet pour controler le servo

int pos = 0;    // variable pour enregistrer la position du servo 

void setup() {
  myservo.attach(9);  // vérifie que le servo est bien sur le pin 9
  Serial.begin (9600); //
  }


void loop() 
{
  for (pos = 0; pos <= 69; pos ++) 
  {                                   // vas de 0 degrès à 68 degrés par pas de 1 degrès
    myservo.write(pos);              // dire au servo de se positionner dans la variable 'pos'
    delay(200);                    // attendre 200ms que le servo atteigne sa position
    Serial.println(pos);
  }
 
  for (pos = 69; pos <= 70; pos ++) 
  {                                    // vas de 68 degrès a 69 degrès par pas de 1 degrès
    myservo.write(pos);              // dire au servo de se positionner dans la variable 'pos'
    delay(6000);                    // attendre 6s que le servo atteigne sa position
    Serial.println(pos);
  }
  
  
  
  for (pos = 70; pos >= 0; pos --) 
  {                                    // vas de 69 degrès a 0 degrès par pas de 1 degrès
    myservo.write(pos);              // dire au servo de se positionner dans la variable 'pos'
    delay(100);                    // attendre 100ms que le servo atteigne sa position
    Serial.println(pos);
  }
 while (1);                      //arrete le programme
}

