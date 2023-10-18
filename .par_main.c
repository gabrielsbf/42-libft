#include <stdio.h>
#include <string.h>
#include "ft_strchr.c"

char *ft_strchr(const char *str, int c);

int	main()
{
	char lim = '.';
	const char * str = "Esta Tudo Bem!.";
	printf("-----------BEGGINING OF THE NATIVE FUNCTION-----------\n");
	printf("lim: %c,\nphrase: %s\nResult of the function: %s\n", lim, str, strchr(str, lim));
	printf("-----------END OF THE NATIVE FUNCTION-----------------\n");
	printf("-----------BEGGINING OF THE FT_FUNCTION---------------\n");
	printf("lim: %c,\nphrase: %s\nResult of the function: %s\n", lim, str, ft_strchr(str, lim));
	printf("-----------END OF THE FT_FUNCTION---------------------\n");
	return (0);
}
