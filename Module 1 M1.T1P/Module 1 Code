// C++ code
//

const int lightSensorPin = A0;  // Analog pin connected to the photoresistor
const int ledPin = 3;           // Digital pin connected to the LED
const int threshold = 500;      // Light level threshold

void setup() {
  pinMode(ledPin, OUTPUT);      // Set the LED pin as an output
  Serial.begin(9600);           // Initialize serial communication at 9600 baud
}

void loop() {
  int lightLevel = analogRead(lightSensorPin);  // Read the value from the photoresistor
  Serial.print("Light Level: ");                // Print the light level to the Serial Monitor
  Serial.println(lightLevel);

  if (lightLevel < threshold) {                 // Check if the light level is below the threshold
    digitalWrite(ledPin, HIGH);                 // Turn the LED on
  } else {
    digitalWrite(ledPin, LOW);                  // Turn the LED off
  }

  delay(1000);                                  // Wait for 1 second before repeating
}
