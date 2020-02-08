#include <unistd.h>

int is_blank(char c)
{
	return (c == ' ' || c == '\t');
}

void	rev_wstr(char *s, int first)
{
	int start;
	int i = 0;
	if (s[i])
	{
		while (s[i] && (is_blank(s[i])))
			i++;
		if (!s[i])
			return ;
		start = i;
		while (s[i] && (!is_blank(s[i])))
			i++;
		rev_wstr(&s[i], 0);
		write (1, &s[start], i - start);
		if (!first)
			write (1, " ", 1);
	}
}

int		main(int ac, char **av)
{
	if (ac == 2)
		rev_wstr(av[1], 1);
	write(1, "\n", 1);
	return (0);
}