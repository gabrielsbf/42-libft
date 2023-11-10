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

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		i_begin;
	int		i_last;
	int		i_set;

	i_set = 0;
	i_begin = 0;
	i_last = ft_strlen((char *)s1) - 1;
	while (ft_strchr(set, s1[i_begin]) != 0)
		i_begin++;
	while (ft_strrchr(set, s1[i_last]) != 0)
		i_last--;
	ptr = ft_calloc((size_t)(i_last - i_begin + 2), sizeof(char));
	ptr = ft_substr(s1, i_begin, (size_t)i_last - i_begin + 1);
	return (ptr);
}
