
import serial
import matplotlib.pyplot as plt
import sys

sys.path.append('/hw/hw10/non_c_files')
from genref import genRef

ser = serial.Serial('COM3',230400,rtscts=1)
print('Opening port: ', end = '')
print(ser.name)
print()

has_quit = False
# menu loop
while not has_quit:

	print('PIC32 MOTOR DRIVER INTERFACE')
	# display the menu options; this list will grow
	print('\tb: read current (mA) \tc: read encoder (counts) \td: read encoder (deg)')
	print('\te: reset encoder \tf: set PWM, -100 to 100 \tg: set current gains')
	print('\th: get current gains \ti: set position gains \t\tj: get position gains')
	print('\tk: test current gains \tl: go to position \t\tm: load step traj.')
	print('\tn: load cubic traj. \to: execute traj. \t\tp: power off PWM')
	print('\t' + '_' * 90)
	print('\tq: quit \t\tr: read PIC32 mode \t\tx: example command \n')

	# read the user's choice
	selection = input('ENTER COMMAND: ')
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

		#enter new values of position gains
		gain = input('Enter new gain Kp for current: ')
		gain = float(gain)
		serial_text = (str(gain) + '\n').encode()
		ser.write(serial_text)

		gain = input('Enter new gain Ki for current: ')
		gain = float(gain)
		serial_text = (str(gain) + '\n').encode()
		ser.write(serial_text)

		gain = input('Enter new gain Kd for current: ')
		gain = float(gain)
		serial_text = (str(gain) + '\n').encode()
		ser.write(serial_text)
		print()

	elif (selection == 'h'):

		#read values of current gains from UART
		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of current gain Kp: {gain}')

		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of current gain Ki: {gain}')

		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of current gain Kd: {gain} \n')

	elif (selection == 'i'):

		#set new values of position gains
		gain = input('Enter a new value for position gain Kp: ')
		gain = float(gain)
		serial_text = (str(gain) + '\n').encode()
		ser.write(serial_text)

		gain = input('Enter a new value for position gain Ki: ')
		gain = float(gain)
		serial_text = (str(gain) + '\n').encode()
		ser.write(serial_text)

		gain = input('Enter a new value for position gain Kd: ')
		gain = float(gain)
		serial_text = (str(gain) + '\n').encode()
		ser.write(serial_text)
		print()

	elif (selection == 'j'):

		#read values of position gains from UART
		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of position gain Kp: {gain}')

		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of position gain Ki: {gain}')

		bytes = ser.read_until(b'\n')
		gain = float(bytes)
		print(f'Value of position gain Kd: {gain} \n')	


	elif (selection == 'k'):

		curr_array = []
		ref_array = []

		print('Running ITEST mode now. Check plot of datapoints.')
		bytes = ser.read_until(b'\n')
		num_samps = int(bytes)
		print(f'Number of ITEST samples: {num_samps} \n')

		for i in range(num_samps):
			#read until binary space char
			bytes = ser.read_until(b' ')
			current = float(bytes)
			curr_array.append(current)

			#read until binary newline char
			bytes = ser.read_until(b'\n')
			refval = float(bytes)
			ref_array.append(refval)

		xvals = list(range(0,num_samps))
		plt.plot(xvals, ref_array, curr_array)
		plt.show()

	elif (selection == 'l'):
		
		#gp to a position
		#posn = input('Enter a position to move to: ')
		#posn = float(posn)
		#serial_text = (str(posn) + '\n').encode()
		#ser.write(serial_text)
		pass

	elif (selection == 'm'):
		#load step trajectory
		print('Sending step trajectory to PIC.\n')
		ref = genRef('step')

		#send length of the array to the PIC so we know how much data there is
		print("Sending data to the PIC...")
		length = len(ref)
		print('Length of ref: ' + str(length))
		print('Printing ref array: ')
		print(ref)

		serial_text = (str(length) + '\n').encode()
		ser.write(serial_text)


		#take every element in the ref array and send it to the PIC
		for i in range(len(ref)):
			val = str(ref[i])
			serial_text = (val + '\n').encode()
			ser.write(serial_text)

		print("Data sent to the PIC!\n")

	elif (selection == 'n'):
		#load cubic trajectory
		print('Sending cubic trajectory to PIC.\n')
		ref = genRef('cubic')

		#send length of the array to the PIC so we know how much data there is
		print("Sending data to the PIC...")
		
		
		length = len(ref)
		print('Length of ref: ' + str(length))
		print('Printing ref trajectory: ')
		print(ref)

		serial_text = (str(length) + '\n').encode()
		ser.write(serial_text)

		#take every element in the ref array and send it to the PIC
		for i in range(len(ref)):
			val = str(ref[i])
			serial_text = (val + '\n').encode()
			ser.write(serial_text)

		print("Data sent to the PIC!\n")


	elif (selection == 'o'):
		#execute trajectory
		print('Executing trajectory...')

		posn_list = []
		traj_list = []

		#wait for PIC to do all the computations
		#and retrieve the values
		bytes = ser.read_until(b'\n')
		traj_length = int(bytes)
		print(f'Length of trajectory: {traj_length}')

		for i in range(traj_length):
			bytes = ser.read_until(b' ')
			traj = float(bytes)
			traj_list.append(traj)

			bytes = ser.read_until(b'\n')
			posn = float(bytes)
			posn_list.append(posn)

		x_ref = list(range(traj_length))

		print(f'Trajectory list received: {traj_list}')

		plt.plot(x_ref, posn_list, traj_list)
		plt.show()


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



