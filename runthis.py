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
thickness = 10*(input("Enter plate thickness: "))
if (int(thickness) <= 30):
    try:
        thick_binary = '{0:08b}'.format(thickness)
        print(thickness)
        print(thick_binary)
        # line = ser.readline()
        # split_line = line.split()

        # actuator1state = split_line[1]
        # actuator1error = split_line[3]

        # actuator2state = split_line[5]
        # actuator2error = split_line[7]
    finally:
        print("program end")
