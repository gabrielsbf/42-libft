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
	char	*ptr_trim;

	ptr_trim = ft_strtrim(str, &c);
	// printf("PARA O TRIM:\nstr é: '%s' e c é '%c' >> ptr_trimmed é :'%s'\n", str, c, ptr_trim);
	c_encounter = 0;
	char_count = 0;
	i = 0;
	while (ptr_trim[i])
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
		i++;
	}
	return (c_encounter + 1);
}

static void	num_iter(char *ptr_trim, unsigned int *n_arr, char c)
{
	unsigned int	i_arr;
	unsigned int	char_count;
	unsigned int	i;

	//printf("\nO que pode ter acontecido com o meu ALLOC_LEN\n------------------------------------\nDentro de num_iter, depois da trim>>'%s'\n",ptr_trim);
	i_arr = 0;
	char_count = 0;
	i = 0;
	while (ptr_trim[i])
	{
		////printf("\nptr_trim no indice %d é :%d\n",i, ptr_trim[i]);
		if (ptr_trim[i] == c && char_count >= 1)
		{
			n_arr[i_arr] = char_count;
			i_arr++;
			char_count = 0;
		}
		if (ptr_trim[i] == c && char_count == 0)
			char_count = 0;
		else
			char_count++;
		i++;
	}
	//printf("\nO que pode ter acontecido com o meu ALLOC_LEN\n------------------------------------\nvalor de n_arr em 0 >> %d", n_arr[0]);
	n_arr[i_arr] = char_count;
}

static unsigned int	*num_char(const char *str, char c)
{
	//printf("\nO que pode ter acontecido com o meu ALLOC_LEN\n------------------------------------\nstr >> '%s', c >> '%c'\n", str,c );
	unsigned int	*n_arr;
	char			*ptr_trim;

	ptr_trim = ft_strtrim(str, &c);
	n_arr = (unsigned int *)malloc(num_arr(str, c) * sizeof(int));
	if (!n_arr)
	{
		//printf("\nmeu n_arr deu errado");
		return (NULL);
	}
	//printf("\nO que pode ter acontecido com o meu ALLOC_LEN\n------------------------------------\nvai entrar na função num_iter\n");
	num_iter(ptr_trim, n_arr, c);
	return (n_arr);
}

static char	*iter_split(char **ptr_arr, char *ptr_trim, char c, unsigned int i)
{
	unsigned int	i_char;
	unsigned int	alloc_len;

	alloc_len = num_char(ptr_trim, c)[0];
	//printf("\nFunção iter_split\nalloc_len tem valor de >> %d\n", alloc_len);
	i_char = 0;
	while (alloc_len > i_char)
	{
		//printf("Valor de ptr_trim é >> %d, que representa o caracter '%c'\n", *ptr_trim, *ptr_trim);
		while (*ptr_trim == c)
		{
			//printf("Esse valor foi igual a %c >> ptr_trim incrementado pro próximo" , c);
			ptr_trim++;
		}
		ptr_arr[i][i_char] = *ptr_trim;
		//printf("\nna array %d, o caracter na posição %d é o do código ascii >> %d, que representa o caracter %c", i, i_char, ptr_arr[i][i_char],ptr_arr[i][i_char]);
		i_char++;
		ptr_trim++;
	}
	ptr_arr[i][i_char] = '\0';
	return (ptr_trim);
}

char	**ft_split(char const *s, char c)
{
	char			**ptr_arr;
	unsigned int	i;
	char			*ptr_trim;

	ptr_trim = ft_strtrim(s, &c);
	//printf("\nptr_trim é:'%s'\n", ptr_trim);
	i = 0;
	ptr_arr = (char **)malloc(num_arr(s, c) * sizeof(char *));
	// printf("numero de arrays alocadas: %d\n", num_arr(s,c));
	if (!ptr_arr)
		return (NULL);
	while (i < num_arr(s, c))
	{
		//printf("\n\n/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*/*\nINICIANDO O WHILE PRINCIPAL\nAloquei na array %d, %d bytes\n", i, num_char(s,c)[i] + 1);
		ptr_arr[i] = (char *)malloc((num_char(s,c)[i] + 1) * sizeof(char));
		if (!ptr_arr[i])
		{
			//printf("Ponteiro entrou no erro");
			while (i-- >= 0)
				free(ptr_arr[i]);
			return (NULL);
		}
		//printf("\n-------------------------------\nEntrando na ITER_SPLIT\n");
		ptr_trim = iter_split(ptr_arr, ptr_trim, c, i++);
	}
	ptr_arr[i] = NULL;
	return (ptr_arr);
}
int	main()
{
	const char *s = "0 0 0 0 0 0 0 0 0";
	int i = 0;
	const char v = ' ';
	char **result = ft_split(s, v);

	while (result[i])
	{
		printf("Result is: '%s'\n",result[i]);
		free(result[i]);
		i++;

	}
	free(result);
}
