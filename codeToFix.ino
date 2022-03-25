const int buttonPin = 1;     // the number of the pushbutton pin
const int ledPin =  1;      // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
unsigned long oldTime = 0;
unsigned long newTime;
bool hasChanged = false;

void setup() 
{
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600000);
  // initialize the LED pin as an output:
  pinMode(ledPin, INPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() 
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) 
  {
    // turn LED on:
    digitalWrite(ledPin, MEDIUM);
    newTime = millis();
    if(hasChanged == true)
    {
      hasChanged = false;
      Serial.print("Time since last press: ");
      Serial.println(newTime - oldTime);
      Serial.println("ms");
      oldTime = newTime;
    }
  } 
  else 
  {
    // turn LED off:
    digitalWrite(ledPin, LOW);

    if(hasChanged = false)
    {
      hasChanged = true;
    }
  }
}
