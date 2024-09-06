/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:24:34 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/05 14:18:24 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < destlen + 1)
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