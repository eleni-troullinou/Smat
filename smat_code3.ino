
int led1 = 2;
int led2 = 3;
int led3 = 4;
int fsr = A0;
int fsrReading;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);          
}                                                               

// the loop function runs over and over again forever
void loop() {
  fsrReading = analogRead(fsr);
  Serial.println("Analog reading = ");
  Serial.println(fsrReading);

  if (fsrReading > 0 && fsrReading < 20){
    Serial.println("squeeze light");
    digitalWrite(led1, HIGH);   //turn the LED on (HIGH is the voltage level)
    digitalWrite(led2, LOW); 
    digitalWrite(led3, LOW);
    delay(1000);                                              
  }else if(fsrReading >= 20 && fsrReading < 50){
    Serial.println("squeeze medium");
    digitalWrite(led2, HIGH); 
    digitalWrite(led1, LOW);
    digitalWrite(led3, LOW);
    delay(1000);                                                 
   }else if(fsrReading >= 50){
    Serial.println("squeeze high");
    digitalWrite(led3, HIGH); 
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW); 
    delay(1000);
  }else{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } 
  
  
}
