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
char  *char_to_binary(unsigned char c)
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
}