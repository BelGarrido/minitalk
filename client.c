/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 10:40:22 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/04/22 13:30:46 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		printf("Signal recived\n");
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
