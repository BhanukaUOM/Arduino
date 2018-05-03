#define FR 9
#define RR 6
#define RL 5
#define FL 3

#define IR 1
int irres;
const int trigPinM = 11;
const int echoPinM = 10;

long duration;
int distance;

void setup() {
  pinMode(FR, OUTPUT);
  pinMode(RR, OUTPUT);
  pinMode(RL, OUTPUT);
  pinMode(FL, OUTPUT);
  
  pinMode(trigPinM, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPinM, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication

}

void loop() {
  if(getDistanceM()>20 && irGet()>10){
    analogWrite(FR, 255);
    analogWrite(RR, 255);
    analogWrite(RL, 255);
    analogWrite(FL, 255);
  } else {
    analogWrite(FR, 0);
    analogWrite(RR, 0);
    analogWrite(RL, 0);
    analogWrite(FL, 0); 
  }
}

int getDistanceM(){
   // Clears the trigPin
  digitalWrite(trigPinM, LOW);
  delayMicroseconds(2);
  
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPinM, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinM, LOW);
  
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPinM, HIGH);
  
  // Calculating the distance
  distance= duration*0.034/2;
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}

int irGet(){
  irres = (analogRead(IR) - 220)/17;
  Serial.print("IR: ");
  Serial.println(irres);
  return irres;
}

