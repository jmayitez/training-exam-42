#include <unistd.h>

int     is_blank(char c)
{
    return (c == ' ' || c == '\t');
}

void    rostring(char *s)
{
    int i = 0;
    int first_word_len = 0;
    while (s[i])
    {
        while (is_blank(s[i]))
            i++;
        if (s[i] && !is_blank(s[i]))
        {
            if (first_word_len == 0)
                while (s[i] && !is_blank(s[i++]))
                    first_word_len++;
            else
            {
                while (s[i] && !is_blank(s[i]) && write(1, &s[i++], 1));
                write(1, " ", 1);
            }
        }
    }
    i = 0;
    while (is_blank(s[i]))
        i++;
    while (first_word_len--)
        write(1, &s[i++], 1);
}

int     main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
    return (0);
}