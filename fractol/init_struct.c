/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:08:12 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/21 19:40:14 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	window_start(t_frac *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		return (0);	
	return (1);
}

t_frac	*init_struct()
{
	t_frac *frac;

	frac = (t_frac *)malloc(sizeof(t_frac));
	if (!frac)
	{	
		ft_printerr("%sError!\nMalloc fail! in inut_struct!", KMAG);
		exit(1);
	}
	if (!window_start(frac))
	{
		free(frac);
		ft_printerr("%sError!\nMlx function fail!\n", KMAG);
		exit(1);
	}
	return (frac);
}