# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif

/*
char	*get_next_line(int fd)
{
	char	*ret = malloc(9999);
	char	c;
	int		i = 0;
	int		cpt = 0;

	if (fd < 0)
		return (NULL);
	while ((cpt = read(fd, &c, 1)) > 0)
	{
		ret[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	if (i == 0 || cpt < 0)
	{
		free(ret);
		return (NULL);
	}
	ret[i] = '\0';
	return (ret);
}*/


/*
char	*get_next_line(int fd)
{
	char	*ret = malloc(BUFFER_SIZE + 1);
	char	c;
	int		i = 0;
	int		cpt = 0;

	if (fd < 0)
		return (NULL);
	cpt = read(fd, ret, BUFFER_SIZE);
	if (cpt < 1)
	{
		free(ret);
		return (NULL);
	}
	ret[cpt] = '\0';
	return (ret);
}*/

/*char *get_next_line(int fd)
{
    char *buf;
    int len = 0;

    // Convert the first condition to a ternary operator
    return (fd < 0 || BUFFER_SIZE < 1) ? NULL : 
        (buf = malloc(BUFFER_SIZE + 1)) ? 
        ((len = read(fd, buf, BUFFER_SIZE)) < 1 ? (free(buf), NULL) : 
        (buf[len] = '\0', buf)) : NULL;
}*/

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE];
	static int	bytes_read = 0;
	static int	index = 0;
	char		*line;
	int			i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = malloc(10000); // Allocate a reasonable buffer size
	if (!line)
		return (NULL);
	while (1)
	{
		if (index >= bytes_read)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			index = 0;
			if (bytes_read <= 0)
			{
				free(line);
				return (bytes_read == 0 && i > 0) ? line : NULL;
			}
		}
		line[i++] = buffer[index++];
		if (line[i - 1] == '\n')
			break ;
	}
	line[i] = '\0';
	return (line);
}



int		main(int argc, char **argv)
{
	int 	fd = 0;
	char	*line;

	if (argc > 1)
		fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		printf("line |%s", line);
		free(line);
		line = get_next_line(fd);
	}
	return (0);
}
