/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri <anagarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:40:22 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/05/06 10:53:54 by anagarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_ack = 0;

void	send_char(int pid, unsigned char c)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		g_ack = 0;
		if (c >> i & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (!g_ack)
			pause();
		i--;
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		g_ack = 1;
		printf("Signal recived\n");
	}
}

int	main(int argc, char *argv[])
{
	char				*s;
	int					pid;
	int					i;
	struct sigaction	csa;

	if (argc != 3)
	{
		printf("Error: Expecting 2 arguments (process ID and a string)\n");
		return (1);
	}
	csa.sa_handler = signal_handler;
	sigemptyset(&csa.sa_mask);
	csa.sa_flags = 0;
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
	return (0);
}
