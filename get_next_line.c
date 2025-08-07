/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:59:27 by zkarali           #+#    #+#             */
/*   Updated: 2025/08/07 19:01:45 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *extra_line(char **rest, int nl_i)
{
    char *line;
    char *oldrest;
    int len;

    line = sub_str(*rest, 0, nl_i);
    len = str_len(*rest) - (nl_i + 1);
    oldrest = *rest;
    *rest = sub_str(*rest, nl_i + 1, len);
    free(oldrest);
    return (line);
}

char *get_next_line(int fd)
{
    static char *rest;
    char *buf;
    char *line;
    int byte_read;
    int nl_i;

    if (BUF_SIZE <= 0 || fd < 0)
        return (NULL);
    buf = malloc(BUF_SIZE + 1);
    if (!buf)
        return (NULL);
    byte_read = 1;
    while ((nl_i = newline_i(rest)) < 0
        && (byte_read = read(fd, buf, BUF_SIZE)) > 0)
    {
        buf[byte_read] = '\0';
        rest = str_join(rest, buf);
    }
    free(buf);
    if (nl_i >= 0)
        return (extra_line(&rest, nl_i));
    if (rest && *rest)
    {
        line = sub_str(rest, 0, str_len(rest));
        free(rest);
        rest = NULL;
        return (line);
    }
    return (NULL);
}	
