void setup() {
  // put your setup code here, to run once:
  pinMode(4, INPUT);
  pinMode(2, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(2) == HIGH)  
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);

  if(digitalRead(4) == HIGH)  
    digitalWrite(12, HIGH);
  else
    digitalWrite(12, LOW);
}
