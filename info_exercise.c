
write
ft_printf y cualquier equivalente que TÚ hayas programado

signal()---------------------------------------------------
	The signal function in C is a way to specify a function, called a signal handler, to be called when a specific signal is received by a running program.
	sighandler_t signal(int signum, sighandler_t handler);

sigemptyset()----------------------------------------------
	The sigemptyset function is used to initialize a signal set to the empty set,	
	int sigemptyset(sigset_t *set);
	
sigaddset()------------------------------------------------
	This function allows to add a signal to a set of signals.	
	int sigaddset(sigset_t *set, int signum);
	
	int main(void)
	{
		sigset_t signal_set;

		// Initialize an empty signal set
		sigemptyset(&signal_set);

		// Add SIGINT to the signal set
		sigaddset(&signal_set, SIGINT);
	}
sigaction
kill
getpid
malloc
free
pause
sleep
usleep
exit

------------------------------------------------------------------------------------------------------------------------------------------

The server must be started first. After its launch, it has to print its PID.
The client takes two parameters: 
	1) The server PID
	2)The string to send.
The client must send the string passed as a parameter to the server. Once the string has been received, the server must print it.
The server has to display the string pretty quickly. Quickly means that if you think it takes too long, then it is probably too long.
Your server should be able to receive strings from several clients in a row without needing to restart.
The communication between your client and your server has to be done only using UNIX signals.
You can only use these two signals: SIGUSR1 and SIGUSR2.


One process, called the "speaker/client" sends the message by transmitting a series of signals over the wire. 

The other process, called the "listener/server" receives the message by interpreting the series of signals as a message.


-----------------------------------------------------------------------------------------------------------------------------------------

******Client Checklist*******

In the "client.c" file, you will...

	Write a program (main) in which the client takes two parameters/arguments

	(done) The PID of the server to which it wants to send the message

	(done) A message

	Encrypt the message (I did the encryption via bits)

	Send the message to the server (via its PID)

	Create a stop condition so that the server knows when it has finished receiving the message

*******Server Checklist*******

In the "server.c" file, you will...

	(done) Display its PID

	(done) Create an endless loop so that the server can receive signals at any time

	(done) Receive signals

	Decrypt signals

	For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action

*******Basic Checklist*******

Makefile (create the "server" and "client" executables)

Manage errors & remove all leaks

Deal with the holy norminette

----------------------------------------------------------------------------------------------------------------

// CLIENT.C file

/** global static int variable. it will help us note 
*   when we stopped receiving signals
*/

void sig_handler(int signum, siginfo_t* info, void* context)
{
  /** 
     *  create a variable static int i to count the numbers of bit read
     *  void the args you are not using
     *
     *  change the global varaible to 1
     *  if signum == SIGUSR2 
     *     increment i
     *  else if signum == SIGUSR1 
      *    print the number of bytes recieved (NB: 8 bits = 1 byte)
     */
}

int char_to_bin(char c, int pid)
{
  /** 
     *  VARIABLES
     *  
     *  create a variable int itr
     *  int bit_index to loop over each byte
     *
     *  initialise bit_index to 7 ie 0 -> 7 which will make 8 bits
     *  create a while loop to loop bit by bit by decrementing from 7 to 0
     * while(bit_idx >= 0)
     *{
          // initialize itr back to zero
          // conversion
          if ((c >> bit_index) & 1)
              kill(pid, SIGUSR1);
          else
              kill(pid, SIGUSR2);
          while (g_receiver == 0)
          {
             if (itr == 50) // wait for response after count of 50 (any number)
             {
                //print no response from server here and exit
             }
             // increment itr by 1
             usleep(100); // gives enough time for each signal to be processed
          }
          // re-initialize g_receiver back to zero and decrement bit_index by 1
         }
         return (0);
     */
}

int main(int argc, char* argv[])
{
  /** 
   *  VARIABLES
   *  create a struct for our sigaction
   *  create a variable for each byte
   *  then variable for the process identifier
   *
   *  SIGACTION
   *  Check if the right number of argument is being passed
   *  convert the servers pid argument from string to number
          and save it to the process identifier variable
   *  empty the signal numbers to prevent error 
   *  -> u can use the sigemptyset. some people also use the memset func
   *  set the appropraite flags for sigaction
   *  also set the sig_handler func
   *  call the sigaction function twice: with SIGUSR1 and SIGUSR2 respectively
   *  you can handle the error for the function call,
   *  where -1 means an error occurred
   *  Handle each character of the string by looping over
   *  and converting to binary using a function with a prototype of
   *  int char_to_bin(char c, int pid) // note: c -> argv[2][byte_index++]
   *  then outside the loop call the conversion function again but
   *  this time pass '\0' as char. This is important in preparing 
   *  the server for new feed of strings 
   */
}


// ALT PSUEDOCODE (same as above)

STATIC int g_receiver = 0

FUNCTION sig_handler(int signum, siginfo_t *info, void *context)
    STATIC int i = 0

    SET g_receiver = 1
    IF signum IS SIGUSR2 THEN
        INCREMENT i
    ELSE IF signum IS SIGUSR1 THEN
        PRINT "Number of bytes received: " AND (i / 8)
    END IF
END FUNCTION

FUNCTION ft_char_to_bin(char c, int pid)
    FOR bit_index FROM 7 TO 0 DO
        IF ((c >> bit_index) AND 1) IS TRUE THEN
            SEND SIGUSR1 TO pid
        ELSE
            SEND SIGUSR2 TO pid
        END IF

        DECLARE itr = 0
        WHILE g_receiver IS 0 DO
            IF itr EQUALS 50 THEN
                PRINT "No response from server."
                EXIT WITH ERROR
            END IF
            INCREMENT itr
            WAIT FOR 100 microseconds
        END WHILE
        SET g_receiver TO 0
    END FOR
END FUNCTION

FUNCTION main(int argc, char *argv[])
    DECLARE sigaction sa
    DECLARE int byte_index = 0
    DECLARE int pid

    IF argc NOT EQUALS 3 THEN
        PRINT "You need to pass 2 args but u passed " AND (argc - 1)
        RETURN 1
    END IF

    SET pid TO atoi(argv[1])
    SET signal handlers FOR SIGUSR1 AND SIGUSR2

    WHILE argv[2][byte_index] IS NOT NULL DO
        CALL ft_char_to_bin(argv[2][byte_index], pid)
        INCREMENT byte_index
    END WHILE

    CALL ft_char_to_bin('\0', pid)  // Send termination character

    RETURN 0
END FUNCTION

END




--------------------------------------------------------------------------------------------------

// SERVER.C

void bin_to_char(int signum, char* c)
{
/**
 * if (signum == SIGUSR1) *c = (*c << 1) | 1;
 * else if (signum == SIGUSR2) *c <<= 1;
*/
}

void sig_handler(int signum, siginfo_t* info, void* context)
{
  /**
  * create static int variable for pid and i and static char for c
  * void unused arg
  * set the details of the pid you are receiving from to the pid by using
  * info->pid
  * send the signal number and address of c to the bin_to_char function
  * if (++i == 8) // for every 8 bit read c
     {
      initialize i to 0
      if (!c) // this if block prepares the server for new feed of strings
      {
         kill(pid, SIGUSR1);
         // initialize pid to zero, so that you can handle multiple terminals
         // return
      }
      // since we have read 8 bits we can now read c and then initalise it back
      // back to null
     }
     kill(pid, SIGUSR2);
  */
}

int main(void)
{
/** 
   *  VARIABLES
   *  create a struct for our sigaction
   * 
   *  print the server pid using getpid()
   *  SIGACTION
   *  -> u can use the sigemptyset. some people also use the memset func
   *  set the appropraite flags for sigaction
   *  also set the sig_handler func
   *  call the sigaction function twice: with SIGUSR1 and SIGUSR2 respectively
   *  you can handle the error for the function call,
   *  create a while loop to wait for signals while(1) pause();
   */
 return (0);
}


// ALT PSUEDOCODE (Same as above)
FUNCTION ft_bin_to_char(signum, *char c)
    IF signum IS SIGUSR1 THEN
        SET *c = (*c << 1) OR 1
    ELSE IF signum IS SIGUSR2 THEN
        SET *c = *c << 1
    END IF
END FUNCTION

FUNCTION sig_handler(int signum, siginfo_t *info, void *context)
    STATIC int pid = 0
    STATIC char c = 0
    STATIC int i = 0

    IF pid IS 0 THEN
        SET pid = info->si_pid
    END IF

    CALL ft_bin_to_char(signum, &c)

    INCREMENT i

    IF i EQUALS 8 THEN
        RESET i

        IF c EQUALS NULL CHARACTER THEN
            SEND SIGUSR1 TO pid  // Acknowledge end of message
            RESET pid
            RETURN
        END IF

        PRINT c TO STDOUT
        RESET c
    END IF

    SEND SIGUSR2 TO pid  // Acknowledge bit received
END FUNCTION

FUNCTION main()
    DECLARE sigaction sa

    PRINT "Server PID: " AND getpid()
    SET sa.sa_flags TO SA_RESTART | SA_SIGINFO
    SET sa.sa_sigaction TO sig_handler

    SET signal handlers FOR SIGUSR1 AND SIGUSR2

    LOOP FOREVER
        CALL pause()
    END LOOP
END FUNCTION

END