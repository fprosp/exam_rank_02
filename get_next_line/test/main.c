#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
        int fd;
        char *str;

        fd = open("file.txt", O_RDONLY);
        str = NULL;
        while ((str = get_next_line(fd)) != NULL)
        {
                printf("%s",str);
                free(str);
        }
        close(fd);
        return (0);
}
