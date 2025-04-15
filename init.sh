#!/bin/bash

#DIR=~/arduino_projects/rgb_led/
curl -fsSL https://raw.githubusercontent.com/arduino/arduino-cli/master/install.sh | sh
arduino-cli core install arduino:avr
#arduino-cli compile -v -b arduino:avr:uno ${DIR} -p /dev/ttyUSB0 -u