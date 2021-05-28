#define b 9
#define g 10
#define r 11

void setup() {
  // put your setup code here, to run once:
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i < 254) {
    digitalWrite(r, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
  delay(1000);

  digitalWrite(r, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);

  delay(500);

  for (int i = 0; i < 254) {
    digitalWrite(r, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, HIGH);
  }

  delay(1000);

  digitalWrite(r, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);

  delay(500);

  for (int i = 0; i < 254) {
    digitalWrite(r, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
  }

  delay(1000);

  digitalWrite(r, HIGH);
  digitalWrite(g, HIGH);
  digitalWrite(b, HIGH);

  delay(500);
}
