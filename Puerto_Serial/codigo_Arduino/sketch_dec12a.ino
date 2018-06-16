int option;
int led1 = 2;
int buttonPin1 = 3;
int buttonState1 = 0;
int led2 = 4;
int buttonPin2 = 5;
int buttonState2 = 0;
int led3 = 6;
int buttonPin3 = 7;
int buttonState3 = 0;
int led4 = 8;
int buttonPin4 = 9;
int buttonState4 = 0;
 
void setup(){
  Serial.begin(9600);
  pinMode(led1, OUTPUT); 
  pinMode(buttonPin1, INPUT);
  pinMode(led2, OUTPUT); 
  pinMode(buttonPin2, INPUT);
  pinMode(led3, OUTPUT); 
  pinMode(buttonPin3, INPUT);
  pinMode(led4, OUTPUT); 
  pinMode(buttonPin4, INPUT);
}
 
void loop(){
  if (Serial.available()>0){
    //leemos la opcion enviada
    option=Serial.read();
    if(option=='a') {
      digitalWrite(led1, LOW);
      Serial.println("OFF");
    }
    if(option=='b') {
      digitalWrite(led1, HIGH);
      Serial.println("ON");
    }
    /////////////////////////////////////////
    if(option=='c') {
      digitalWrite(led2, LOW);
      Serial.println("OFF");
    }
    if(option=='d') {
      digitalWrite(led2, HIGH);
      Serial.println("ON");
    }
    ////////////////////////////////////////
    if(option=='e') {
      digitalWrite(led3, LOW);
      Serial.println("OFF");
    }
    if(option=='f') {
      digitalWrite(led3, HIGH);
      Serial.println("ON");
    }
    ////////////////////////////////////////
    if(option=='g') {
      digitalWrite(led4, LOW);
      Serial.println("OFF");
    }
    if(option=='h') {
      digitalWrite(led4, HIGH);
      Serial.println("ON");
    }
  }
  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);
  buttonState3 = digitalRead(buttonPin3);
  buttonState4 = digitalRead(buttonPin4);
  if (buttonState1 == HIGH) {
  Serial.println("Rojo");
  delay(500);
  }
  if (buttonState2 == HIGH) {
  Serial.println("Azul");
  delay(500);
  }
  if (buttonState3 == HIGH) {
  Serial.println("Amarillo");
  delay(500);
  }
  if (buttonState4 == HIGH) {
  Serial.println("Verde");
  delay(500);
  }
}
