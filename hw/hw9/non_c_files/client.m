function client(port)
%   provides a menu for accessing PIC32 motor control functions
%
%   client(port)
%
%   Input Arguments:
%       port - the name of the com port.  This should be the same as what
%               you use in screen or putty in quotes ' '
%
%   Example:
%       client('/dev/ttyUSB0') (Linux/Mac)
%       client('COM3') (PC)
%
%   For convenience, you may want to change this so that the port is hardcoded.
   
% Opening COM connection
if ~isempty(instrfind)
    fclose(instrfind);
    delete(instrfind);
end

fprintf('Opening port %s....\n',port);

% settings for opening the serial port. baud rate 230400, hardware flow control
% wait up to 120 seconds for data before timing out
mySerial = serial(port, 'BaudRate', 230400, 'FlowControl', 'hardware','Timeout',120); 
%mySerial = serial(port, 'BaudRate', 230400, 'FlowControl', 'hardware','Timeout',120); 

% opens serial connection
fopen(mySerial);
% closes serial port when function exits
clean = onCleanup(@()fclose(mySerial));                                 

has_quit = false;
% menu loop
while ~has_quit
    fprintf('PIC32 MOTOR DRIVER INTERFACE\n\n');
    % display the menu options; this list will grow
    fprintf('\tb: read current (mA) \tc: read encoder (counts) \td: read encoder (deg) \n')
    fprintf('\te: reset encoder \t\tf: set PWM, -100 to 100 \tg: set current gains \n')
    fprintf('\th: get current gains \tp: power off \tr: read PIC32 mode \n')
    fprintf('\tx: Dummy Command \tq: Quit\n');
    % read the user's choice
    selection = input('\nENTER COMMAND: ', 's');
     
    % send the command to the PIC32
    fprintf(mySerial,'%c\n',selection);
    
    % take the appropriate action
    switch selection

        case 'b'
            %read current (mA)
            fprintf(mySerial,'b\n');
            n = fscanf(mySerial, "%f");
            fprintf('Read: %f \n',n);

        case 'c'
            %read encoder (counts)

        case 'd'
            %read encoder(degrees)

        

        case 'x'                         % example operation
            n = input('Enter number: '); % get the number to send
            fprintf(mySerial, '%d\n',n); % send the number
            n = fscanf(mySerial,'%d');   % get the incremented number back
            fprintf('Read: %d \n',n);     % print it to the screen
            
        case 'q'
            has_quit = true;             % exit client

        otherwise
            fprintf('Invalid Selection %c\n', selection);
    end
end

end
