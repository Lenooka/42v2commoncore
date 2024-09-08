/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:24:34 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/08 13:40:44 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	c;

	c = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size == 0)
		return (size + slen);
	if (dlen < size - 1 && size > 0)
	{
		while (src[c] != '\0' && dlen + c < size - 1)
		{
			dst[dlen + c] = src[c];
			c++;
		}
		dst[dlen + c] = '\0';
	}
	if (dlen < size)
	{
		return (dlen + slen);
	}
	return (size + slen);
}*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size == 0)
		return (size + srclen);
	if (size > 0 && destlen < size - 1)
	{
		while (src[i] != '\0' && ((i + destlen) < size - 1))
		{
			dst[destlen + i] = src[i];
			i++;
		}
		dst[destlen + i] = '\0';
	}
	if (destlen < size)
		return (destlen + srclen);
	return (srclen + size);
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