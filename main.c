#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

int main()
{
    int fd = open("deneme", O_RDONLY);
    if (fd == -1)
    {
        printf("hata");
        return (1);
    }
    char *line;

    (line = get_next_line(fd));
        printf("%s ", line);
        free(line);
    close(fd);
}