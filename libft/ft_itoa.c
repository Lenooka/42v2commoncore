/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:34:46 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/04 20:53:32 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len_calc(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n != 10)
	{
		n = n / 10;
		len++;
	}
	len++;
	return (len);
}

char *ft_itoa(int n)
{
	char *res;
	int len;

	res = (char *)malloc(sizeof(char) * len_calc(n));
	if (n == -2147483648)
		return (res = ft_strdup("-2147483648"));
	if(!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	len = len_calc(n);
	res[len] = '\0';
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[len - 1] = (n % 10) + '0';
		n = (n / 10);
		len--;
	}
	return (res);
}
