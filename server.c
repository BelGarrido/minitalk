// must be started first
// after its launch it has to print its PID
// must print the string after receiving the the string from client
// must display the string pretty quickly
// server must be able to receive several string from differents clients in a row without needing to restart
// communication must be done only using UNIX signals
// you only can use SIGUSR1 and SIGUSR2

#include "minitalk.h"
#include "ft_printf.h"

// Trial function
// kill(pid, SIGUSR2); signum es el valor de SIGUSR1 / 2;
void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t client_pid = 0;
	static unsigned char c = 0;
	static int char_index = 0;
	context = context;
	//si en algun momento averiguo como se manda una señak de acknolegdment
	if (client_pid == 0)
        client_pid = info->si_pid;

	if (signum == SIGUSR1)
	{
		c = c << 1 | 1;
		//printf("1\n");
	}
	else if (signum == SIGUSR2)
	{
		c = c << 1;
		//printf("0\n");
		//sleep(100);
	}
	char_index++;

	kill(info->si_pid, SIGUSR1);

	if (char_index == 8)
	{
		write (1, &c, 1);
		c = 0;
		char_index = 0;
	}
}

int		main(void)
{
	struct sigaction sa;

	// Initialize the struct with 0s (optional but recommended for safety)
	sa.sa_sigaction = signal_handler;

	sigemptyset(&sa.sa_mask); // Not blocking any other signals
	sa.sa_flags = SA_SIGINFO; //Use siginfo_t to get sender's PID
	// When receiving sigusr1 || sigusr2 signal_handler is called
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	//sigaction(SIGTERM, &sa, NULL);

	//ft_printf("The process ID is %d\n", pid);
	printf("Yey server it's working! It's process ID is %d\n", getpid());
	//bucle de escucha
	while (1)
		pause();
	return 0;
}