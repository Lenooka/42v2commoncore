#include <stdlib.h>
#include <unistd.h>


#ifndef BUFFER_SIZE
#define BUFFER_SIZE 42
#endif


char *get_next_line(int fd)
{
	static char buf[BUFFER_SIZE];
	static int byt;
	static int indx = 0;
	int i = 0;
	char *line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!(line = malloc(10000)))
		return (NULL);
	while (1)
	{
		if (indx >= byt)
		{
			byt = read(fd, buf, BUFFER_SIZE);
			indx = 0;
			if (byt <= 0)
			{
				if (i == 0)
				{
					free(line);
					return (NULL);
				}
				break ;
			}
		}
		line[i++] = buf[indx++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return line;
}