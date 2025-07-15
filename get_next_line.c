#include <fcntl.h>
#include <stdlib.h>
#define BUF_SIZE 42

int newline_i(const char *s)
{
    int i = 0;
    while (s && s[i])
    {
        if (s[i++] == '\n')
            return (i);
    }
    return (-1);
}

char *get_next_line(int fd)
{
    static char *rest;
    char *buf;
    char *line;
    char *temp;
    char *oldrest;
    int    byte_read;
    int nl_i;

    nl_i = newline_i(rest);
    byte_read = 1;
    if (BUF_SIZE <= 0 || fd < 0)
        return (0);
    buf = malloc(BUF_SIZE + 1);
    if (!buf)
        return NULL;
    while ((byte_read = read(fd, buf, BUF_SIZE)) > 0)
    {
        buf[byte_read] = '\0';
        rest = str_join(rest, buf);
        if (newline_i >= 0)
        {
            line = sub_str(rest, 0, nl_i);
            temp = str_len(rest) - (nl_i + 1);
            oldrest = rest;
            rest = sub_str(rest, newline_i(oldrest) + 1, temp);
            free(oldrest);
            return (line);
        }
    }
    free(buf);
    if (rest && *rest) 
    {
        line = sub_str(rest, 0, str_len(rest));
        free(rest);
        rest = NULL;
        return (line);
    }
    return (0);
}