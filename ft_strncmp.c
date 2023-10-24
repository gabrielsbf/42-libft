/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 19:14:45 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/23 19:14:47 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//PARA ESSA FUNÇÃO SERIA INTERESSANTE JÁ TER O ARQUIVO .H PARA USAR
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 1 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
