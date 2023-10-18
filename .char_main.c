#include "libft.h"
#include <ctype.h>
int	main()
{
	char a = 'P';
	printf("(NATIVE_FUNCTION)return of the value: '%c' is: %c\n", a, isalpha(a));
	printf("(FT_FUNCTION)    return of the value: '%c' is: %c", a, ft_isalpha(a));
	return (0);
}
