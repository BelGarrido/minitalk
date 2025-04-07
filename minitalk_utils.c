/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:32:48 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/04/04 13:55:39 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	*ft_memset(void *ptr, int x, size_t n)
{
	size_t	i;
	char	*ptr2;

	i = 0;
	ptr2 = (char *) ptr;
	while (i < n)
	{
		ptr2[i] = x;
		i++;
	}
	return (ptr);
}

char	*char_to_binary(unsigned char c)
{
	char	num;
	int		char_value;
	char	*binary;
	int		i;

	if (!binary)
		return (NULL);
	binary = malloc(9 * sizeof(char));
	ft_memset(binary, '0', 8);
	i = 7;
	while (c != 0)
	{
		num = (c % 2) + '0';
		binary[i] = num;
		c = c / 2;
		i--;
	}
	binary[8] = '\0';
	return (binary);
}
