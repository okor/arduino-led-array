/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */
 
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int led[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};
// used in accelerate
int start_time = 1200;

// the setup routine runs once when you press reset:
void setup() {
  for (int i = 0; i < 12; i++) {
    pinMode(led[i], OUTPUT);
  }
}

// the loop routine runs over and over again forever:
void loop() {
  traverse(10);
  delay(600);
  
  accelerate();
  delay(600);
  
  light_all_colors();
  delay(600);
}



void traverse(int iterations){
  for (int it = iterations; it > 0; it--) {
    for (int i = 0; i < 12; i++) {
      pinMode(led[i], OUTPUT);
      digitalWrite(led[i], HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(10);               // wait for a second
      digitalWrite(led[i], LOW);    // turn the LED off by making the voltage LOW
      delay(10);               // wait for a second
    }
  }
}


void accelerate(){
  for (int i = 0; i < 12; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(start_time / 2);               // wait for a second
    digitalWrite(led[i], LOW);    // turn the LED off by making the voltage LOW
    delay(start_time / 2);               // wait for a second
    start_time = start_time - 100;
  }
  start_time = 1200;
}

void light_all_colors(){
  for (int i = 0; i < 12; i++) {
    pinMode(led[i], OUTPUT);
    digitalWrite(led[i], HIGH);
  }
  
   delay(600);
  
   for (int i = 0; i < 12; i++) {
    digitalWrite(led[i], LOW);    // turn the LED off by making the voltage LOW
   }
}
