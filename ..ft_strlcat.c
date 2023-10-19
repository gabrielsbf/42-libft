#include "libft.h"
//LEAK OF MEMORY
size_t ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	total_len;



	i = 0;
	dest_len = 0;
	total_len = 0;
	while (dest[dest_len] != '\0' && size > dest_len)
		dest_len++;
	while (src[i] != '\0' && size > dest_len)
	{
		dest[dest_len] = src[i];
		dest_len++;
		i++;
	}
	dest[dest_len] = '\0';
	while(src[i] != '\0')
	{
		total_len++;
		i++;
	}
	return (dest_len + total_len);
}
