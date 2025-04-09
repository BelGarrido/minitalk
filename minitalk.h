/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:19:06 by anagarri          #+#    #+#             */
/*   Updated: 2025/04/05 12:20:42 by anagarri@st      ###   ########.fr       */
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

extern int str_len;

//initialized the binary string to '0'
void	*ft_memset(void *ptr, int x, size_t n);
char	*char_to_binary(unsigned char c);

#endif


// LIST OF THINGS TO CHANCE LATER

	//PRINTF -->FT_PRINTF
	//ATOI -->FT_ATOI