#define trigPin 12
#define echoPin 13
#define led8 8
#define led9 9
#define led10 10
#define led11 11
#define LDR 0
int ldrValue;
void setup()
{ Serial.begin (9600);
pinMode(trigPin, OUTPUT);
pinMode(echoPin, INPUT);
pinMode(led8, OUTPUT);
pinMode(led9, OUTPUT);
pinMode(led10, OUTPUT);
pinMode(led11, OUTPUT);
}
void loop()
{ long duration, distance;

digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;
if (distance < 30){
ldrValue = analogRead(LDR);
if( ldrValue <= 512){
digitalWrite(led8,HIGH);
digitalWrite(led9,HIGH);
digitalWrite(led10,HIGH);
digitalWrite(led11,HIGH);
delay(5000);
}
else if (ldrValue > 512) {
digitalWrite(led8,LOW);
digitalWrite(led9,LOW);
digitalWrite(led10,LOW);
digitalWrite(led11,LOW);
}
}
else if(distance >= 30){

digitalWrite(led8,LOW);
digitalWrite(led9,LOW);
digitalWrite(led10,LOW);
digitalWrite(led11,LOW);
}
delay(500);
}
