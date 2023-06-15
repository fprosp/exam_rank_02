#include "get_next_line.h"

char *get_next_line(int fd)
{
	char *line,  c;
	int cl, i;
	
	line = malloc(sizeof(char *) * 999999999);
	if (!line)
		return (NULL);
	i = 0;
	while((cl = read(fd, &c, (BUFFER_SIZE * 0 + 1))) > 0)
	{
		line[i] = c;
		if (line[i] == '\n')
			break ;	
		i++;
	}
	if((!line[i] && !cl) || cl == -1)
	{
		free(line);
		return (NULL);
	}
	line[++i] = '\0'; 
	return (line);
}

