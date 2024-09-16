/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:42:13 by olena             #+#    #+#             */
/*   Updated: 2024/09/16 21:06:45 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_parse(const char *form, int i, va_list arg)
{
	int		c;

	c = 0;
	if (form[i + 1] == 'c')
		c += ft_printf_char(va_arg(arg, int));
	else if (form[i + 1] == 's')
		c += ft_printf_str(va_arg(arg, char *));
	else if (form[i + 1] == 'd' || form[i + 1] == 'i')
		c += ft_printf_nbr(va_arg(arg, int));
	else if (form[i + 1] == 'u')
		c += ft_printf_unsigned(va_arg(arg, unsigned int));
	else if (form[i + 1] == 'x')
		c += ft_printf_hex(va_arg(arg, unsigned int), 0);
	else if (form[i + 1] == 'X')
		c += ft_printf_hex(va_arg(arg, unsigned int), 1);
	else if (form[i + 1] == 'p')
		c += ft_printf_pointer(va_arg(arg, unsigned long long));
	else if (form[i + 1] == '%')
		c += ft_printf_percent();
	return (c);
}


int	ft_printf(const	char	*form, ...)
{
	int		i;
	int		c;
	va_list	args;

	i = 0;
	c = 0;
	va_start(args, form);
	while(form[i])
	{
		if (form[i] == '%')
		{
			c += ft_printf_parse(form, i, args);
			i++;
		}
		else
		{
			c += ft_printf_char(form[i]);
		}
		i++;
	}
	va_end(args);
	return (c);
}
