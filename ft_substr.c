/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 20:08:14 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/31 20:08:15 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	s_size;
	unsigned int	limit_index;
	char			*str;
	char			*ptr;

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
