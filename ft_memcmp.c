#include "libft.h"

int ft_memcmp(const void *s1, const void *s2, size_t n)
{
    unsigned char   *p_s1;
    unsigned char   *p_s2;
    size_t  limit;

    limit = 0;
    p_s1 = (unsigned char *)s1;
    p_s2 = (unsigned char *)s2;
    if(n == 0)
        return (0);
    while (p_s1 && p_s2 && limit < n)
    {
        if (*p_s1 != *p_s2)
            return *p_s1 - *p_s2;
        limit++;
        p_s1++;
        p_s2++;
    }
    p_s1--;
    p_s2--;
    return (*p_s1 - *p_s2);
}