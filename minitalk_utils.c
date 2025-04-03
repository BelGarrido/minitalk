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

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return i;
}