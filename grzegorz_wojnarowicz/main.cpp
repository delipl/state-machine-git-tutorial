//buttons pins numbers
const int onOffPin = 2;
const int colorPin = 3;

//leds pins numbers
const int redLed = 4;
const int greenLed = 5;
const int blueLed = 6;

void disco();

//states
enum States {
        UNKNOWN,            //all leds off 
        DISABLED,           //all leds and color button off
        LEDR,               //red led on, blue and green led off
        LEDG,               //green led on, blue and red led off
        LEDB,               //blue led on, red and green led off
        DISCO               //activate order 66
        };

States currentState = UNKNOWN;

//just for some disco
int pulse = 0; 


void setup() {
  // put your setup code here, to run once:
  
  pinMode(redLed, OUTPUT);             //red diode
  pinMode(greenLed, OUTPUT);             //green diode
  pinMode(blueLed, OUTPUT);             //blue diode

  pinMode(colorPin, INPUT);       //change color button
  pinMode(onOffPin, INPUT);       //on/off button

  //at the beggining everything is undefined
  currentState = UNKNOWN;

    Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  switch(currentState){
    case UNKNOWN:
        Serial.println("undefined");
        if(digitalRead(onOffPin) == HIGH){
          currentState = DISABLED;
          digitalWrite(redLed, LOW);
          digitalWrite(greenLed, LOW);
          digitalWrite(blueLed, LOW);
          delay(100);
        }else if(digitalRead(colorPin) == HIGH){
           currentState = LEDR;
          delay(100);
        }else{
         	digitalWrite(redLed, LOW);	
  			digitalWrite(greenLed, LOW);
  			digitalWrite(blueLed, LOW);
        }
      break;
    case DISABLED:
		Serial.println("off");
        if(digitalRead(onOffPin) == HIGH){
          currentState = UNKNOWN;
          digitalWrite(redLed, LOW);
          digitalWrite(greenLed, LOW);
          digitalWrite(blueLed, LOW);
          delay(100);
        }else if(digitalRead(colorPin) == LOW){
			digitalWrite(redLed, LOW);
            digitalWrite(greenLed, LOW);
            digitalWrite(blueLed, LOW);
        }else{
          
        }
      break;
    case LEDR:
		Serial.println("red");
        if(digitalRead(onOffPin) == HIGH){
          currentState = DISABLED;
          digitalWrite(redLed, LOW);
          digitalWrite(greenLed, LOW);
          digitalWrite(blueLed, LOW);
          delay(100);
        }else if(digitalRead(colorPin) == LOW){
          
          	digitalWrite(redLed, HIGH);
 			digitalWrite(greenLed, LOW);
 			digitalWrite(blueLed, LOW);
          
        }else{
            currentState = LEDG;
          	delay(100);
        }	
      break;
    case LEDG:
		Serial.println("green");
        if(digitalRead(onOffPin) == HIGH){
          currentState = DISABLED;
          digitalWrite(redLed, LOW);
          digitalWrite(greenLed, LOW);
          digitalWrite(blueLed, LOW);
          delay(100);
        }else if(digitalRead(colorPin) == LOW){
          
          	digitalWrite(redLed, LOW);
 			digitalWrite(greenLed, HIGH);
 			digitalWrite(blueLed, LOW);
        }else{
            currentState = LEDB;
          	delay(100);
        }	
      break;
    case LEDB:
		Serial.println("red");
        if(digitalRead(onOffPin) == HIGH){
          currentState = DISABLED;
          digitalWrite(redLed, LOW);
          digitalWrite(greenLed, LOW);
          digitalWrite(blueLed, LOW);
          delay(100);
        }else if(digitalRead(colorPin) == LOW){
          
          	digitalWrite(redLed, LOW);
 			digitalWrite(greenLed, LOW);
 			digitalWrite(blueLed, HIGH);
        }else{
            currentState = DISCO;
          	delay(100);
        }	
      break;
    case DISCO:
		Serial.println("BAYRAKTAR!!!");
        if(digitalRead(onOffPin) == HIGH){
          currentState = DISABLED;
          digitalWrite(redLed, LOW);
          digitalWrite(greenLed, LOW);
          digitalWrite(blueLed, LOW);
          pulse = 0;
          delay(100);
        }else if(digitalRead(colorPin) == LOW){
    		disco();
        	delay(100);  
        }else{
            currentState = LEDR;
          	pulse = 0;
          	delay(100);
        }	
      break;
  }
 
}

void disco(){
  pulse += 1;
    if(pulse % 2 == 0 && pulse % 3 != 0 && pulse % 5 != 0){
      digitalWrite(redLed, HIGH);             		
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
    } else if(pulse % 2 != 0 && pulse % 3 == 0 && pulse % 5 != 0){
      digitalWrite(redLed, LOW);             		
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
    }else if(pulse % 2 != 0 && pulse % 3 != 0 && pulse % 5 == 0){
      digitalWrite(redLed, LOW);             		
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
    }else if(pulse % 2 == 0 && pulse % 3 == 0 || pulse % 5 == 0 && pulse % 3 == 0 || pulse % 2 == 0 && pulse % 5 == 0){
      digitalWrite(redLed, HIGH);             		
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, HIGH);
    }else{
      digitalWrite(redLed, LOW);             		
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
    }
  }
              