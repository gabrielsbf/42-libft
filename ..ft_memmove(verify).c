/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ..ft_memmove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:55:42 by gabrfern          #+#    #+#             */
/*   Updated: 2023/10/18 19:55:44 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	char	*strch1;
	char	*strch2;
	int		i;

	strch1 = (char *)str1;
	strch2 = (char *)str2;
	i = 0;
	while (strch2[i] != '\0' && i < (n))
	{
		strch1[i] = strch2[i];
		i++;
	}
	strch1[i] = '\0';
}


#include <string.h>
#include <stdio.h>
int	main()
{
	char src_or[7] = "teste1";
	char dest_or[10] = "teste 552";

	char src[7] = "teste1";
	char dest[10] = "teste 552";

	memmove(dest_or, src_or,10);
	printf("-------------função library-------------\nsrc_or: %s\ndest_or: %s\n", src_or, dest_or);
	ft_memmove(dest, src,10);
	printf("--------------ft_function--------------\nsrc: %s\ndest: %s\n", src, dest);
	return 0;
}
