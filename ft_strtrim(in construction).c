/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:08:13 by gabrfern          #+#    #+#             */
/*   Updated: 2023/11/03 14:08:14 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//ELE PEGA APENAS UMA VEZ O CHARSET, DEPOIS DISSO,
//PODE RETORNAR O RESTO DO PONTEIRO!
//INCLUIR NO MAKE
#include "libft.h"

static unsigned int	ft_trim_count(char const *s1, char const *set)
{
	char	*ptr;
	int		itr_set;

	itr_set = 0;
	
	while(set[itr_set] != '\0')
	{
		ptr = ft_strrchr(s1, set[itr_set]);
	}

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
	while (ptr_iter < count_trim)
	{
		set_itr = 0;
		while (*s1 != *set && *set)
		{
			set_itr++;
			set++;
		}
		if (*s1 != *set)
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
// int	main()
// {
// 	const char	s1[8] = "exemplo";
// 	const char	set[2] = "e";
// 	char *res = ft_strtrim(s1, set);
// 	printf("answer is %s\n", res);
// 	return (0);

// }
