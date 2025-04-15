int redpin = 9, //select the pin for the red LED
    bluepin = 11, // select the pin for the blue LED
    greenpin = 10;// select the pin for the green LED
int rVal = 0,
    gVal = 128,
    bVal = 255;
int rFade = 3,
    gFade = 3,
    bFade = -3;
int buzzPin_3 = 3;   // the PWM pin the LED is attached to
int brightness = 0,  // how bright the LED is
    fadeAmount = 5;  // how many points to fade the LED by

void fade_led() {
  if ( brightness > 255 ) analogWrite(buzzPin_3, 255);
  else if ( brightness < 0 ) analogWrite(buzzPin_3, 0);
  else analogWrite(buzzPin_3, brightness);

  // change the brightness for next time through the loop:
  brightness = brightness + fadeAmount;

  // reverse the direction of the fading at the ends of the fade:
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
}
void fade_rgb() {
  if( rVal > 255 ) analogWrite(redpin, 255);
  else if ( rVal < 0 ) analogWrite(redpin, 0);
  else analogWrite(redpin, rVal);

  if( bVal > 255 ) analogWrite(bluepin, 255);
  else if ( bVal < 0 ) analogWrite(bluepin, 0);
  else analogWrite(bluepin, bVal);

  if( gVal > 255 ) analogWrite(greenpin, 255);
  else if ( gVal < 0 ) analogWrite(greenpin, 0);
  else analogWrite(greenpin, gVal);

  rVal = rVal + rFade;
  gVal = gVal + gFade;
  bVal = bVal + bFade;

  if( rVal <= 0 || rVal >= 255 ) rFade = -rFade;
  if( gVal <= 0 || gVal >= 255 ) gFade = -gFade;
  if( bVal <= 0 || bVal >= 255 ) bFade = -bFade;
}
void setup() {
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(buzzPin_3, OUTPUT);
  delay(25);
  }
void loop() 
{
  fade_led();
  fade_rgb();

  delay(50);  
}