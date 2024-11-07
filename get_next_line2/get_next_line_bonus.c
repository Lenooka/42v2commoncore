/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:40:39 by oltolmac          #+#    #+#             */
/*   Updated: 2024/10/17 17:53:47 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_copy_line(char *line)
{
	int		i;
	char	*s;

	i = 0;
	if (!line[i])
		return (NULL);
	i = ft_strlen_nl_op(line, 0);
	s = malloc(sizeof(char) * i + 2);
	if (!s)
		return (NULL);
	ft_gnl_strlcpy(s, line, i + 2);
	if (line[i] == '\n')
		s[i] = line[i];
	s[i + 1] = '\0';
	return (s);
}

char	*ft_rewrite_st_line(char *line)
{
	int	i;
	int	j;

	j = 0;
	i = ft_strlen_nl_op(line, 0);
	if (!line[i])
	{
		free(line);
		return (NULL);
	}
	while (line[i + 1])
	{
		line[j] = line[i + 1];
		i++;
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*get_next_line(int fd)
{
	char		*s;
	static char	*fd_buf[1024];

	if (fd == -1 || BUFFER_SIZE < 1)
		return (NULL);
	fd_buf[fd] = ft_read_get_line(fd_buf[fd], fd);
	if (!fd_buf[fd] || fd_buf[fd][0] == '\0' || fd_buf[fd] == NULL)
	{
		free(fd_buf[fd]);
		return (NULL);
	}
	s = ft_copy_line(fd_buf[fd]);
	fd_buf[fd] = ft_rewrite_st_line(fd_buf[fd]);
	return (s);
}

// int	main(void)
// {
// 	char	*line;
// 	int		i;
// 	int		fd1;
// 	fd1 = open("test/test4.txt", O_RDONLY);
// 	int	fd2 = open("test/test5.txt", O_RDONLY);
// 	int	fd3 = open("test/test.txt", O_RDONLY);
// 	i = 1;
// 	line = get_next_line(fd1);
// 	if (line != NULL)
// 	{
// 		printf("line [%02d]: %s", i, line);
// 		i++;
// 		free(line);
// 		line = get_next_line(fd1);
// 			printf("line [%02d]: %s", i, line);
// 		free(line);	
// 		line = get_next_line(fd1);
// 		i++;
// 			printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd3);
// 		i++;
// 			printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd2);
// 		i++;
// 			printf("line [%02d]: %s", i, line);
// 		free(line);
// 		line = get_next_line(fd1);
// 		i++;
// 			printf("line [%02d]: %s", i, line);
// 		free(line);	
// 	}
// 	close(fd1);
// 	return (0);
// }