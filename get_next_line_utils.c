#include <stdlib.h>

size_t str_len(const char *s)
{
    size_t i;

    i = 0;
    while(s[i])
        i++;
    return (i);
}

char *str_join(char const *s1, char const *s2)
{
    char *str;
    int i;
    int j;

    i = 0;
    j = 0;
    str = malloc(str_len(s1) + str_len(s2) + 1);
    if (!str)
        return (NULL);
    while(s1[i])
        str[i] = s1[i++];
    while (s2[j])
        str[i + j] = s2[j++];
    str[i + j] = '\0';
    return (str);
}

char *str_chr(const char *s, int c)
{
    size_t i;

    i = 0;
    while(*s)
    {
        if ((unsigned char)*s == (unsigned char)c)
            return ((char *)s);
        s++;
    }
    if ((unsigned char)c == '\0')
        return ((char *)s);
    return (0);
}

char *sub_str(char const *s, unsigned int start, size_t len)
{
    size_t i;
    size_t s_len;
    char *str;

    if (!s)
        return (NULL);
    s_len = str_len(s);
    if (start >= s_len)
    {
        str = malloc(1);
        if (!str)
            return (NULL);
        str[0] = '\0';
        return (str);
    }
    if (len > s_len - start)
        len = s_len - start;
    str = malloc(len + 1);
    if (!str)
        return (NULL);
    i = 0;
    while (i < len)
    {
        str[i] = s[start + i];
        i++;
    }
    str[i] = '\0';
    return (str);
}