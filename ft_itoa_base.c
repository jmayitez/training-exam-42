#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa_base(int value, int base)
{
	char	*s;
	long	n = (value < 0) ? -(long)value : value;
	int		sign = (value < 0 && base == 10) ? -1 : 0;
	int		i = (sign == -1) ? 2 : 1;	
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (value < 0) ? -(long)value : value;
	while (i-- + sign)
	{
		s[i] = (n % base < 10) ? n % base + '0' : n % base + 'A' - 10;
		n /= base;
	}
	s[i] = (i == 0) ? '-' : 0;
	return (s);
}

int		main(int ac, char **av)
{
	if (ac == 3)
		printf("%s", ft_itoa_base(atoi(av[1]), atoi(av[2])));
	return (1);
}