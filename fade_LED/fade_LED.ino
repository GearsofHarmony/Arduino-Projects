int buzzPin_3 = 3;   // the PWM pin the LED is attached to
int brightness = 0;  // how bright the LED is
int fadeAmount = 5;  // how many points to fade the LED by

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin_3, OUTPUT);
}

void loop() {
  if ( brightness > 255 ) analogWrite(buzzPin_3, 255);
  else if ( brightness < 0 ) analogWrite(buzzPin_3, 0);
  else analogWrite(buzzPin_3, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  // wait for 30 milliseconds to see the dimming effect
  delay(50);
}
