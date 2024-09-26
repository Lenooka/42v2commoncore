/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 13:40:57 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/25 17:47:18 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_bonus
{
	int		fd;
	char	*buffer;
	struct 	s_bonus	*next;
} t_bonus;

char	*get_next_line(int fd);
char	*ft_read_get_line(char *line, int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
char	*ft_gnl_strchr(char *s, int c);
size_t	ft_strlen_nl_op(const char *s, int op);
size_t	ft_gnl_strlcpy(char *dst, const char *src, size_t size);
char	*ft_rewrite_st_line(char *line);
char	*ft_copy_line(char *line);

#endif