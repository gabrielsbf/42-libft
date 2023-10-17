#include <stdio.h>
#include <string.h>
#include "ft_strlen.c"

int	ft_strlen(char *str);

int	main()
{
	char *a = "";
	printf("(NATIVE_FUNCTION)return of the value: '%s' is: %d\n", a, strlen(a));
	printf("(FT_FUNCTION)    return of the value: '%s' is: %d", a, ft_strlen(a));
	return (0);
}
