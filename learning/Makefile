# Command to compile
#   make
# Command to compile and upload
#   make upload
# Besides make upload you can also
#   make             - no upload
#   make clean       - remove all our dependencies
#   make depends     - update dependencies
#   make reset       - reset the Arduino by tickling DTR on the serial port
#   make raw_upload  - upload without first resetting
#   make show_boards - list all the boards defined in boards.txt
#   make monitor     - connect to the Arduino's serial port
#   make size        - show the size of the compiled output (relative to
#                      resources, if you have a patched avr-size)
#   make disasm      - generate a .lss file in build-cli that contains
#                      disassembly of the compiled file interspersed
#                      with your original source code.
#   make verify_size - Verify that the size of the final file is less than
#   				   the capacity of the micro controller.
#   make eeprom      - upload the eep file
#	make raw_eeprom  - upload the eep file without first resetting

ARDUINO_DIR=/usr/share/arduino
ARDMK_DIR=/usr/share/arduino
ARDMK_PATH=/usr/bin
AVR_TOOLS_DIR=/usr

BOARD_TAG = uno
MONITOR_PORT = /dev/ttyACM0
ARDUINO_LIBS = 

include /usr/share/arduino/Arduino.mk
