/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 17:57:35 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/18 17:57:43 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	minus;
	int	i;
	int	result;

	minus = 0;
	result = 0;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		minus = (str[i] == 45);
		i++;
	}
	while (str[i] != '\0' && (str[i] >= 48 && str[i] <= 57))
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	if (minus != 0)
		result *= -1;
	return (result);
}
