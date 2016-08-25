import serial
import serial.tools.list_ports as list_ports
import sys

ports = list(list_ports.comports())

for p in ports:
    if "Arduino" in p[1]:
        arduino_com = p[0]
print(arduino_com)

ser = serial.Serial(port=arduino_com, baudrate=9600, parity=serial.PARITY_NONE,
                    stopbits=serial.STOPBITS_ONE, bytesize=serial.EIGHTBITS)
print("connected to: " + ser.portstr)


#while True:
try:
    thickness = input("Enter plate thickness: ")
    if ((float(thickness).is_integer()) & (float(thickness) <= 3)):
        print('hi')
        # line = ser.readline()
        # split_line = line.split()

        # actuator1state = split_line[1]
        # actuator1error = split_line[3]

        # actuator2state = split_line[5]
        # actuator2error = split_line[7]
    else:
        print('nothing')
finally:
    print('program end')