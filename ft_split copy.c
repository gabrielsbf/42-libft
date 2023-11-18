/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabrfern <gabrfern@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 20:05:57 by gabrfern          #+#    #+#             */
/*   Updated: 2023/11/14 20:32:09 by gabrfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	num_arr(const char *str, char c)
{
	int				i;
	unsigned int	char_count;
	unsigned int	c_encounter;

	c_encounter = 0;
	char_count = 0;
	i = 0;
	if (c == '\0')
	return (1);
	while (str[i])
	{
		if (str[i] == c && char_count >= 1)
		{
			char_count = 0;
			c_encounter++;
		}
		if (str[i] == c && char_count == 0)
			char_count = 0;
		else
			char_count++;
		i++;
	}
	return (c_encounter + 1);
}


static unsigned int	num_char(const char *str, char c, unsigned int index)
{
	unsigned int	i_arr;
	unsigned int	char_count;
	unsigned int	i;
	char			*ptr_trim;

	ptr_trim = ft_strtrim(str, &c);
	i_arr = 0;
	char_count = 0;
	i = 0;
	while (ptr_trim[i])
	{
		if (ptr_trim[i] == c && char_count >= 1)
		{
			if(i_arr == index)
				break;
			i_arr++;
			char_count = 0;
		}
		if (ptr_trim[i] == c && char_count == 0)
			char_count = 0;
		else
			char_count++;
		i++;
	}
	free(ptr_trim);
	return (char_count);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr_arr;
	unsigned int	i;
	unsigned int	i_char;
	unsigned int	alloc_len;
	unsigned int	index_s;

	i = 0;
	ptr_arr = (char **)malloc(num_arr(s, c) * sizeof(char *));
	if (c == '\0')
	{
		ptr_arr[0] = malloc(1 * sizeof(char *));
		ptr_arr[0] = NULL;
		return (ptr_arr);
	}
	if (!ptr_arr)
		return (NULL);
	index_s = 0;
	while (i < num_arr(s, c))
	{
		// printf("\n\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\nINICIANDO O WHILE PRINCIPAL\nAloquei na array %d, %d bytes\n", i, num_char(s,c,i) + 1);
		alloc_len = num_char(s, c, i);
		ptr_arr[i] = (char *)malloc((num_char(s,c,i) + 1) * sizeof(char));
		if (!ptr_arr[i])
		{
			// printf("Ponteiro entrou no erro");
			while (i >= 0)
				free(ptr_arr[i--]);
			free(ptr_arr);
			return (NULL);
		}
		i_char = 0;
		while(i_char < alloc_len)
		{
			// printf("\nvalor de s + index_s é: %c, index_s é: %d, ponteiro de s permanece em: %c",*(s + index_s), index_s, *s);
			while (*(s + index_s) == c)
				index_s++;
			ptr_arr[i][i_char] = *(s + index_s);
			index_s++;
			i_char++;
		}
		ptr_arr[i][i_char] = '\0';
		i++;
	}
	ptr_arr[i] = NULL;
	return (ptr_arr);
}

int main ()
{
	char *s = "      split       this for   me  !       ";
	char **result = ft_split(s, ' ');

	while(*result)
	{
		printf("Valor de resultado é >> %s\n", *result);
		result++;
	}
}
