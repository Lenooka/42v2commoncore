/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:25:53 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/30 14:25:09 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	after_dot(int i, char *nptr)
{
	double	d;
	double	aft;

	d = 1;
	aft = 0.0;
	while ((nptr[i] && nptr[i] >= '0' && nptr[i] <= '9'))
	{
		d /= 10;
		aft = aft + (nptr[i] - '0') * d;
		i++;
	}
	return (aft);
}

double	ft_atoif(char *nptr)
{
	int		sign;
	int		res;
	long	i;
	double	aft;

	i = 0;
	sign = 1;
	res = 0;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	if (nptr[i] == '.')
		i++;
	aft = after_dot(i, nptr);
	return ((res + aft) * sign);
}

void	valid_and_len(t_frac *frac, char *s)
{
	int	i;
	int	l;

	i = 0;
	l = ft_strlen(s);
	if (l > 8 || (l > 7 && s[0] != '-') || (l == 1 && (!ft_isdigit(s[0]))))
	{
		free(frac);
		print_mess();
		exit(1);
	}
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (s[i] == '.')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	if (i != l)
	{
		free(frac);
		print_mess();
		exit(1);
	}
}

void	init_j_constants(char **argv, t_frac *frac)
{
	valid_and_len(frac, argv[2]);
	valid_and_len(frac, argv[3]);
	frac->cxj = ft_atoif(argv[2]);
	if ((argv[2][0] != '0') && ((argv[2][1] != '\0'))
		&& frac->cxj == 0)
	{
		if (frac->cxj == 0)
		{
			free(frac);
			print_mess();
			exit(1);
		}
	}
	frac->cyj = ft_atoif(argv[3]);
	if ((argv[3][0] != '0') && ((argv[3][1] != '\0'))
		&& frac->cyj == 0)
	{
		if (frac->cyj == 0)
		{
			free(frac);
			print_mess();
			exit(1);
		}
	}
}
