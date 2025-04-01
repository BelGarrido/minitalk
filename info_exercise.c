
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

	The PID of the server to which it wants to send the message

	A message

	Encrypt the message (I did the encryption via bits)

	Send the message to the server (via its PID)

	Create a stop condition so that the server knows when it has finished receiving the message

*******Server Checklist*******

In the "server.c" file, you will...

	Display its PID

	Create an endless loop so that the server can receive signals at any time

	Receive signals

	Decrypt signals

	For each signal received (SIGUSR1 & SIGUSR2) it should take a certain action

*******Basic Checklist*******

Makefile (create the "server" and "client" executables)

Manage errors & remove all leaks

Deal with the holy norminette