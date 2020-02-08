#include <stdlib.h>
#include <stdio.h>

int len(long nb)
{
    int len = (nb <= 0) ? 1 : 0;
    while (nb != 0)
    {
        nb /= 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int nbr)
{
    long nb = nbr;
    int i = len(nb);
    char *res = (char*)malloc(sizeof(char) * (i + 1));
    res[i--] = '\0';
    if (nb == 0)
        return ((nb == 0) ? "0" : NULL);
    if (nb < 0)
    {
        res[0] = '-';
        nb *= -1;
    }
    while (nb > 0)
    {
        res[i] = (nb % 10) + '0';
        nb /= 10;
        i--;
    }
    return (res);
}

int	main(void)
{
	int i = 0;
	int tab[5] = {-2147483648, -42, 0, 42, 2147483647};

	while (i < 5)
		printf("%s\n", ft_itoa(tab[i++]));

	return 0;
}