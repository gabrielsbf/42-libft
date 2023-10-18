#include "libft.h"

int	ft_isalnum(int c)
{
	int check;

	if((c >= 48 && c <= 57) || (c >= 97 && c <= 122) || (c >= 65 && c <= 90))
		check = 1;
	else
		check = 0;
	return check;
}
