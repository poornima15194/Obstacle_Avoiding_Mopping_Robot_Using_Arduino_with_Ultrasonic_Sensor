const int trigPin = 9;
const int echoPin = 10;
int m1p1= 6;
int m2p1= 7;
int Distance;
long duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Distance_Calc();
  if (distance >=20){
    digitalWrite(m1p1, HIGH);
    digitalWrite(m2p1, HIGH);
    Serial.println("Forward");
    }
  if (distance <=20){
    digitalWrite(m1p1, HIGH);
    digitalWrite(m2p1, LOW);
    Serial.println("Turn Right");
    delay(1000);
    digitalWrite(m1p1, HIGH);
    digitalWrite(m2p1, HIGH);
    Serial.println("Forward");
    if(distance <=3){
      digitalWrite(m1p1, LOW);
      digitalWrite(m2p1, HIGH);
      Serial.println("Turn Left");
      delay(5000);
      digitalWrite(m1p1, HIGH);
      digitalWrite(m2p1, HIGH);
      Serial.println("Forward");
    }
  }
}

int Distance_Calc(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;
  Serial.print("Distance: ");
  Serial.println(distance);
}
