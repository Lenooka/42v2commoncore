/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerr.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 12:59:30 by olena             #+#    #+#             */
/*   Updated: 2024/09/19 13:31:49 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTERR_H
# define FT_PRINTERR_H
# include <stdarg.h>
# include <unistd.h>
# include "libft/libft.h"
# include <stdint.h>

int		ft_printerr(const char *form, ...);
int		ft_printerr_unsigned(unsigned int n);
int		ft_printerr_hex(unsigned int n, int x);
int		ft_printerr_nbr(int d);
int		ft_printerr_unsigned(unsigned int n);
int		ft_printerr_percent(void);
int		ft_printerr_str(char *s);
int		ft_printerr_char(int c);
int		ft_printerr_pointer(unsigned long long ptr);

#endif