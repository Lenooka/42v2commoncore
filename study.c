

char	*get_next_line(int fd)
{
	static	char *line = NULL;
	char	*copy;
	char	*buf;
	int		bytes;	
	
	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)
	if (!buf)
	{
		free(line);
		return (NULL);
	}
	bytes = read(fd, buf, BUFFER_SIZE);
	if (bytes == -1)
	{		
		free(buf)
		return (NULL);
	}
	while(bytes > 0)
	{
		buf[bytes] = '\0';
		line = ft_strjoin(line, buf);
		if (ft_strchr(buffer, '\n'))
			break ;
		bytes = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	return (line);
}
