#include <Servo.h>   //library servo standard

int PIN_PUSH_VERSE  = 8; // bouton poussoir
int PIN_SVERSE      = 9; //PIN affecte au servo

Servo mySVERSE;     //note servomoteur

int Poussoir_VERSE = 1 //en cas d'appui passe à 0


void setup() {
  // initialisation des PIN 
  pinMode(PIN_PUSH_VERSE, INPUT); //Le PIN est en lecture
  digitalWrite(PIN_PUSH_VERSE, HIGH); // le PIN est en sortie

  //activation du servomoteur
  mySVERSE.attach(PIN_SVERSE);

  //on met le servo à l'angle de départ
  mySVERSE.write(0);  // 0 est l'angle de repos
  
}

void loop() {
  //commande le vidage dubac
  poussoir_VERSE = digitalRead(PIN_PUSH_VERSE); //Lecture de l'état
  if (poussoir_VERSE == LOW) (
         //Le poussoir est appuyé donc il marche 
  mySVERSE.write(90);  // Rotation de 90 degrès 
  delay(2000);       //attendre 2 sec 
  mySVERSE.write(0); // retour position de départ
  
  

}
