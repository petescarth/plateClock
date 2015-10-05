/*
A very simple analog clock for Arduino. 
Uses 12 LEDs on pins 1-12 to indicate both the hour and 5 minute intervals
The minute indicator flashes every second so you know ;)
Peter Scarth
*/

int second=0, minute=0, hour=0; //start the time on 00:00:00
int valm=0;
int valh=0;
int i= 0;
boolean tick = true;

void setup() { //set outputs and inputs
pinMode(1, OUTPUT);pinMode(2, OUTPUT);pinMode(3, OUTPUT);pinMode(4, OUTPUT);pinMode(5, OUTPUT);
pinMode(6, OUTPUT);pinMode(7, OUTPUT);pinMode(8, OUTPUT);pinMode(9, OUTPUT);pinMode(10, OUTPUT);
pinMode(11, OUTPUT);pinMode(12, OUTPUT);pinMode(13, OUTPUT);

pinMode(14, INPUT);
pinMode(15, INPUT);
digitalWrite(14, HIGH);
digitalWrite(15, HIGH);
}


void loop() {

static unsigned long lastTick = 0; // set up a local variable to hold the last time we moved forward one second
// move forward one second every 1000 milliseconds

if (millis() - lastTick >= 1000) {
  lastTick = millis();
  second++;
  tick = !tick;
}

// move forward one minute every 60 seconds
  if (second >= 60) {
  minute++;
  second = 0; // reset seconds to zero
}

// move forward one hour every 60 minutes
if (minute >=60) {
  hour++;
  minute = 0; // reset minutes to zero
}

if (hour >=12) {
  hour=0;
  minute = 0; // reset minutes to zero
}

// Flash the minute led   
for (i = 1; i < 13; i++) {
  if(minute >= ((i - 1) * 5)  && minute < (i * 5) && tick) {
  digitalWrite(i, HIGH);
   } else {
  digitalWrite(i, LOW);
   }
   }

// Light up the hour led
for (i = 1; i < 13; i++) {
  if(hour >= (i - 1)  && hour < i) {
  digitalWrite(i, HIGH);
   } else {
  digitalWrite(i, LOW);
   }
   }
   

// Seconds Indication on the built in pin 13 LED
digitalWrite(13, tick);

// Set the time using buttons on pins 14 and 15
  valm = digitalRead(14);    // add one minute when button on pin 14 pressed
   if(valm== LOW) {
   minute++;
   second=0;
   delay(250);
  }
  
  valh = digitalRead(15);    // add one hour when button on pin 15 is pressed
   if(valh==LOW) {
   hour++;
   second=0;
   delay(250);
  }


}
