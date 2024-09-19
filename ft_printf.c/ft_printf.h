/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:59:30 by olena             #+#    #+#             */
/*   Updated: 2024/09/19 13:15:43 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdint.h>

int		ft_printf(const char *form, ...);
int		ft_printf_unsigned(unsigned int n);
int		ft_printf_hex(unsigned int n, int x);
int		ft_printf_nbr(int d);
int		ft_printf_unsigned(unsigned int n);
int		ft_printf_percent(void);
int		ft_printf_str(char *s);
int		ft_printf_char(int c);
int		ft_printf_pointer(unsigned long long ptr);


#endif