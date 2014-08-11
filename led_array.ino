// Each number corresponds to a pin number that's conneceted to the LED anode.
int leds[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2};

// used in accelerate rate of led change in 'accelerate' function.
int start_time = 1200;

// prime the pins to be used
void setup() {
  for (int i = 0; i < 12; i++) {
    pinMode(leds[i], OUTPUT);
  }
}

// this loop runs forever
void loop() {
  traverse(10);
  delay(600);
  
  accelerate();
  delay(600);
  
  light_all_colors();
  delay(600);
}


// this function lights up one LED and then turns it off very quickly
void traverse(int iterations){
  for (int it = iterations; it > 0; it--) {
    for (int i = 0; i < 12; i++) {
      pinMode(leds[i], OUTPUT);
      digitalWrite(leds[i], HIGH);   // turn the leds on (HIGH is the voltage level)
      delay(10);                     // wait for 1/100th of a second aka 10 miliseconds
      digitalWrite(leds[i], LOW);    // turn the leds off by making the voltage LOW
      delay(10);                     // wait for 1/100th of a second aka 10 miliseconds
    }
  }
}


// this function lights up one LED and then turns it off
// then moves on to the next LED
// with each LED, the time until it lights up the next LED is reduced by 50%
void accelerate(){
  for (int i = 0; i < 12; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);      // turn the leds on (HIGH is the voltage level)
    delay(start_time / 2);            // wait
    digitalWrite(leds[i], LOW);       // turn the leds off by making the voltage LOW
    delay(start_time / 2);            // wait for a second
    start_time = start_time - 100;
  }
  start_time = 1200;
}


// this function lights up all the LEDs at once then turns them all off
void light_all_colors(){
  for (int i = 0; i < 12; i++) {
    pinMode(leds[i], OUTPUT);
    digitalWrite(leds[i], HIGH);
  }
  
   delay(600);
  
   for (int i = 0; i < 12; i++) {
    digitalWrite(leds[i], LOW);    // turn the leds off by making the voltage LOW
   }
}
