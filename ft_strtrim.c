#include "libft.h"
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	s_it;
	char			*s_cp;
	char			*set_it;
	unsigned int	ct_trim;

	ct_trim = 0;
	s_it = 0;
	set_it = 0;
	while (*s1)
	{
		while(*set)
		{
			if(*set == *s1)
				ct_trim++;
			set++;
		}
		if(ct_trim == 0)
			*s_cp = *(char *)s1;
		s1++;
		ct_trim = 0;
		set = set - (ft_strlen((char *)set) - 1) ;
	}
	return (s_cp);
}

int	main()
{
	const char	s1[31] = "Fazendo um teste, e tudo, mais";
	const char	set[] = ", ";
	char res = ft_strtrim(s1, set);
	printf("resposta é %s", res);
	return (0);

}
