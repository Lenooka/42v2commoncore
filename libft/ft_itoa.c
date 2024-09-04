/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 20:34:46 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/05 00:06:29 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	int len_calc(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char *ft_itoa(int n)
{
	char *res;
	unsigned int len;

	if (n == -2147483648)
		return (res = ft_strdup("-2147483648"));
	len = len_calc(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if(!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
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
