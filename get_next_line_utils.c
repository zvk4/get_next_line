/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:00:27 by zkarali           #+#    #+#             */
/*   Updated: 2025/08/07 18:44:55 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t str_len(const char *s)
{
    size_t i;

    i = 0;
    if (!s)
        return (0);
    while(s[i])
        i++;
    return (i);
}

char	*str_dup(const char *s)
{
	int		i;
	char	*copy;

    if (!s)
        return (NULL);
	i = 0;
	while (s[i])
		i++;
	copy = malloc(i + 1);
	if (!copy)
		return (0);
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

char *str_join(const char *s1, const char *s2)
{
    char *str;
    size_t i;
    size_t j;
    
    i = 0;
    j = 0;
    if (!s1 && !s2)
        return (NULL);
    if (!s1)
        return (str_dup(s2));
    if (!s2)
        return (str_dup(s1));
    str = malloc(str_len(s1) + str_len(s2) + 1);
    if (!str)
        return (NULL);
    while (s1[i])
    {
        str[i] = s1[i];
        i++;
    }
    while (s2[j])
    {
        str[i + j] = s2[j];
        j++;
    }
    str[i + j] = '\0';
    return (str);
}

char *sub_str(const char *s, unsigned int start, size_t len)
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
        return(str);
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

int newline_i(const char *s)
{
    int i;
    
    i = 0;
    if (!s)
        return (-1);
    while (s[i])
    {
        if (s[i] == '\n')
            return (i);
        i++;
    }
    return (-1);
}
