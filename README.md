# Arduino-Projects
Several small arduino projects

Several small projects that utilize the "keyestudio 48 in 1 Sensor Kit" on the Arduino Uno model. Everything is compiled with Arduino-CLI and the programs are flashed onto the board through a USB-TTL converter with UART pins. The RTS pin of the converter is connected to a small capacitor which leads to the arduino board's reset pin. This allows the programmer to flash the board with the same ease of use as if they were using the standard USB cable.

CLI example of compiling and flashing a program from a project.

```
arduino-cli compile -v -b arduino:avr:uno $(pwd)/fade_LED -p /dev/ttyUSB0 -u
```