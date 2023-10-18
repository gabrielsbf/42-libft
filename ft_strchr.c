#include "libft.h"

char *ft_strchr(const char *str, int c)
{
	int	i;
	char *strc;
	strc = (char * )str;
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return (strc + i);
		i++;
	}
	return (0);
}
