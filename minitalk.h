/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri <anagarri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:19:06 by anagarri          #+#    #+#             */
/*   Updated: 2025/04/15 14:15:16 by anagarri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stddef.h> // size_t
# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <stdio.h> // printf
# include <stdint.h>
# include <signal.h>
# include "ft_printf.h"

void	send_char(int pid, unsigned char c);
int		ft_atoi(const char *s);

#endif
