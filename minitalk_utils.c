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

int	ft_atoi(const char *s)
{
	int	i;
	int	neg;
	int	number;

	i = 0;
	neg = 1;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s [i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
		{
			neg = -neg;
		}
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + s[i] - '0';
		i++;
	}
	return (number * neg);
}

/* char  *char_to_binary(unsigned char c)
{
    char num;
    int char_value;
    char *binary = malloc(9 * sizeof(char));
	int i = 7;

	if (!binary)
        return NULL;
    ft_memset(binary, '0', 9);
    while (c != 0)
    {
        num = (c % 2) + '0';
        binary[i] = num;
        c = c / 2;
        i--;
    }
    binary[8] = '\0';
    return binary;
} */