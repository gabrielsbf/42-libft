#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	i;
	char *strc;
	strc = (char * )str;
	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	while(i > 0)
	{
		if(str[i] == c)
			return (strc + (i + 1));
		i--;
	}

	return (0);
}
