#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;

	i = 0;
	while(src[i] != '\0' && size > i)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while(src[i] != '\0')
		i++;
	return (i);
}
