void setup() {
  Serial.begin(115200);

  pinMode(LED_BUILTIN,OUTPUT);

  delay(500);
  Serial.println("Hello ESP32");
}

void loop() {

  delay(500);
  digitalWrite(LED_BUILTIN,HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN,LOW);
}
