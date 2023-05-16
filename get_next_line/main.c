#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
        int fd;
        char *line;

        fd = open("file.txt", O_RDONLY);
        line = NULL;
	while ((line = get_next_line(fd)) != NULL)
        {
                printf("%s", line);
                free(line);
        }
        close(fd);
        return (0);
}

