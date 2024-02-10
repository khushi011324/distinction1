const int pirPin1 = 2;
const int pirPin2 = 3;
const int soilMoisturePin = A0;
const int ledPin1 = 4;
const int ledPin2 = 5;
const int ledPin3 = 6;

void setup() {
  Serial.begin(9600);
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(soilMoisturePin, INPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
}

void loop() {
  int pirState1 = digitalRead(pirPin1);
  int pirState2 = digitalRead(pirPin2);
  int soilMoistureValue = analogRead(soilMoisturePin);

  Serial.println("PIR Sensor 1: " + String(pirState1));
  Serial.println("PIR Sensor 2: " + String(pirState2));
  Serial.println("Soil Moisture: " + String(soilMoistureValue));

  // Check PIR sensors
  if (pirState1 == HIGH) {
    digitalWrite(ledPin1, HIGH);
  } else {
    digitalWrite(ledPin1, LOW);
  }

  if (pirState2 == HIGH) {
    digitalWrite(ledPin2, HIGH);
  } else {
    digitalWrite(ledPin2, LOW);
  }

  // Check Soil Moisture
  if (soilMoistureValue < 500) {  // Adjust the threshold based on your sensor
    digitalWrite(ledPin3, HIGH);
  } else {
    digitalWrite(ledPin3, LOW);
  }

  delay(500);
}

