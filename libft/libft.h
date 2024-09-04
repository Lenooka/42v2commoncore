/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:43:51 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/04 19:27:42 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <bsd/string.h>

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
void ft_bzero(void *s, size_t n);
size_t ft_strlcpy(char *dst, const char *src, size_t size);

#endif