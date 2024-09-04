/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:24:34 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/04 14:27:24 by oltolmac         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < destlen)
		return (size + srclen);
	if (size > 0)
	{
		while (src[i] != '\0' && ((i + destlen) < size - 1))
		{
			dst[destlen + i] = src[i];
			i++;
		}
		dst[destlen + i] = '\0';
		while (src[i] != '\0')
		{
			dst[destlen + i] = '\0';
			i++;
		}
	}
	return (srclen + destlen);
}

/*int	main(int argc, char **argv)
{

	if (argc)
	{
		//ft_strlcat(argv[1], argv[2], sizeof(argv[1]));
		printf("%s\n", argv[1]);
	}
	strlcat(argv[1], argv[2], sizeof(argv[1]));
	printf("%s\n", argv[1]);
}*/