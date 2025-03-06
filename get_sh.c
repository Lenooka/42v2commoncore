# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
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

char    *get_next_line(int fd)
{
    char    *buf;
    int     len = 0;

    if (fd < 0 || BUFFER_SIZE < 1)
        return (NULL);
    buf = malloc(BUFFER_SIZE + 1);
    if (!buf)
        return (NULL);
    len = read(fd, buf, BUFFER_SIZE);
    if (len < 1)
        return (free(buf),  NULL);
    buf[len] = '\0';
    return (buf);
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
