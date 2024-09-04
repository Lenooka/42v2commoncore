/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 11:45:32 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/02 11:49:51 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char *mem;
	size_t i;

	i = 0;
	mem = (unsigned char *)s;
	while (n--)
	{
		mem[i] = '\0';
		i++;	
	}
}