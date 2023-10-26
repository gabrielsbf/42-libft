/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:46:26 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/24 17:46:30 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr( const void *str, int ch, size_t n )
{
	unsigned char	*ptr;
	unsigned char	c;
	size_t			limit;

	c = (unsigned char)ch;
	limit = 0;
	ptr = (unsigned char *)str;
	while (*ptr && n > limit)
	{
		if (*ptr == c)
			return ((void *)ptr);
		ptr++;
		limit++;
	}
	return (NULL);
}
