// client takes 2 arguments (server PID, the string to communicate)
// must sent the string passed as argument to the server


/*char_to_bin
 1 iterar sobre elstring
 2 char_to_bin devuelve binario almacenarlo en un int o en un cha
 3 bucle iterando sobre el int para seleccionar cada valor y mandar una señal u otra.
 */


#include "minitalk.h"

void signal_handler(int signum)
{
	printf("Server confirmation recived\n");
}

int main(int argc, char *argv[])
{
	char *s;
	int pid;
	char *binary;
	char *binary_free;
	int i;
	struct sigaction csa;

	if (argc != 3)
	{
		printf("Error: You have to pass 2 arguments (process ID and a string)\n");
		return 1;
	}
	csa.sa_handler = signal_handler;
	sigemptyset(&csa.sa_mask); // Not blocking any other signals
	csa.sa_flags = 0; //Use siginfo_t to get sender's PID
	sigaction(SIGUSR1, &csa, NULL);
	s = argv[2];
	pid = atoi(argv[1]);
	i = 0;
	while (s[i] != '\0')
	{
		binary = char_to_binary(s[i]);
		binary_free = binary;
		i++;
		while (*binary != '\0')
		{
			if (*binary == '0')
			{
				kill(pid, SIGUSR2);
				usleep(50);
			}
			else if (*binary == '1')
			{	
				kill(pid, SIGUSR1);
				usleep(50);
			}
			binary++;
		}
		free(binary_free);
	}
}

/* void send_signal(pid_t pid, char *s)
{

} */
