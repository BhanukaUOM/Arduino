int SRCLK = 3;
int RCLK = 2;
int SER = 4;

void setup()
{
    pinMode(SRCLK, OUTPUT);
    pinMode(RCLK, OUTPUT);
    pinMode(SER, OUTPUT);

    sendSerialData(0);
}

void loop()
{
 
}

void clockpulse(){
  digitalWrite(RCLK, HIGH);
  delay(1);
  digitalWrite(RCLK, LOW);
  delay(1);
}

void latchpulse(){
  digitalWrite(SRCLK, HIGH);
  delay(1);
  digitalWrite(SRCLK, LOW);
  delay(1);
}

void sendSerialData(int data){
  for(int i=0; i<8; i++){
         digitalWrite(SER, HIGH);

      clockpulse();  //Pulse the Clock line
     
  }
  latchpulse();
}
