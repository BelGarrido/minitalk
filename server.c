// must be started first
// after its launch it has to print its PID
// must print the string after receiving the the string from client
// must display the string pretty quickly
// server must be able to receive several string from differents clients in a row without needing to restart
// communication must be done only using UNIX signals
// you only can use SIGUSR1 and SIGUSR2

#include "minitalk.h"

/* void	bin_to_char(int signum, char* c)
{

} */

// Trial function
// kill(pid, SIGUSR2); signum es el valor de SIGUSR1 / 2;
void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("1\n");

	else if (signum == SIGUSR2)
		printf("0\n");
		//sleep(100);
}

int		main(void)
{
	struct sigaction sa;

	// Initialize the struct with 0s (optional but recommended for safety)
	sa.sa_handler = signal_handler;
	sigemptyset(&sa.sa_mask); // Not blocking any other signals
	sa.sa_flags = 0;          // No additional flags
 

	// When receiving sigusr1 || sigusr2 signal_handler is called
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	//sigaction(SIGTERM, &sa, NULL);

	// Handle the error in signals


	//ft_printf("The process ID is %d\n", pid);
	printf("Yey server it's working! It's process ID is %d\n", getpid());

	//bucle de escucha
	while (1)
	{
		pause();
	}

	return 0;
}