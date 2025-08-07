/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkarali <zkarali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:00:47 by zkarali           #+#    #+#             */
/*   Updated: 2025/08/07 18:10:42 by zkarali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 42
# include <unistd.h>
# include <stdlib.h>

char *get_next_line(int fd);
int newline_i(const char *s);
size_t str_len(const char *s);
char *str_join(const char *s1, const char *s2);
char *sub_str(const char *s, unsigned int start, size_t len);
char *str_chr(const char *s, int c);

#endif
