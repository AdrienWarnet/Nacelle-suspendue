#include <Servo.h>

Servo esc; // création de l'objet permettant le controle de l'esc

int val = 0;



void setup() {
  esc.attach(9); // On attache l'ESC au port numerique 9 (port PWM obligatoire)
  delay(15);
  Serial.begin(9600);

  // Initialisation de l'ESC
  // (certain ESC ont besoin d'une "procédure d'initialisation" pour devenir opérationnel)
  esc.write(0);
  delay(1000);
  esc.write(180);
  delay(1000);
  esc.write(0);

  // Info pour l'utilisateur
  Serial.println("saisir un nombre entre 0 et 179");
  Serial.println("(0= arret - 179 = vitesse maxi");
  Serial.println("demarrage a partir de 20)");

}

void loop() {
  if (Serial.available() > 0) {
    val = Serial.parseInt(); // lecture de la valeur passée par le port série
    Serial.println(val);
    esc.write(val);
    delay(15);
  }

}
