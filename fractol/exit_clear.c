/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:31:11 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/27 15:53:42 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	clear_funct(t_frac *frac, int step)
{
	ft_printerr("Mlx_function fail!");
	if (step == 1)
	{
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		free(frac);
		exit(1);
	}
	if (step == 2)
	{
		mlx_destroy_window(frac->mlx, frac->w);
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		free(frac);
		exit(1);
	}
	if (step == 3)
	{
		mlx_destroy_image(frac->mlx, frac->img);
		mlx_destroy_window(frac->mlx, frac->w);
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		free(frac);
		exit(1);
	}
}

int	esc_exit(int key, t_frac *frac)
{
	(void)frac;
	if (key == XK_Escape)
	{
		mlx_destroy_image(frac->mlx, frac->img);
		mlx_destroy_window(frac->mlx, frac->w);
		mlx_destroy_display(frac->mlx);
		free(frac->mlx);
		free(frac);
		exit(1);
	}
	else if (key == XK_r && frac->frac_type == JULIA)
	{
		calc_and_render_julia(frac, frac->cxj, frac->cyj);
		mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	}
	else if (key == XK_r && frac->frac_type == MANDEL)
	{
		calc_and_render_m(frac);
		mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	}
	return (0);
}

int	cross_exit(t_frac *frac)
{
	mlx_destroy_image(frac->mlx, frac->img);
	mlx_destroy_window(frac->mlx, frac->w);
	mlx_destroy_display(frac->mlx);
	free(frac->mlx);
	free(frac);
	exit(1);
	return (0);
}
