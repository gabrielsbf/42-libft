/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:55:42 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/26 17:53:12 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_p;
	unsigned char	*src_p;
	size_t			limit;

	dest_p = (unsigned char *)dest;
	src_p = (unsigned char *)src;
	limit = 0;
	while (limit < n)
	{
		*dest_p = *src_p;
		src_p++;
		dest_p++;
		limit++;
	}
	return (dest);
}
