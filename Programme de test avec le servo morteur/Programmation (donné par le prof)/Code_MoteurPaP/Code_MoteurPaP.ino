
// commande moteur pas à pas bipolaire avec Arduino-MotorShield
#define DIRA 12
#define DIRB 13
#define BRAKEA 9
#define BRAKEB 8 
#define PWMA 3
#define PWMB 11
#define VAL 100

int etape;

void pas_une_phase(int etape) { // pas One Phase ON
  switch (etape) {
    case 0 : // 1000
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,HIGH);
    digitalWrite(DIRA,HIGH);
    break;
    case 1 : // 0010
    digitalWrite(BRAKEA,HIGH);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRB,HIGH);
    break;
    case 2 : // 0100
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,HIGH);
    digitalWrite(DIRA,LOW);
    break;
    case 3 : // 0001
    digitalWrite(BRAKEA,HIGH);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRB,LOW);
    break;
  }  
}

void pas_deux_phases(int etape) { // pas One Phase ON
  switch (etape) {
    case 0 : // 1010
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,HIGH);
    break;
    case 1 : // 0110
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
    break;
    case 2 : // 0101
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,LOW);
    break;
    case 3 : // 1001
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
    break;
  }  
}

void pas_demi_pas(int etape) {
  switch(etape) {
    case 0 : // 1000
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,HIGH);
    digitalWrite(DIRA,HIGH);
    break;
    case 1: // 1010
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,HIGH);
    break;
    case 2: // 0010
    digitalWrite(BRAKEA,HIGH);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRB,HIGH);
    break;
    case 3: // 0110
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,HIGH);
    break;
    case 4: //0100
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,HIGH);
    digitalWrite(DIRA,LOW);
    break;
    case 5: //0101
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,LOW);
    digitalWrite(DIRB,LOW);
    break;
    case 6: //0001
    digitalWrite(BRAKEA,HIGH);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRB,LOW);
    break;
    case 7: //1001
    digitalWrite(BRAKEA,LOW);
    digitalWrite(BRAKEB,LOW);
    digitalWrite(DIRA,HIGH);
    digitalWrite(DIRB,LOW);
    break;
  }  
}

void pas_une_phase_sens_1() {
  etape++;
  if (etape>3) etape = 0;
  pas_une_phase(etape);  
}

void pas_une_phase_sens_2() {
  etape--;
  if (etape<0) etape = 3;
  pas_une_phase(etape);  
}

void pas_deux_phases_sens_1() {
  etape++;
  if (etape>3) etape = 0;
  pas_deux_phases(etape);  
}

void pas_deux_phases_sens_2() {
  etape--;
  if (etape<0) etape = 3;
  pas_deux_phases(etape);  
}

void pas_demi_pas_sens_1() {
  etape++;
  if (etape>7) etape = 0;
  pas_demi_pas(etape);  
}

void pas_demi_pas_sens_2() {
  etape--;
  if (etape<0) etape = 7;
  pas_demi_pas(etape);  
}

void pwm(int pwm) {
  analogWrite(PWMA,pwm);
  analogWrite(PWMB,pwm); 
}

void setup() {
  pinMode(DIRA,OUTPUT); 
  pinMode(DIRB,OUTPUT);
  pinMode(BRAKEA,OUTPUT);
  pinMode(BRAKEB,OUTPUT);
  pinMode(PWMA,OUTPUT);
  pinMode(PWMB,OUTPUT);
  analogWrite(PWMA,0);
  analogWrite(PWMB,0);
  etape = 0;
}

void loop() {
  int k;
  unsigned int duree_courant = 10;
  unsigned long duree_pas = 20;
  unsigned long temps;
  
  for (k=0; k<67; k++) {
    temps = millis();
    pas_une_phase_sens_2();
    pwm(255); // courant max
    while (millis()-temps < duree_courant) {
          // autre chose à faire pendant le pas moteur
    }
  }

  for (k=0; k<67; k++) {
    temps = millis();
    pas_une_phase_sens_1();
    pwm(255); // courant max
    while (millis()-temps < duree_courant) {
          // autre chose à faire pendant le pas moteur
    }
  }


}
                
