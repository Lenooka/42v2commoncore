/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_chars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:16:03 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/16 15:19:39 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_print_str(char *s)
{
	int	len;

	len = write(1, &s, ft_strlen(s));
	return (len);
}