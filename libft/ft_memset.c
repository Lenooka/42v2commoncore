/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:54:04 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/05 23:51:13 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	unsigned char *set;
	size_t	i;

	i = 0;
	set = (unsigned char *)str;
	while (i < n)
	{
		set[i] = (unsigned char)c;
		i++;
	}
	return (set);
}