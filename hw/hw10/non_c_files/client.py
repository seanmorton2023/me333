
import serial
import matplotlib.pyplot as plt
import sys
from statistics import mean 

sys.path.append('/hw/hw10/non_c_files')
from genref import genRef

ser = serial.Serial('COM3',230400,rtscts=1)
print('Opening port: ', end = '')
print(ser.name)
print()

def read_arrays():

	ref_array = []
	curr_array = []

	bytes = ser.read_until(b'\n')
	num_samps = int(bytes)
	print(f'Number of datapoints: {num_samps} \n')

	for i in range(num_samps):
		#read until binary space char
		bytes = ser.read_until(b' ')
		val1 = float(bytes)
		ref_array.append(val1)

		#read until binary newline char
		bytes = ser.read_until(b'\n')
		val2 = float(bytes)
		curr_array.append(val2)

	return ref_array, curr_array

###

def plot_arrays(ref_array, curr_array):

		#plot arrays and mean deviation, like Nick's example
		x_ref = list(range(len(ref_array)))

		meanzip = zip(ref_array,curr_array)
		meanlist = []
		for i,j in meanzip:
		    meanlist.append(abs(i-j))
		score = mean(meanlist)
		score = round(score,4)

		plt.plot(x_ref, curr_array, ref_array)
		plt.title('Score = ' + str(score))
		plt.ylabel('value')
		plt.xlabel('index')
		plt.show()

###

def send_trajectory(shape):

	print(f'Sending {shape} trajectory to PIC.\n')
	ref = genRef(shape)

	#send length of the array to the PIC so we know how much data there is
	print("Sending data to the PIC...")
		
	length = len(ref)
	print('Length of ref: ' + str(length))
	serial_text = (str(length) + '\n').encode()
	ser.write(serial_text)

	#take every element in the ref array and send it to the PIC
	for i in range(len(ref)):
		val = str(ref[i])
		serial_text = (val + '\n').encode()
		ser.write(serial_text)

	print("Data sent to the PIC!\n")

###

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
	print('\tq: quit \t\tr: read PIC32 mode \t\ty: view traj. arrays\n')

	ser.flush()

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

		print('Running ITEST mode now. Check plot of datapoints.')
		ref_array, curr_array = read_arrays()
		plot_arrays(ref_array, curr_array)

	elif (selection == 'l'):
		
		#go to a position
		posn = input('Enter a position to move to: ')
		posn = float(posn)
		serial_text = (str(posn) + '\n').encode()
		ser.write(serial_text)

		#PIC handles the rest from here
		pass

	elif (selection == 'm'):
		send_trajectory('step')

	elif (selection == 'n'):
		send_trajectory('cubic')

	elif (selection == 'o'):

		print('Executing trajectory...')
		traj_list, posn_list = read_arrays()
		plot_arrays(traj_list, posn_list)

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

	elif (selection == 'y'):
		
		print('Arrays stored on the PIC:')
		#show what arrays the PIC has stored
		traj_list, posn_list = read_arrays()
		for i in range(len(traj_list)):
			if (i == 0 or (i+1)%100 == 0):
				traj = traj_list[i]
				posn = posn_list[i]
				print(f'Index {i}: ref {traj} actual {posn}')
		print()

	elif (selection == 'q'):
		print('Exiting client')
		has_quit = True; # exit client
		# be sure to close the port
		ser.close()

	else:
		print('Invalid Selection ' + selection_endline)



