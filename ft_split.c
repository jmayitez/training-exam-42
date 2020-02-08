#include <stdio.h>
#include <stdlib.h>

int     is_blank(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int     count_words(char *s)
{
        int count = 0;
        while (*s)
        {
            while (*s && is_blank(*s))
                s++;
            if (*s && !is_blank(*s))
            {
                count++;
            while (*s && is_blank(*s))
                s++;
            }
        }
    return (count);
}

char    *cpy_word(char *s)
{
    char *word;
    int i = 0;

    while (s[i] && !is_blank(s[i]))
        i++;
    if (!(word = (char *)malloc(sizeof(*word) * (i + 1))))
        return (NULL);
    i = 0;
    while (s[i] && !is_blank(s[i]))
    {
        word[i] = s[i];
        i++;
    }
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str)
{
    char **tab = (char **)malloc(sizeof(char *) * (count_words(str) + 1));

    int i = 0;
    while (*str)
    {
        while (*str && is_blank(*str))
            str++;
        if (*str && !is_blank(*str))
        {
            tab[i] = cpy_word(str);
            i++;
            while (*str && is_blank(*str))
                str++;
        }
        tab[i] = '\0';
        return (tab);
    }
}


int		main(int ac, char **av)
{
	char **arr;

	char *phrase = "   Hello,   Flavio\t Wuensche!  ";
	arr = ft_split(phrase);
	printf("%s\n", arr[0]);
	printf("%s\n", arr[1]);
	printf("%s\n", arr[2]);
	printf("%s\n", arr[3]);
}
