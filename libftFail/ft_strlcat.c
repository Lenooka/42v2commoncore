/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:24:34 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/10 21:32:41 by oltolmac         ###   ########.fr       */
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
	if (size == 0 )
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

/*int main()
{
	printf("%zu\n",strlcat(NULL, "hello", 0));
	printf("%zu",ft_strlcat(NULL,"hello", 0));
}*/