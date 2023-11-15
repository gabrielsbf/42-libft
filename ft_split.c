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
	unsigned int	i;
	unsigned int	char_count;
	unsigned int	c_encounter;
	char			*ptr_trim;

	c_encounter = 0;
	char_count = 0;
	i = 0;
	ptr_trim = ft_strtrim(str, &c);
	while (ptr_trim[i++])
	{
		if (ptr_trim[i] == c && char_count >= 1)
		{
			char_count = 0;
			c_encounter++;
		}
		if (ptr_trim[i] == c && char_count == 0)
			char_count = 0;
		else
			char_count++;
	}
	return (c_encounter + 1);
}

static void	num_iter(char *ptr_trim, unsigned int *n_arr, char c)
{
	unsigned int	i_arr;
	unsigned int	char_count;
	unsigned int	i;

	i_arr = 0;
	char_count = 0;
	i = 0;
	while (ptr_trim[i])
	{
		if (ptr_trim[i] == c && char_count >= 1)
		{
			n_arr[i_arr] = char_count;
			// printf("Alocado na array: %d >> %d\n",i_arr, char_count);
			i_arr++;
			char_count = 0;
		}
		if (ptr_trim[i] == c && char_count == 0)
			char_count = 0;
		else
			char_count++;
		i++;
	}
	// printf("allocado na array %d(última) >> %d\n -------------------FIM do While do TRIM-------------------", i_arr, char_count);
	n_arr[i_arr] = char_count;
}

static unsigned int	*num_char(const char *str, char c)
{
	unsigned int	*n_arr;
	char			*ptr_trim;

	ptr_trim = ft_strtrim(str, &c);
	n_arr = (unsigned int *)malloc(num_arr(ptr_trim, c) * sizeof(int));
	if (!n_arr)
		return (NULL);
	num_iter(ptr_trim, n_arr, c);
	return (n_arr);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr_arr;
	unsigned int	i;
	unsigned int	*alloc_len;
	unsigned int	i_char;
	unsigned int	i_str;
	char	*ptr_trim;

	ptr_trim = ft_strtrim(s, &c);
	// printf("Trim >> %s\n", ptr_trim);
	i_str = 0;
	i_char = 0;
	i = 0;
	// printf("Arr alocados >> %d\n", num_arr(ptr_trim, c));
	ptr_arr = (char **)malloc(num_arr(ptr_trim, c) * sizeof(char *));
	if (!ptr_arr)
		return (NULL);
	while (i < num_arr(ptr_trim, c))
	{
		alloc_len = num_char(ptr_trim, c);
		// printf("\nno array %d, a alloc len tem o valor de >> %d\n",i, alloc_len[i]);
		ptr_arr[i] = (char *)malloc((alloc_len[i] + 1) * sizeof(char));
		if(!ptr_arr[i])
		{
			while (i-- >= 0)
				free(ptr_arr[i]);
			return (NULL);
		}
		while(alloc_len[i] > i_char)
		{
			// printf("\nEntrei While - alloc_len >> %d, i_char >> %d",alloc_len[i], i_char);
			while (ptr_trim[i_str] == c)
			{
				// printf("\nchar de index %d é igual a %c", i_str, c);
				i_str++;
				}
			ptr_arr[i][i_char] = ptr_trim[i_str];
			i_char++;
			i_str++;
		}
		ptr_arr[i][i_char] = '\0';
		i_char = 0;
		i++;
	}
	return (ptr_arr);
}

int	main()
{
	
	char *s = "split  ||this|for|me|||||!|";
	// int i = 0;
	char **result = ft_split(s, '|');
	printf("\nResposta é : %s", result[4]);
	// while (result[i])
	// {

	// 	free(result[i]);
	// 	i++;

	// }
	free(result);
}
