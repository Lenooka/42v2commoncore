/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:42:13 by olena             #+#    #+#             */
/*   Updated: 2024/09/16 23:34:18 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


static	int	ft_formats(va_list args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printf_char(va_arg(args, int));
	else if (format == 's')
		print_length += ft_printf_str(va_arg(args, char *));
	else if (format == 'p')
		print_length += ft_printf_pointer(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		print_length += ft_printf_nbr(va_arg(args, int));
	else if (format == 'u')
		print_length += ft_printf_unsigned(va_arg(args, unsigned int));
	else if (format == 'x')
		print_length += ft_printf_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		print_length += ft_printf_hex(va_arg(args, unsigned int), 1);
	else if (format == '%')
		print_length += ft_printf_percent();
	return (print_length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}
