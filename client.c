// client takes 2 arguments (server PID, the string to communicate)
// must sent the string passed as argument to the server


/*char_to_bin
 1 iterar sobre elstring
 2 char_to_bin devuelve binario almacenarlo en un int o en un cha
 3 bucle iterando sobre el int para seleccionar cada valor y mandar una señal u otra.
 */


#include "minitalk.h"

char  *char_to_binary(unsigned char c)
{
    char num;
    int char_value;
    char *binary = malloc(9 * sizeof(char));
	int i = 7;

	if (!binary)
	{
        printf("malloc failed");
        return NULL;
    }
    ft_memset(binary, '0', 8);
    while (c != 0)
    {
        num = (c % 2) + '0';
        binary[i] = num;
        c = c / 2;
        i--;
    }
    binary[8] = '\0';
    return binary;
}

int main(int argc, char *argv[])
{
	char *s;
	int pid;  
	char *binary;
	int i;

	if (argc != 3)
	{
		printf("Error: You have to pass 2 arguments (process ID and a string)\n");
		return 1;
	}
	s = argv[2];
	pid = atoi(argv[1]);
	i = 0;
	while (s[i] != '\0')
	{
		binary = char_to_binary(s[i]);
		i++;
		while (*binary != '\0')
		{	
			if (*binary == '0')
			{
				printf("0\n");
				kill(pid, SIGUSR2);
				sleep(1);
			}
			else if (*binary == '1')
			{
				printf("1\n");	
				kill(pid, SIGUSR1);
				sleep(1);
			}
			binary++;
		}
	}

	/* kill(pid, SIGUSR1);
	sleep(1);
	kill(pid, SIGUSR2);
	sleep(1); */
	//como no he redefinido el manejador de las señales, la señal de sigterm, tiene el comportamiento por defecto, que es terminar el programa
	/*kill(pid, SIGTERM);
	sleep(1);*/

}