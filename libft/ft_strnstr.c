/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 14:28:57 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/04 19:03:49 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t 	i;
	size_t	x;

	i = 0;
	x = 0;
	if (little[i] == '\0')
		return (big);
	while (i < len && big[i])
	{
		if (big[i] == little[x])
		{
			while (i + x < len && big[i + x] == little[x])
			{
				x++;
				if (!little[x])
					return (big + i);
			}
		}
		i++;
	}
	return (NULL);
}