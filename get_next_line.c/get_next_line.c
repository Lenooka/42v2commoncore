/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:40:39 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/20 18:52:09 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (src != NULL)
		len = ft_strlen(src);
	else
		len = 0;
	if (size <= 0)
		return (len);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	olen;
	size_t	tlen;
	char	*join;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	tlen = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (olen + tlen + 1));
	if (!join)
		return (NULL);
	ft_strlcpy(join, s1, olen + 1);
	ft_strlcpy(join + olen, s2, tlen + 1);
	return (join);
}

char	*ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	c = c % 256;
	if (s == NULL)
		return (NULL);
	while (s[i] && s != NULL)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	if (c == '\0')
		return ((char *)s + i);
	return (NULL);
}

char	*rr(char *line, int fd)
{
	int		bytes;
	char	*buffer;
	
	bytes = 1;
	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}
char *get_line(char *line)
{
	int i;
	char *s;

	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	s = malloc(sizeof(char) * i + 2);
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		s[i] = line[i];
		i++;
	}
	s[i] = '\n';
	s[i + 1] = '\0';
	return (s);
}
char *get_next_line(int fd)
{
	static char 	*line;
	char	*buffer;
	int		bytes;
	char	*s;
	int		i;
	
	i = 0;
	int j = 0;
	line = rr(line, fd);
	s = get_line(line);
	while (line[i] && line[i] != '\n')
		i++;
	i++;
	while (line[i] && line[i] != '\n')
	{
		line[j] = line[i];
		i++;
		j++;
	}
	if(line[i] == '\n')
		line[j] = '\n';
	line[j + 1] = '\0';
	return (s);
}
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("test/test4.txt", O_RDONLY);

	i = 1;
	line = get_next_line(fd1);
	if (line != NULL)
	{
		printf("line [%02d]: %s", i, line);
		i++;
		line = get_next_line(fd1);
		printf("line [%02d]: %s", i, line);
		line = get_next_line(fd1);
		i++;
		printf("line [%02d]: %s", i, line);
		line = get_next_line(fd1);
		i++;
		printf("line [%02d]: %s", i, line);
		line = get_next_line(fd1);
		i++;
		printf("line [%02d]: %s", i, line);
		line = get_next_line(fd1);
		i++;
		printf("line [%02d]: %s", i, line);
	}
	free(line);
	close(fd1);
	return (0);
}