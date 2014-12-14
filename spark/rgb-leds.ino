/*

 Toggle 3 LEDs (red, green, and blue) with button presses

 Button presses are debounced using a *bounceTime* msec debounce window.
 Note that due to the millis() function overflowing after approximately
 50 days, there is *bounceTime* msec window that will repeat
 approximately every 50 days where a valid button press would not
 be registered.

 Created by CMA 04/17/2014

*/

// Constant LED pins
const int redLED = 10;
const int greenLED = 11;
const int blueLED = 12;
// Constant buttons
const int redButton = 0;
const int greenButton = 1;
const int blueButton = 2;
// LED state booleans

// Variable LED states
boolean redLEDState = LOW;
boolean greenLEDState = LOW;
boolean blueLEDState = LOW;
// Variable button states
long redPressTime = 0;
long greenPressTime = 0;
long bluePressTime = 0;

long loopTime = 0;
long bounceTime = 400;
//abs();
//millis();

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redButton, INPUT);
  pinMode(greenButton, INPUT);
  pinMode(blueButton, INPUT);
}


void loop() {

  loopTime = millis();

  // Red control
  if (digitalRead(redButton) == HIGH && (abs(redPressTime - loopTime) > bounceTime)) {
    redPressTime = loopTime;
    redLEDState = !redLEDState;
    digitalWrite(redLED, redLEDState);
  }

  // Green control
  if (digitalRead(greenButton) == HIGH && (abs(greenPressTime - loopTime) > bounceTime)) {
    greenPressTime = loopTime;
    greenLEDState = !greenLEDState;
    digitalWrite(greenLED, greenLEDState);
  }

  // Blue control
  if (digitalRead(blueButton) == HIGH && (abs(bluePressTime - loopTime) > bounceTime)) {
    bluePressTime = loopTime;
    blueLEDState = !blueLEDState;
    digitalWrite(blueLED, blueLEDState);
  }

}
