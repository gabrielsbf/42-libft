/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:14:59 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/23 19:15:13 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_big;
	size_t	i_little;
	char	*str;

	str = (char *)big;
	i_big = 0;
	i_little = 0;
	if (*little == 0 || ((!str) && len == 0))
		return ((char *)big);
	while (str[i_big] != '\0')
	{
		while (str[i_big] == little[i_little]
			&& len > i_big && str[i_big] != '\0')
		{
			i_big++;
			i_little++;
		}
		if (little[i_little] == '\0')
			return (str + (i_big - i_little));
		i_big++;
		i_little = 0;
	}
	return (0);
}
