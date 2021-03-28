#include "libft.h"

int
    ft_isnumber(char *s)
{
    int len;
    int i;

    len = ft_strlen(s);
    i = 0;
    while (ft_isdigit(s[i]))
        i++;
    if (i == len)
        return (1);
    return (0);
}