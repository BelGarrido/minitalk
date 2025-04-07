/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:32:30 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/04/04 14:06:47 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// must be started first
// after its launch it has to print its PID
// must print the string after receiving the the string from client
// must display the string pretty quickly
// server must be able to receive several string from differents clients
// in a row without needing to restart
// communication must be done only using UNIX signals
// you only can use SIGUSR1 and SIGUSR2

#include "minitalk.h"

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t			client_pid;
	static unsigned char	c = 0;
	static int				char_index;

	client_pid = 0;
	char_index = 0;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (signum == SIGUSR1)
		c = c << 1 | 1;
	else if (signum == SIGUSR2)
		c = c << 1;
	char_index++;
	kill(info->si_pid, SIGUSR1);
	if (char_index == 8)
	{
		write (1, &c, 1);
		c = 0;
		char_index = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Yey server it's working! It's process ID is %d\n", getpid());
	while (1)
		pause();
	write (1, "\n", 1);
	return (0);
}
