# chapter 28 in python

# sudo apt-get install python3-pip
# python3 -m pip install pyserial
# sudo apt-get install python3-matplotlib

import serial
ser = serial.Serial('COM3',230400,rtscts=1)
print('Opening port: ')
print(ser.name)

has_quit = False
# menu loop
while not has_quit:
	print('PIC32 MOTOR DRIVER INTERFACE')
	# display the menu options; this list will grow
	print('\tb: read current (mA) \tc: read encoder (counts) \td: read encoder (deg)')
	print('\te: reset encoder \tf: set PWM, -100 to 100 \tg: set current gains')
	print('\th: get current gains \tp: power off PWM \t\tr: read PIC32 mode')
	print('\tx: Dummy Command \tq: Quit');

	# read the user's choice
	selection = input('\nENTER COMMAND: ')
	selection_endline = selection+'\n'
	 
	# send the command to the PIC32
	ser.write(selection_endline.encode()); # .encode() turns the string into a char array
	
	# take the appropriate action
	# there is no switch() in python, using if elif instead

	if (selection == 'b'):

		bytes = ser.read_until(b'\n')
		current = float(bytes)
		print(f'Current reading: {current} \n')

	elif (selection == 'c'):

		bytes = ser.read_until(b'\n')
		count = int(bytes)
		print(f'Encoder reading: {count} \n')

	elif (selection == 'd'):

		bytes = ser.read_until(b'\n')
		degs = float(bytes)
		print(f'Encoder reading (degrees) {degs} \n')	

	elif (selection == 'e'):
		#no data to read here; just sends data to the PICO
		print('Sent command to reset the encoder count.\n')

	elif (selection == 'f'):
		
		pwm = input('Enter a new value for PWM (-100 to 100): ')
		serial_text = (str(pwm) + '\n').encode()
		ser.write(serial_text)
		print(f'New value of PWM: {pwm} \n')


	elif (selection == 'g'):

		#make this use just one variable for faster execution time

		gain1 = input('Enter new gain Kp for current: ')
		gain1 = float(gain1)
		serial_text = (str(gain1) + '\n').encode()
		ser.write(serial_text)

		gain2 = input('Enter new gain Ki for current: ')
		gain2 = float(gain2)
		serial_text = (str(gain2) + '\n').encode()
		ser.write(serial_text)
		print()

	elif (selection == 'h'):

		#gets into an infinite loop during the reading portion

		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of current gain Kp: {gain}')

		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of current gain Ki: {gain} \n')

	elif (selection == 'k'):
		pass

	elif (selection == 'p'):
		print("PIC mode set to IDLE.\n")

	elif (selection == 'r'):

		bytes = ser.read_until(b'\n')
		mode = int(bytes)
		print(f'Current mode of PIC32: {mode} \n')

		print(
		"Guide to program modes: \n" +
		"IDLE Mode: 0 \n"  +
		"PWM Mode: 1 \n" +
		"ITEST Mode: 2 \n" + 
		"HOLD Mode: 3 \n" + 
		"TRACK Mode: 4 \n\n",
		)

	elif (selection == 'x'):
		# example operation
		n_str = input('Enter number: ') # get the number to send
		n_int = int(n_str) # turn it into an int
		print('number = ' + str(n_int)) # print it to the screen to double check

		ser.write((str(n_int)+'\n').encode()); # send the number
		n_str = ser.read_until(b'\n');  # get the incremented number back
		n_int = int(n_str) # turn it into an int
		print('Got back: ' + str(n_int) + '\n') # print it to the screen



	elif (selection == 'q'):
		print('Exiting client')
		has_quit = True; # exit client
		# be sure to close the port
		ser.close()

	else:
		print('Invalid Selection ' + selection_endline)



