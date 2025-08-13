#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

// void recursive(int fd)
// {
//     char *line;

//     line = get_next_line(fd);
//     if (line)
//     {
//         recursive(fd);
//         printf("%s", line);
//         free(line);
//     }
// }

// int main()
// {
//     int fd = open("deneme", O_RDONLY);
//     char *line;

//     line = get_next_line(fd);
//     printf("%s", line);
//     free(line);
//     close(fd);
// }

// int main()
// {
//     int fd = open("deneme", O_RDONLY);
//     char *line;

//     while ((line = get_next_line(fd)))
//     {
//         printf("%s", line);
//         free(line);
//     }
//     close(fd);
// }

// int sum(int a)
// {
//     static char b;
//     return (b += a);
// }
// int main()
// {
//     int c;
//     while (1)
//     {
//         c = sum(1);
//         printf("%d\n", c);
//         if (c == 4)
//             break;
//     }
// }

// int main()
// {
//     int fd=open("deneme", O_RDONLY);
//     char *line;
//     char *a[30];
//     int i = 0;

//     while ((line = get_next_line(fd)))
//     {
//         a[i] = line;
//         i++;
//     }
//     while (i > 0)
//     {
//         i--;
//         printf("%s", a[i]);
//         free(a[i]);
//     }
//     free(line);
//     close(fd);
// }
