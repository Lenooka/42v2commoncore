/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:40:39 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/19 14:53:52 by oltolmac         ###   ########.fr       */
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

	if (s1 != NULL)
		olen = strlen(s1);
	else
		olen = 0;
	tlen = strlen(s2);
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

char *get_next_line(int fd)
{
	char 	*line;
	char	*buffer;
	int		bytes;

	line = NULL;
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
int	main(void)
{
	char	*line;
	int		i;
	int		fd1;
	fd1 = open("test/test.txt", O_RDONLY);

	i = 1;
	line = get_next_line(fd1);
	if (line != NULL)
	{
		printf("line [%02d]: %s", i, line);
	}
	free(line);
	close(fd1);
	return (0);
}