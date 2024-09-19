/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_nmbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:20:33 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/16 20:42:19 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	int	ft_len(int n, int base)
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
		n = n / base;
		len++;
	}
	return (len);
}

int	ft_printf_nbr(int d)
{
	int	len;

	len = ft_len(d, 10);
	ft_putnbr_fd(d, 1);
	return (len);
}

static void	ft_hex(unsigned int n, int x)
{
	if (n >= 16)
	{
		ft_hex(n / 16, x);
		ft_hex(n % 16, x);
	}
	else
	{ 
		if (n < 10)
		{
			ft_putchar_fd((n + '0'), 1);
		}
		else
		{
			if (x == 0)
				ft_putchar_fd((n - 10 + 'a'), 1);
			if (x == 1)
				ft_putchar_fd((n - 10 + 'A'), 1);
		}
	}
}

int	ft_printf_hex(unsigned int n, int x)
{
	int	len;
	
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	len = ft_len(n, 16);
	if (n == 0)
	{
		ft_putchar_fd(48, 1);
		return (len);
	}
	ft_hex(n, x);
	return (len);
}