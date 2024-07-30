const int lightSensorPin = A0;  // Analog pin connected to the photoresistor
const int ledPin = 3;           // Digital pin connected to the LED
const int buttonPin = 2;        // Digital pin connected to the button (interrupt pin)
const int threshold = 500;      // Light level threshold

volatile bool updateFlag = false;
volatile bool buttonPressed = false; // Flag to track button state

void setup() {
  pinMode(ledPin, OUTPUT);         // Set the LED pin as an output
  pinMode(buttonPin, INPUT_PULLUP); // Set the button pin as input with internal pull-up resistor
  Serial.begin(9600);              // Initialize serial communication at 9600 baud
  
  // Set up pin change interrupt on pin 2
  attachInterrupt(digitalPinToInterrupt(buttonPin), handleButtonPress, FALLING); // Attach interrupt to pin 2
}

void loop() {
  // Main loop checks the flag and updates the LED state accordingly
  if (updateFlag) {
    int lightLevel = analogRead(lightSensorPin);  // Read the value from the photoresistor
    Serial.print("Light Level: ");                // Print the light level to the Serial Monitor
    Serial.println(lightLevel);

    if (lightLevel < threshold) {                 // Check if the light level is below the threshold
      digitalWrite(ledPin, HIGH);                 // Turn the LED on
      Serial.println("LED is ON");
    } else {
      digitalWrite(ledPin, LOW);                  // Turn the LED off
      Serial.println("LED is OFF");
    }
    updateFlag = false; // Reset the flag
    buttonPressed = false; // Reset the button state flag
  }
}

// Interrupt service routine (ISR)
void handleButtonPress() {
  if (!buttonPressed) { // Check if the button was not already pressed
    updateFlag = true;  // Set the flag to update the light level in the main loop
    buttonPressed = true; // Set the button state flag
  }
}
