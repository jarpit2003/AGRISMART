int moisture = 0;
float moisturePercentage = 0.0;
const int minMoisture = 0;   
const int maxMoisture = 872;

void setup()
{
  pinMode(A0, OUTPUT); 
  pinMode(A1, INPUT);  
  Serial.begin(9600);  

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop()
{
  digitalWrite(A0, HIGH);
  delay(10); 

  moisture = analogRead(A1);

  digitalWrite(A0, LOW);

  moisturePercentage = map(moisture, minMoisture, maxMoisture, 0, 100);

  moisturePercentage = constrain(moisturePercentage, 0, 100);
  Serial.print("Soil Moisture Percentage: ");
  Serial.println(moisturePercentage);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  if (moisturePercentage < 20) {
    digitalWrite(12, HIGH); // Very dry
  } else if (moisturePercentage < 40) {
    digitalWrite(11, HIGH); // Dry
  } else if (moisturePercentage < 60) {
    digitalWrite(10, HIGH); // Moist
  } else if (moisturePercentage < 80) {
    digitalWrite(9, HIGH);  // Wet
  } else {
    digitalWrite(8, HIGH);  // Very wet
  }

  delay(100);
}
