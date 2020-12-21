//---------------------Code to define initial state------------------------------------------
// this constant won't change:
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to
const int solenoidPin = 4;   // the pin that the TIP120 transistor's base is attached to (for solenoid)
int i = 0;

// Variables will change:
int buttonPushCounter = 0;   // counter for the number of button presses
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  pinMode(solenoidPin, OUTPUT);
  // initialize serial communication:
  Serial.begin(9600);
}

//--------------------Code to manipulate the behavior of the button ---------------------------
void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("Stage of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  
//---------------------Code to actually influence the state of the box during ON/OFF ---------------------------
  //Turn on systen when being pressed once
  if (buttonPushCounter % 2 == 0) {
    //Setting Required Pins to HIGH - The system is ON and ready to unlock
    digitalWrite(ledPin, HIGH); 
    digitalWrite(solenoidPin, HIGH);
    while(i<1000){Serial.println("i:"); Serial.println(i);
      i++;
    }
    buttonPushCounter=1;
    i = 0;
    //Setting Button Pin back to HIGH - resetting the state of the button
    digitalWrite(buttonPin, HIGH);
    Serial.println("on");
    Serial.print("number of button pushes: ");
    Serial.println(buttonPushCounter);

    //Setting Required Pins to LOW - The system is OFF and ready to lock the box
    digitalWrite(ledPin, LOW);
    digitalWrite(solenoidPin, LOW);
  } 
}