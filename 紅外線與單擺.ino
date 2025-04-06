int inPin=10;
int ledPin = 13;
int n=3;
int N=30;
int i=0;
int Val= HIGH;
int lastVal = HIGH;
long time[100];

void setup() {
  pinMode(inPin, INPUT);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  Serial.println("Measuring the period of simple pendulum");
}

void loop() {
  Val = digitalRead(inPin);
  if( Val==LOW && lastVal==HIGH){

    time[i] = millis();
    i=i+1;
    Serial.println(i);
    delay(50);
  }
  
  lastVal = Val;
  
  if(i>2*(n+N)){
    Serial.print("Start at :");
    Serial.println(n);
    Serial.print("End at:");
    Serial.println(N);
    int T = (time[2*(n+N)]-time[2*n])/N;
    Serial.print("the cycle of simple pendulum is:");
    Serial.print(T);
    Serial.print("ms");
    delay(100000);
  }

}
