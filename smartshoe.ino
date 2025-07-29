const int trigPin = 9;
const int echoPin = 10;
const int buzzerPin = 11;
const int vibrationPin = 6;
const int buttonPin = 5;
int buttonState = 0;
int intensity = 0;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
  long duration, distance;


  buttonState = digitalRead(buttonPin);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

 
  distance = duration * 0.034/2;
  
  Serial.println(distance);

  if(distance > 100) {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(vibrationPin, LOW);
  }
  
  if(distance < 100) {
    intensity = map(distance, 0, 100, 255, 0);
    analogWrite(vibrationPin, intensity);
    analogWrite(buzzerPin, intensity);
  }
  if(buttonState == LOW) {
    digitalWrite(buzzerPin, LOW);
  } 
 

delay(100);


}