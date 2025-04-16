/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:40:40 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/04/16 09:55:35 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	update_char_from_signal(unsigned char c, int signum)
{
	if (signum == SIGUSR1)
		c = c << 1 | 1;
	else if (signum == SIGUSR2)
		c = c << 1;
	return (c);
}

void	signal_handler(int signum, siginfo_t *info, void *context)
{
	static pid_t			client_pid = 0;
	static unsigned char	c = 0;
	static int				char_index = 0;

	context = context;
	if (client_pid == 0)
		client_pid = info->si_pid;
	if (client_pid != info->si_pid)
	{
		client_pid = info->si_pid;
		c = 0;
		char_index = 0;
	}
	c = update_char_from_signal(c, signum);
	char_index++;
	if (char_index == 8)
	{
		if (c == '\0')
		{
			client_pid = 0;
			write (1,"\n", 1);
		}
		else
			write (1, &c, 1); //no estoy segura de esto
		c = 0;
		char_index = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = signal_handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_printf("Yey server it's working! It's process ID is %d\n", getpid());
	while (1)
		pause();
	return (0);
}
