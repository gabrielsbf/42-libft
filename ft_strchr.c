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
	int	i;
	char *strc;
	strc = (char * )str;
	i = 0;
	while(str[i] != '\0')
	{
		if(str[i] == c)
			return (strc + i);
		i++;
	}
	if(str[i] == c)
		return (strc + (i + 1));
	return (0);
}
