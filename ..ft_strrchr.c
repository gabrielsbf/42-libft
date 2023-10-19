#include "libft.h"
//PARA ESSA FUNÇÃO SERIA INTERESSANTE JÁ TER O ARQUIVO .H PARA USAR
#include "libft.h"

char *ft_strrchr(const char *str, int c)
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
