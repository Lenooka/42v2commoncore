/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:13:27 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/04 14:46:02 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while(s[i])
	{
		i++;
	}
	return (i);
}

size_t ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	int				j;
	int				len;

	i = 0;
	j = 0;
	len = ft_strlen(src);
	if (size <= 0)
		return (len);
	while (i < size - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	dst[j] = '\0';
	return (len);
}