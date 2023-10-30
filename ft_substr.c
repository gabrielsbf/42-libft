#include "libft.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	char	*ptr;
	unsigned int	s_size;
	unsigned int	limit_index;

	limit_index = (start + len);
	str = (char *)s;
	s_size = (unsigned int)ft_strlen(str);
	if (len + start > s_size)
		ptr = (char *)malloc((s_size - start + 1) * sizeof(char));
	else
		ptr = (char *)malloc((len + 1) * sizeof(char));
	if (!(ptr))
		return (NULL);
	while (ptr && limit_index > start)
	{
		*ptr = str[start];
		start++;
		ptr++;
	}
	*ptr = '\0';
	return (ptr - len);
}
