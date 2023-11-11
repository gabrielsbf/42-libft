/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:58:17 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/18 17:58:18 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	*strc;
	int		i;

	strc = (char *)str;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)&strc[i]);
		i++;
	}
	if (str[i] == c)
		return ((char *)&strc[i]);
	return (0);
}
