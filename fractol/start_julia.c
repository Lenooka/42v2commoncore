/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:09:59 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/26 17:20:38 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	init_j_constants(char **argv, t_frac *frac)
{
	(void)argv;
	frac->cxj = 0;
	frac->cyj = 0.8;	
}

void	check_and_start_julia(char **argv, t_frac *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
	{
		ft_printerr("Mlx_function fail!");
		free(frac);
		exit(1);	
	}
	init_j_constants(argv, frac);
	frac->w = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "fractol");
	if (!frac->w)
		clear_funct(frac, 1);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
		clear_funct(frac, 2);
	frac->addrs = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	if (!frac->addrs)
		clear_funct(frac, 3);
	frac->frac_type = JULIA;
	calc_and_render_julia(frac, frac->cxj, frac->cyj);
	mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	mlx_hook(frac->w, 2, (1L << 0), esc_exit, frac);
	mlx_hook(frac->w, 17, 0, cross_exit, frac);
	mlx_hook(frac->w, 4, 1L<<2, mouse_zoom, frac);
	mlx_loop(frac->mlx);
}