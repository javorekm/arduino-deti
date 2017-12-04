import sys
import serial
from pykeyboard import PyKeyboard

keyboard = PyKeyboard()

KEYS = {
    b"KEY_UP\n": keyboard.up_key,
    b"KEY_DOWN\n": keyboard.down_key,
    b"KEY_RIGHT\n": keyboard.right_key,
    b"KEY_LEFT\n": keyboard.left_key,
    b"KEY_SPACE\n": keyboard.space_key,
    #b"KEY_ENTER\n": keyboard.enter_key,
    b"KEY_ENTER\n": 'a',
}

print("Arduino UNO R3 Keyboard simulator")

if len(sys.argv) < 2:
    print("Schazi port, na kterem mam poslouchat Arduino")
    print("priklad Windows: python arduino_keyboard.py COM1")
    print("priklad Linux: python arduino_keyboard.py /dev/ttyusb0")
    sys.exit(1)

port = sys.argv[1]
print("Nasloucham na portu: {}".format(port))
print("Pro ukonceni stiskni Ctrl+C\n")

ser = serial.Serial(port, 9600)
while(1):
    line = ser.readline()
    print("Arduino poslalo: {}".format(line))
    for k, v in KEYS.items():
        if line == k:
            keyboard.tap_key(v)
            print('Mackam klavesu: {}'.format(k))
            break
