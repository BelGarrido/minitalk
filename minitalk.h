/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:19:06 by anagarri          #+#    #+#             */
/*   Updated: 2025/04/15 11:02:26 by anagarri@st      ###   ########.fr       */
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
#include "ft_printf.h"

void	*ft_memset(void *ptr, int x, size_t n);
int		ft_atoi(const char *s);

#endif
