/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:40:47 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/22 17:03:01 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_nl_op(const char *s, int op)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	if (op == 1)
	{
		while (s[i])
		{
			i++;
		}
	}
	else
	{
		while (s[i] && s[i] != '\n')
		{
			i++;
		}
	}
	return (i);
}

size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	if (src != NULL)
		len = ft_strlen_nl_op(src, 1);
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

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	size_t	olen;
	size_t	tlen;
	char	*join;

	if (!s1)
	{
		s1 = (char *)malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	tlen = ft_strlen_nl_op(s2, 1);
	olen = ft_strlen_nl_op(s1, 1);
	join = (char *)malloc(sizeof(char) * (olen + tlen) + 1);
	if (!join)
		return (NULL);
	ft_gnl_strlcpy(join, s1, olen + 1);
	ft_gnl_strlcpy(join + olen, s2, tlen + 1);
	join[olen + tlen] = '\0';
	free(s1);
	return (join);
}

char	*ft_gnl_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
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

char	*ft_read_get_line(char *line, int fd)
{
	int		bytes;
	char	*buffer;

	bytes = 1;
	if (fd == -1)
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_gnl_strchr(line, '\n') && bytes != 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytes] = '\0';
		line = ft_gnl_strjoin(line, buffer);
	}
	free(buffer);
	return (line);
}
