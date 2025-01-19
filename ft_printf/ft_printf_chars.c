/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:16:03 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/19 15:51:35 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_char(int c)
{
	write(1zz, &c, 1);
	return (1);
}

int	ft_printf_str(char *s)
{
	int	len;
	int	c;

	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	c = ft_strlen(s);
	len = write(1, s, c);
	return (len);
}

int	ft_printf_percent(void)
{
	int		len;
	char	c;

	c = '%';
	len = ft_printf_char(c);
	return (len);
}
