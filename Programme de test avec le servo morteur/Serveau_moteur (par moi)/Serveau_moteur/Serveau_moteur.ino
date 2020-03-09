#include <Servo.h>  //library servo standard

const int POS_MIN=550; //largeur impulsion pour position 0° servomoteur
const int POS_MAX=2230; // largeur impulsion pour position 180° servomoteur
                          //POS_MAX=2330 et POS_MIN=550 pour futuba S3003
const int SERVO=2; //déclaration constante de broche 


int ReceptionOctet=0; // variable de stockage des octets reçus par port série
int ReceptionNombre=0; // variable de calcul du nombre reçu par port série

int impulsion=1500; // variable pour impulsion - valeur médiane initiale

Servo mon_servo; // crée un objet servo pour controler le servomoteur

void setup() {
  mon_servo.attach(broche_servo, POS_MIN, POS_MAX); //attache l'objet servo à la broche de commande du servomoteur
  pinMODE(servo, OUTPUT); //met la broche en sortie
  

}

void loop() {
  //--- Lecture d'un nombre reçu par le terminal et positionnement du servomoteuur--
  if (serial.avaible()>0) {// si caractère dans la file d'attente
    //---
  }

}
