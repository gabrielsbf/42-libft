#include <stdio.h>
#include <ctype.h>
#include "ft_tolower.c"
int	ft_tolower(int c);

int	main()
{
	char a = 'P';
	printf("(NATIVE_FUNCTION)return of the value: '%c' is: %c\n", a, tolower(a));
	printf("(FT_FUNCTION)    return of the value: '%c' is: %c", a, ft_tolower(a));
	return (0);
}
