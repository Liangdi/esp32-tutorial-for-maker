# 运行 Hello World 程序

## 使用 Arduino 的框架编写代码

Arduino 的 Hello World 程序，约定俗成的使用了让 LED 灯闪烁的程序，程序很简单，不需要什么修改就直接跑在了 ESP32 上。

```
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
```
DFRobot FireBeetle 开发板的内置 LED 在 D9 引脚上，所以这里驱动 D9 ，引脚进行电平交替更换即可实现 LED 灯闪烁的效果，同时向连接的串口输出 "Hello ESP32" 的字符串。

## 注意事项

基于 Arduino 的平台框架，在 ESP32 上写程序已经很简单了，我们可以大胆移植大部分和层序过来，但是随着你对 ESP32 的深入使用，一些不兼任问题就会遇到，我相信最快遇到的就是我们常用的 PWM 输出，大多数情况下，我们使用 analogWrite 函数进行 PWM 输出，可是这个函数在 ESP32 上会提示没有这个函数，确实 ESP32 库里面没有实现这个函数，取而代之的是用 ledc 这个模块的功能 ,具体可以查看 https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/esp32-hal-ledc.c .

Arduino 是个很开放的平台，如果你想要继续使用 analogWrite ，没问题，有人已经s使用 ledc 写了对应的 analogWrite 的库 https://github.com/ERROPiX/ESP32_AnalogWrite ，安装后，添加对应的依赖后，就可以向往常一样使用 analogWrite 函数了，示例代码(呼吸灯效果):

```
#include <Arduino.h>
#include <analogWrite.h>

int brightStep = 1;
int brightness = 0;

void setup() {
}

void loop() {
  brightness += brightStep;
  analogWrite(LED_BUILTIN, brightness);

  if ( brightness == 0 || brightness == 255 ) {
    brightStep = -brightStep;
  }
  
  delay(10);
}
```

## 后记
Hello World 很简单，