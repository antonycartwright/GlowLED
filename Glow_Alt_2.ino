#define rPin 9
#define gPin 8
#define bPin 7

bool rState = false;
bool gState = false;
bool bState = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.setTimeout(10);

  pinMode(rPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(bPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if (Serial.available()) {
    String str = Serial.readString();
    if (str.indexOf("red") > -1) {
      rState = !rState;
      digitalWrite(rPin, rState);
      Serial.print("Red is " + String(rState ? "ON" : "OFF"));
    } else if (str.indexOf("green") > -1) {
      gState = !gState;
      digitalWrite(gPin, gState);
      Serial.print("Green is " + String(gState ? "ON" : "OFF"));
    } else if (str.indexOf("blue") > -1) {
      bState = !bState;
      digitalWrite(bPin, bState);
      Serial.print("Blue is " + String(bState ? "ON" : "OFF"));
    }
  }

  delay(1);
}
