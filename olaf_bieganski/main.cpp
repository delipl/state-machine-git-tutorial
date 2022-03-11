#define redPin 11
#define greenPin 9
#define bluePin 10
#define colorSwitch 2
#define powerSwitch 4

enum States{UNKNOWN=5, DISABLED=0, LEDR=1, LEDG=2, LEDB=3, DISCO=4};

States state = UNKNOWN;
boolean powerMode=false;
States nextState = LEDR;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(colorSwitch, INPUT);
  pinMode(powerSwitch, INPUT);
  Serial.begin(9600);
}

void loop()
{
  delay(50);
  powerMode = digitalRead(powerSwitch);
  delay(50);
  
  switch(state){
  case UNKNOWN:
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    state = DISABLED;
    break;
  case DISABLED:
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, LOW);
    digitalWrite(bluePin, LOW);
    Serial.println(powerMode);
    delay(500);
    if(digitalRead(powerSwitch)!= powerMode){
      powerMode = !powerMode;
      state=nextState;
    }
    break;
  case LEDR:
    if(digitalRead(powerSwitch)!= powerMode){
      powerMode = !powerMode;
      state = DISABLED;
      nextState = LEDR;
    }
    else if(digitalRead(colorSwitch) == HIGH){
      state = LEDB;
    }
    else{
      digitalWrite(redPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(greenPin, LOW);
    }
    break;
  case LEDB:
    if(digitalRead(powerSwitch)!= powerMode){
      powerMode = !powerMode;
      state = DISABLED;
      nextState = LEDR;
    }
    else if(digitalRead(colorSwitch) == HIGH){
      state = LEDG;
    }
    else{
      digitalWrite(bluePin, HIGH);
      digitalWrite(greenPin, LOW);
      digitalWrite(redPin, LOW);
    }
    break;
  case LEDG:
    if(digitalRead(powerSwitch)!= powerMode){
      powerMode = !powerMode;
      state = DISABLED;
      nextState = LEDR;
    }
    else if(digitalRead(colorSwitch) == HIGH){
      state = DISCO;
    }
    else{
      digitalWrite(greenPin, HIGH);
      digitalWrite(bluePin, LOW);
      digitalWrite(redPin, LOW);
    }
    break;
  case DISCO:
    if(digitalRead(powerSwitch)!= powerMode){
      powerMode = !powerMode;
      state = DISABLED;
      nextState = LEDR;
    }
    else if(digitalRead(colorSwitch) == HIGH){
      state = LEDR;
    }
    else{
      disco(redPin,greenPin,bluePin);
    }
    break;
  }
}

void disco(int redP, int greenP, int blueP){
  for(byte i=0; i<255; i++){
    analogWrite(redP, i);
    analogWrite(greenP, i+85);
    analogWrite(blueP, i+170);
    delay(2);
  }
  for(byte i=255; i<255; i--){
    analogWrite(redP, i);
    analogWrite(greenP, i+85);
    analogWrite(blueP, i+170);
    delay(2);
  }
}