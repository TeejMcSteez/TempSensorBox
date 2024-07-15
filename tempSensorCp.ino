#include <DHT.h>

// Pin definitions
#define DHTPIN 13
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

int A = 2;
int B = 3;
int C = 4;
int D = 5;
int E = 6;
int F = 7;
int G = 8;
int D1 = 9;
int D2 = 10;
int D3 = 11;
int D4 = 12;

void setup() {                
  // Initialize the digital pins as outputs
  pinMode(A, OUTPUT);     
  pinMode(B, OUTPUT);     
  pinMode(C, OUTPUT);     
  pinMode(D, OUTPUT);     
  pinMode(E, OUTPUT);     
  pinMode(F, OUTPUT);     
  pinMode(G, OUTPUT);   
  pinMode(D1, OUTPUT);  
  pinMode(D2, OUTPUT);  
  pinMode(D3, OUTPUT);  
  pinMode(D4, OUTPUT);

  Serial.begin(115200);
  Serial.println(F("Welcome to Teej's temperature sensor!"));
  dht.begin();
}

void loop() {
  float t = dht.readTemperature(true);

  if (isnan(t)) {
    return;
  }

  int temperature = int(t);

  displayTemperature(temperature);
  Serial.println("Temperature: ");
  Serial.println(temperature);
  delay(10); // Display temperature for .1 seconds
}

//start FUNCTIONS

void displayTemperature(int temperature) {
  int thousands = (temperature / 1000) % 10;
  int hundreds = (temperature / 100) % 10;
  int tens = (temperature / 10) % 10;
  int units = temperature % 10;

  //For debugging
  // Serial.print("Thousands: ");
  // Serial.println(thousands);
  // Serial.print("Hundreds: ");
  // Serial.println(hundreds);
  // Serial.print("Tens: ");
  // Serial.println(tens);
  // Serial.print("Units: ");
  // Serial.println(units);

  if (temperature >= 100) {
    displayDigit(hundreds, 1);
    delay(5);
    displayDigit(tens, 3);
    delay(5);
    lightReset();
    displayDigit(units, 4);
    delay(5);
  } else if (temperature >= 10) {
    displayDigit(tens, 1);
    delay(5);
    displayDigit(units, 3);
    delay(5);
  } else if (temperature >= 0){
    displayDigit(units, 1);
    delay(5);
  } else {
    displayDigit(0, 1);
    delay(5);
    displayDigit(0, 3);
    delay(5);
  }
}

void displayDigit(int digit, int position) {
  selectDigit(position);

  switch (digit) {
    case 0: displayNumber0(); break;
    case 1: displayNumber1(); break;
    case 2: displayNumber2(); break;
    case 3: displayNumber3(); break;
    case 4: displayNumber4(); break;
    case 5: displayNumber5(); break;
    case 6: displayNumber6(); break;
    case 7: displayNumber7(); break;
    case 8: displayNumber8(); break;
    case 9: displayNumber9(); break;
  }
}

void lightReset() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}


void selectDigit(int digit) {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);

  switch (digit) {
    case 1: digitalWrite(D1, LOW); break;
    case 2: digitalWrite(D2, LOW); break;
    case 3:
      digitalWrite(D3, LOW); //TODO!!!! --> there is either a coding or wiring problem the third digit on my setup and I am thinking it is a wiring problem. 
     break;
    case 4: digitalWrite(D4, LOW); break;
  }
}

void displayNumber0() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void displayNumber1() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void displayNumber2() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void displayNumber3() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}

void displayNumber4() {
  digitalWrite(A, LOW);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void displayNumber5() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void displayNumber6() {
  digitalWrite(A, HIGH);
  digitalWrite(B, LOW);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void displayNumber7() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW);
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void displayNumber8() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, HIGH);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}

void displayNumber9() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH);
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH);
  digitalWrite(E, LOW);
  digitalWrite(F, HIGH);
  digitalWrite(G, HIGH);
}