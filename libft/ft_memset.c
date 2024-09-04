/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:54:04 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/02 11:58:06 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *set;
	int	i;

	i = 0;
	set = (unsigned char *)str;
	while (i < n)
	{
		set[i] = (unsigned char)c;
		i++;
	}
	return (set);
}