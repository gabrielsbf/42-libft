#include "libft.h"

static unsigned int	alloc_arr(const char *str, char c)
{
	unsigned int    i;
    unsigned int    char_count;
    unsigned int    c_encounter;
    char            *ptr_trim;

    c_encounter = 0;
    char_count = 0;
	i = 0;
    ptr_trim = ft_strtrim(str, &c);
	while (ptr_trim[i] != '\0')
	{
		if (ptr_trim[i] == c && char_count > 1)
        {
           char_count = 0;
			c_encounter++;
        }
        if(ptr_trim[i] == c && char_count == 0)
            char_count = 0;
        else
            char_count++;
		i++;
	}
    printf("C encounter is giving: %d", c_encounter);
	return (c_encounter);
}

static unsigned int *alloc_char(const char *str, char c)
{
    unsigned int    i;
    unsigned int    *n_arr;
    unsigned int    i_arr;
    unsigned int    char_count;
    char            *ptr_trim;

    n_arr = (unsigned int *)malloc(alloc_arr(str, c) * sizeof(int));
    if (!n_arr)
        return (NULL);
    i = 0;
    i_arr = 0;
    ptr_trim = ft_strtrim(str, &c);
    char_count = 0;
    while (ptr_trim[i] != '\0')
	{
		if (ptr_trim[i] == c && char_count > 1)
        {
            n_arr[i_arr] = char_count; 
            char_count = 0;
            i_arr++;        
        }
        if(ptr_trim[i] == c && char_count == 0)
            char_count = 0;
        else
            char_count++;
		i++;
	}
    printf("last i_array is : %d\n", i_arr);
    n_arr[i_arr] = char_count;
    return (n_arr);
}

int main()
{
    #include <stdio.h>
    const char value[] = ",,Testing if, it,,, cou,n ,ts, ok, a,as, asdaf,g";
    char c = ',';
    unsigned int *arr = alloc_char(value, c);

    printf("Result is %d",arr[11]);
    return (0);
}