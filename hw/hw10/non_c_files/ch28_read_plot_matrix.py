# chapter 28 in python

# sudo apt-get install python3-pip
# python3 -m pip install pyserial
# sudo apt-get install python3-matplotlib


import matplotlib.pyplot as plt 
from statistics import mean 
def read_plot_matrix():
    n_str = ser.read_until(b'\n');  # get the number of data points to receive
    n_int = int(n_str) # turn it into an int
    print('Data length = ' + str(n_int))
    ref = []
    data = []
    data_received = 0
    while data_received < n_int:
        dat_str = ser.read_until(b'\n');  # get the data as a string, ints seperated by spaces
        dat_f = list(map(float,dat_str.split())) # now the data is a list
        ref.append(dat_f[0])
        data.append(dat_f[1])
        data_received = data_received + 1
    meanzip = zip(ref,data)
    meanlist = []
    for i,j in meanzip:
        meanlist.append(abs(i-j))
    score = mean(meanlist)
    t = range(len(ref)) # index array
    plt.plot(t,ref,'r*-',t,data,'b*-')
    plt.title('Score = ' + str(score))
    plt.ylabel('value')
    plt.xlabel('index')
    plt.show()

if __name__ == '__main__':
    from genref import genRef

    import serial
    ser = serial.Serial('COM95',230400,rtscts=1)
    print('Opening port: ')
    print(ser.name)

    has_quit = False
    # menu loop
    while not has_quit:
        print('PIC32 MOTOR DRIVER INTERFACE')
        # display the menu options; this list will grow
        print('\tc: get encoder counts \te: reset encoder \td: read encoder angle \tq: Quit') # '\t' is a tab
        # read the user's choice
        selection = input('\nENTER COMMAND: ')
        selection_endline = selection+'\n'
     
        # send the command to the PIC32
        ser.write(selection_endline.encode()); # .encode() turns the string into a char array
    
        # take the appropriate action
        # there is no switch() in python, using if elif instead
        if (selection == 'c'):
            print('Requesting encoder counts: ')
            n_str = ser.read_until(b'\n'); 
            n_int = int(n_str)
            print('Encoder counts = '+str(n_int)+'\n')
        elif (selection == 'r'):
            print('Requesting mode: ')
            n_str = ser.read_until(b'\n'); 
            n_int = int(n_str)
            print('Mode = '+str(n_int)+'\n')
        elif (selection == 'm'):
            ref = genRef('cubic')
            #print(len(ref))
            t = range(len(ref))
            plt.plot(t,ref,'r*-')
            plt.ylabel('ange in degrees')
            plt.xlabel('index')
            plt.show()
            # send 
            ser.write((str(len(ref))+'\n').encode())
            for i in ref:
                ser.write((str(i)+'\n').encode())
        elif (selection == 'o'):
            read_plot_matrix()
        elif (selection == 'q'):
            print('Exiting client')
            has_quit = True; # exit client
            # be sure to close the port
            ser.close()
        else:
            print('Invalid Selection ' + selection_endline)
