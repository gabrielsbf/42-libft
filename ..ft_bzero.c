#include "libft.h"

 void ft_bzero(void * s, size_t n)
 {
	char	*mem;
	size_t i;
	size_t len;

	i = 0;
	mem = (char *) s;
	while (mem[i] != '\0' && i < n)
	{
		mem[i] = '\0';
		i++;
	}

 }

#include <stdio.h>
 int	main()
 {
	char arr[11] = "TESTE12356";
	size_t n = 5;

	ft_bzero(arr, n);
	printf("valor da arr é %s",arr);
	return 0;

 }
