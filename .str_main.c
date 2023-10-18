#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "ft_atoi.c"

int	ft_atoi(const char *str);

int	main()
{
	char *a = "-2147483648";
	printf("(NATIVE_FUNCTION)return of the value: '%s' is: %d\n", a, atoi(a));
	printf("(FT_FUNCTION)    return of the value: '%s' is: %d", a, ft_atoi(a));
	return (0);
}
