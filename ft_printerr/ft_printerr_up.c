/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr_up.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 16:27:07 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/19 15:53:32 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long	int	ft_u_len(unsigned int n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / base;
		len++;
	}
	return (len);
}

static char	*ft_convert_unsigned(unsigned int n)
{
	char	*num;
	int		len;

	len = ft_u_len(n, 10);
	num = (char *)malloc(sizeof(char) * (len + 1));
	if (!num)
		return (0);
	num[len] = '\0';
	while (n != 0)
	{
		num[len - 1] = n % 10 + 48;
		n = n / 10;
		len--;
	}
	return (num);
}

int	ft_printerr_unsigned(unsigned int n)
{
	int		len;
	char	*str;

	if (n == 0)
	{
		len = write(2, "0", 1);
		return (len);
	}
	len = ft_u_len(n, 10);
	str = ft_convert_unsigned(n);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}

static	unsigned int	ft_p_point(uintptr_t n)
{
	int	len;

	len = 0;
	if (n >= 16)
	{
		len += ft_p_point(n / 16);
		len += ft_p_point(n % 16);
	}
	else
	{
		if (n < 10)
		{
			len += ft_printf_char((n + '0'));
		}
		else
		{
			len += ft_printf_char((n - 10 + 'a'));
		}
	}
	return (len);
}

int	ft_printerr_pointer(unsigned long long p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (len = ft_printf_str("(nil)"));
	else
	{
		write(2, "0x", 2);
		len = ft_p_point(p) + 2;
	}
	return (len);
}
