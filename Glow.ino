#define b 9
#define g 10
#define r 11

#define pulseSpeedPin A3

#define bMaxPin A0
#define gMaxPin A1
#define rMaxPin A2

bool pulseUp = true;
int pulseSpeed = 0;

const byte redMax = 0;
const byte greenMax  = 0;
const byte blueMax  = 0;

const byte rgbMin = 7;

byte ledIncrement = 1;

byte rgbPower = 0;
int delayTime = 0;

long previousPowerChange = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);

  pinMode(rMaxPin, INPUT);
  pinMode(gMaxPin, INPUT);
  pinMode(bMaxPin, INPUT);

  Serial.begin(115200);
}

void loop() {
  //Serial.println("Power: " + String(ledPower));

  pulseSpeed = analogRead(pulseSpeedPin);
  Serial.println("Speed: " + String(pulseSpeed));

  if (pulseSpeed > 1000) {
    rgbPower = 255;
  }

  byte red = float(analogRead(rMaxPin) / 4) / 255 * rgbPower;
  red = red < rgbMin ? rgbMin : red;
  Serial.println("Red: " + String(red));
  byte green = float(analogRead(gMaxPin) / 4) / 255 * rgbPower;
  green = green < rgbMin ? rgbMin : green;
  Serial.println("Green: " + String(green));
  byte blue = float(analogRead(bMaxPin) / 4) / 255 * rgbPower;
  blue = blue < rgbMin ? rgbMin : blue;
  Serial.println("Blue: " + String(blue));

  analogWrite(r, red);
  analogWrite(g, green);
  analogWrite(b, blue);

  if (millis() > previousPowerChange + delayTime) {
    if (pulseUp) {
      if (rgbPower < 255) {
        rgbPower += ledIncrement;
      } else {
        pulseUp = false;
      }
    } else {
      if (rgbPower > 0) {
        rgbPower -= ledIncrement;
      } else {
        pulseUp = true;
      }
    }

    if (rgbPower == 0) {
      delayTime = 0;
    } else if (rgbPower < 4) {
      delayTime = pulseSpeed / 0;
    } else if (rgbPower < 8) {
      delayTime = pulseSpeed / 10;
    } else if (rgbPower < 16) {
      delayTime = pulseSpeed / 20;
    } else if (rgbPower < 32) {
      delayTime = pulseSpeed / 30;
    } else if (rgbPower < 64) {
      delayTime = pulseSpeed / 40;
    } else if (rgbPower < 128) {
      delayTime = pulseSpeed / 50;
    } else if (rgbPower < 255) {
      delayTime = pulseSpeed / 100;
    } else if (rgbPower == 255) {
      delayTime = pulseSpeed * 2.5;
    }

    previousPowerChange = millis();
  }

  //delay(1);
}
