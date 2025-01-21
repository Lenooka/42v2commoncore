/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:09:59 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/21 14:10:18 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	check_convert_float(char **a)
{
	(void)a;
	printf("%sHadling float is in progress%s\n", KMAG, KNRM);
}

void	check_and_start_julia(char **argv)
{
	t_frac	*frac;
	
	check_convert_float(argv);
	frac = init_struct();
	//calc_and_render_j(frac);
	mlx_loop(frac->mlx);
}