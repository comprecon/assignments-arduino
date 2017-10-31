#define trigPin 9 
#define echoPin 8 

const int RED_PIN = 4;
const int GREEN_PIN = 3;
const int BLUE_PIN = 2;

const int buzzer = 7;

int maxDistance = 30; 
int minDistance = 2;  
long microSecond, cmDistance; 
int ledTime = 100;

void setup() {
 Serial.begin (9600); 
 pinMode(trigPin, OUTPUT); 
 pinMode(echoPin, INPUT); 

pinMode(RED_PIN, OUTPUT);
pinMode(GREEN_PIN, OUTPUT);
pinMode(BLUE_PIN, OUTPUT);



 }
void loop() {
 digitalWrite(trigPin, LOW); 
 delayMicroseconds(2); 
 digitalWrite(trigPin, HIGH); 
 delayMicroseconds(10); 
 digitalWrite(trigPin, LOW); 
 microSecond = pulseIn(echoPin, HIGH); 
 cmDistance = microSecond/58.3; 
 if (cmDistance >= maxDistance) 
 {
 Serial.println("....>30cm");
  digitalWrite(RED_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  digitalWrite(BLUE_PIN, LOW);
  
  delay(ledTime);

  noTone(buzzer);
 
 }
 else if (cmDistance <= maxDistance) 
 {
  Serial.println("5 cm");
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  digitalWrite(BLUE_PIN, LOW);

  tone(buzzer, 900, 700);

  
  delay(ledTime);
  }
 else if (cmDistance <= minDistance)
 {
  Serial.println("....< 2cm");   
 }
 else {
 Serial.print(cmDistance); 
 Serial.println(" cm"); 
 }
   delay(100);   
 }
