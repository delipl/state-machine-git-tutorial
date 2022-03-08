#include <Arduino.h>
#include <stdint.h>
#include <ArduinoJson.h>
#include <SoftwareSerial.h>


const int blueled = 6;
const int redled = 4;
const int greenled = 5;
const int button1 = 2;
const int button2 = 3;
void button1_service();
void button2_service();
int timer = 0;
void disco();

enum States { UNKN , // nie wiadomo co sie dzieje
              DISABLED , // wylaczona dioda
              LEDR , // zapal c z e r w o n
              LEDG , // zapal z i e l o n
              LEDB , // zapal n i e b i e s k
              DISCO };

States state = UNKN;

void setup() {
  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);

  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  attachInterrupt(0, button1_service, FALLING);
  attachInterrupt(1, button2_service, FALLING);
  Serial.begin(9600);
}

void loop() {
 
  switch ( state ){
      case UNKN :
        break ;
      case DISABLED :
        digitalWrite(redled, LOW);
        digitalWrite(blueled, LOW);
        digitalWrite(greenled, LOW);
        break ;
      case LEDR :
        digitalWrite(redled, HIGH);
        digitalWrite(blueled, LOW);
        digitalWrite(greenled, LOW);
        break ;
      case LEDG :
        digitalWrite(redled, LOW);
        digitalWrite(blueled, LOW);
        digitalWrite(greenled, HIGH);
        break ;
      case LEDB :
        digitalWrite(redled, LOW);
        digitalWrite(blueled, HIGH);
        digitalWrite(greenled, LOW);
        break ;
      case DISCO :
        disco();
        break ;
  }
} 

void button1_service()
{
  state = DISABLED;
}

void button2_service()
{
  switch ( state ){
      case UNKN :
        state = LEDR;
        break ;
      case DISABLED :
        state = LEDR;
        break ;
      case LEDR :
        state = LEDG;
        break ;
      case LEDG :
        state = LEDB;
        break ;
      case LEDB :
        state = DISCO;
        break ;
      case DISCO :
        state = LEDR;
        break ;
  }
}
void disco()
{
  int r = 45;
  int g = 179;
  int b = 78;
  for(int i = 0; i < 6; ++i){
    r = (r + 83) % 255;
    g = (g + 91) % 255;
    b = (b + 57) % 255;
    analogWrite(redled, r);
    analogWrite(blueled, g);
    analogWrite(greenled, b);
    delay(50);
  }
}
