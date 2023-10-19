#include "libft.h"
//PARA ESSA FUNÇÃO SERIA INTERESSANTE JÁ TER O ARQUIVO .H PARA USAR

char *	ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;
	char	*str;

	str = (char *)big;

	i_big = 0;
	i_little = 0;
	while (str[i_big] != '\0')
	{
		while (str[i_big] == little[i_little] && len > i_big && str[i_big] != '\0')
		{
			i_big++;
			i_little++;
		}
		if (little[i_little] == '\0')
				return (str + (i_big - i_little));
		i_big++;
		i_little = 0;
	}
	return (0);
}

#include <string.h>
#include <stdio.h>

int main()
{
    char first[18] = "Teste com a maior";
    char last[6] = "maior";
    char *strnstr = ft_strnstr(first, last, 100);
	printf("valor de strnstr é : %s", strnstr);

    return(0);
}
