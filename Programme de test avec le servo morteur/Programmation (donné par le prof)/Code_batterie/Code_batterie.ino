            //Code Batterie


const int buzzer = 10;                          //Buzzer sur la broche 10

void setup()
{
  pinMode(buzzer, OUTPUT);                      //Initialisation de la broche 10 comme étant une sortie
}

void loop() 
{ 
 int valeurlue = analogRead(A0);                //Lit la valeur de l'entrée analogique A0 (comprise entre 0 et  1023)
 float tensionlue = valeurlue * (5.0/1023);     //Conversion de la valeur retournée par la fonction en une tension
 float tensionreelle = tensionlue * 2;          //Calcule la valeur réelle de la différence de potentielle aux bornes de la batterie
  Serial.println(tensionreelle);                //Affiche la tension en tant que nombre décimal sous la forme d'une chaîne de caractères ASCII
  if (tensionreelle > 6.8)                      //Si la valeur de la tension au bornes de la batterie est supérieure à 6,8V
  {
    digitalWrite(buzzer,1);                     //Pas de signal sonore
  }
  else
  {
    while(1)
    {
    digitalWrite(buzzer,0);                    //Signal sonore
    delay(1000);                               //pendant 1s
    digitalWrite(buzzer,1);                    //Pas de signal sonore
    delay(120000);                             //pendant 2 minutes
    }
  }
}



