/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:40:22 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/04/15 11:06:10 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// client takes 2 arguments (server PID, the string to communicate)
// must sent the string passed as argument to the server


/*char_to_bin
 1 iterar sobre elstring
 2 char_to_bin devuelve binario almacenarlo en un int o en un cha
 3 bucle iterando sobre el int para seleccionar cada valor y mandar una señal u otra.
 */


#include "minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Server confirmation recived\n");
}

void	send_char (int pid, unsigned char c)
{
	int	i;
	
	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i--;
	}
}

int	main(int argc, char *argv[])
{
	char	*s;
	int					pid;
	int					i;
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
	pid = ft_atoi(argv[1]);
	i = 0;

	while (s[i] != '\0')
	{
		send_char(pid, s[i]);
		i++;
	}
	send_char(pid, s[i]);
	return (0); /*no se si sirve para algo*/
}
