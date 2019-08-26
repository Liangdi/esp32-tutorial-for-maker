#include "BluetoothSerial.h"

BluetoothSerial bt;
void setup() {
  Serial.begin(115200);
  bt.begin("Hello-ESP32");
  Serial.println("Bluetooth Ready!");
  Serial.println(LED_BUILTIN);
  Serial2.begin(9600);
}

void loop() {

  if (Serial.available()) {
    bt.write(Serial.read());
  }
  if (bt.available()) {
    Serial.write(bt.read());
  }
  delay(20);
}
