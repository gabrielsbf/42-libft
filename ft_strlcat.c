/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:12:56 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/23 19:12:58 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_static_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	src_itr;
	size_t	dest_itr;
	size_t	dest_len;

	dest_len = ft_static_strlen(dest);
	dest_itr = dest_len;
	src_itr = 0;
	if (size < dest_itr)
		return (ft_static_strlen((char *)src) + size);
	while (src[src_itr] != '\0' && (size - 1) > dest_itr)
	{
		dest[dest_itr] = src[src_itr];
		dest_itr++;
		src_itr++;
	}
	while (dest_itr < size)
	{
		dest[dest_itr] = '\0';
		dest_itr++;
	}
	
	return (dest_len + ft_static_strlen((char *)src));
}
