#include <Servo.h>

Servo myservo;  
int pos = 0;   
#define PAUSE 5000

void setup() {
 myservo.attach(9);
}

void loop() {
   for (pos = 65; pos <= 78; pos += 1) { 
    myservo.write(pos);              
    delay(104);   
   }
    myservo.write(78);
    delay(PAUSE);  
   
    for (pos = 78; pos >= 60; pos -= 1) { 
      myservo.write(pos);              
      delay(104);                       
    }
}
      
