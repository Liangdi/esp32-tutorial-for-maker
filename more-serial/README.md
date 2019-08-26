# ESP32 Serial, Serial1, Serial2 使用注意事项
根据 ESP32 的手册，芯片有三组 UART 接口，在 Arduino 环境中，分别对应 Serial, Serial1, Serial2 三个对象，但是使用的时候有些需要注意的地方。

## Serial 使用会遇到的问题
大多数开发板的 Serial 都会与 USB 接口联通, 除了提供给开发者使用以外, 还担负着下载程序的功能. 如果开发者的程序只是使用 USB 和上位机通讯，那么一般会很少遇到问题，但是如果程序使用 Serial 和另外的模块通讯，那么在更新程序的时候，需要将和另外的模块的连接断开，不然上传数据和反馈信息会和我们的程序冲突造成无法上传的错误。

## Serial1 和 Serial2 的使用
在代码（https://github.com/espressif/arduino-esp32/blob/master/cores/esp32/HardwareSerial.cpp） 中可以看到 arduino-esp32 中定义了 Serial，Serial1，Serial2 三个对象，并且指定了对应的引脚， Serial 的 TX 是 GPIO1， RX 是 GPIO 3， Serial1 的 TX 是 GPIO10，RX 是 GPIO9 ， Serial2 的 TX 是 GPIO17， RX 是 GPIO 16。 
在 ESP32 芯片默认配置情况下 6-12 GPIO 配置 FLASH 的接口，不能被其他程序使用，所以默认 Serial1 是无法正常使用， Serial1 和 Serial2 可以正常使用，Serial2 直接使用即可
```
    Serial2.begin(115200)
```
如何配置 GPIO ， 后续会单独开一篇文章做说明，或者参考 ESP32 手册。