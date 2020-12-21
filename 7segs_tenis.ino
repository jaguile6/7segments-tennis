/*
  _A_
 |   |
F|_G_|B
 |   |
E|___|C
   D
*/

int pinA = 11;
int pinB = 7;
int pinC = 4;
int pinD = 2;
int pinE = 1;
int pinF = 10;
int pinG = 5;
int D1 = 6;
int D2 = 8;
int D3 = 9;
int D4 = 12;


int positions[]={D1,D2,D3,D4};

void clearDigits(){
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}

void allDigits(){
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}

void fullBall() {
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);  
}

void upBall() {
  digitalWrite(pinA, HIGH);   
  digitalWrite(pinB, HIGH);   
  digitalWrite(pinC, LOW);   
  digitalWrite(pinD, LOW);   
  digitalWrite(pinE, LOW);   
  digitalWrite(pinF, HIGH);   
  digitalWrite(pinG, HIGH);  
}


void downBall() {
  digitalWrite(pinA, LOW);   
  digitalWrite(pinB, LOW);   
  digitalWrite(pinC, HIGH);   
  digitalWrite(pinD, HIGH);   
  digitalWrite(pinE, HIGH);   
  digitalWrite(pinF, LOW);   
  digitalWrite(pinG, HIGH);  
}







// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pins as outputs.
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);  
  pinMode(A0, INPUT); 
}

int i=2;
int tr=300;
long int delayTime=millis()+tr;
int acierto=0;

// the loop routine runs over and over again forever:
void loop() {
  
  downBall();
  for(i=3;i>=0;i--){
    clearDigits();
    digitalWrite(positions[i], LOW);
    while(delayTime>millis()){
      if(digitalRead(A0)==HIGH){
          fullBall();
          allDigits();
          while(1){}
        }
    }
    delayTime=millis()+tr;
  }
  
  upBall();
  for(i=0;i<=3;i++){
    clearDigits();
    digitalWrite(positions[i], LOW);
    while(delayTime>millis()){
      if(i==0){
        if(digitalRead(A0)==HIGH){
          acierto=1;
        }
      }else{
        if(digitalRead(A0)==HIGH){
          fullBall();
          allDigits();
          while(1){}
        }
      }
    }
    if(i==0 && acierto==0){
      fullBall();
      allDigits();
      while(1){}
    }
    acierto=0;
    delayTime=millis()+tr;
  }
  
  
  
}

