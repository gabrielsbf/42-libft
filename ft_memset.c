#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p_mem;
	size_t		limit;

	limit = 0;
	p_mem = (unsigned char *)s;
	while (*p_mem && n > limit)
	{
		*p_mem = c;
		p_mem++;
		limit++;
	}
	return s;
}
