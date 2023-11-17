/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 19:36:53 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/26 19:36:55 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	char	*ptr;

	if(num == 0 || size == 0)
	{
		num = 1;
		size = 1;
	}
	i = 0;
	ptr = (char *)malloc(num * size);
	if (!ptr)
		return (NULL);
	ft_bzero((void *)ptr, num * size);
	return ((void *)ptr);
}
