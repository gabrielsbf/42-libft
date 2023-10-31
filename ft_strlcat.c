/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:12:56 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/23 20:58:28 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//LEAK OF MEMORY

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen((char *)src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (size <= dest_len)
		return (src_len + size);
	while (src[i] != '\0' && size > (dest_len + i + 1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
// 1, 3, 4 e ultima
