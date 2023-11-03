//ELE PEGA APENAS UMA VEZ O CHARSET, DEPOIS DISSO,
//PODE RETORNAR O RESTO DO PONTEIRO!
#include "libft.h"

static unsigned int	ft_trim_count(char const *s1, char const *set)
{
	unsigned int	set_itr;
	unsigned int	set_len;
	unsigned int	m_count;
	
	m_count = (unsigned int)ft_strlen((char *)s1);
	set_len = (unsigned int)ft_strlen((char *)set);
	set_itr = 0;
	while(*s1)
	{
		while (*s1 != *set && set_itr < set_len)
		{
			set_itr++;
			set++;
		}
		if (*s1 == *set )
			m_count--;
		s1++;
		set = set - (set_itr);
		set_itr = 0;
	}
	return (m_count);
}
// Peguei uma parte da função principal e cortei pra cá!
// static void	itr_set(unsigned int set_itr, char const *s1, char const *set)
// {
// 	set_itr = 0;
// 	while (*s1 != *set && *set)
// 	{
// 		set_itr++;
// 		set++;
// 	}
// }

char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	count_trim;
	unsigned int	set_itr;
	unsigned int	ptr_iter;
	char			*ptr;

	count_trim = ft_trim_count(s1, set);
	ptr_iter = 0;
	ptr = (char *)malloc((count_trim + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	while(ptr_iter < count_trim)
	{
		set_itr = 0;
		while (*s1 != *set && *set)
		{
			set_itr++;
			set++;
		}
		if(*s1 != *set)
		{
			*ptr = *(char *)s1;
			ptr++;
			ptr_iter++;
		}
		s1++;
		set = set - (set_itr);
	}
	*ptr = '\0';
	return (ptr - count_trim);
}
int	main()
{
	const char	s1[8] = "exemplo";
	const char	set[2] = "e";
	char *res = ft_strtrim(s1, set);
	printf("answer is %s\n", res);
	return (0);

}
