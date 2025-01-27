/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_julia.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:09:59 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/27 16:52:32 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	calc_real_img_julia(double real, double img, double cx, double cy)
{
	double	temp_real;
	int		i;

	i = 0;
	while ((real * real + img * img < 4) && i < 100)
	{
		temp_real = real * real - img * img + cx;
		img = 2 * real * img + cy;
		real = temp_real;
		i++;
	}
	return (i);
}

void	render_julia(t_frac *fr, double cx, double cy)
{
	double	real;
	double	img;
	int		i;
	int		color;

	fr->y = 0;
	fr->x = 0;
	while (fr->y < HEIGHT)
	{
		fr->x = 0;
		while (fr->x < WIDTH)
		{
			real = fr->left + fr->x * fr->x_scale;
			img = fr->top - fr->y * fr->y_scale;
			i = calc_real_img_julia(real, img, cx, cy);
			color = get_color_julia(i);
			update_adr(fr, fr->x, fr->y, color);
			fr->x++;
		}
		fr->y++;
	}
}

void	calc_and_render_julia(t_frac *frac, double cx, double cy)
{
	frac->left = -2.0;
	frac->right = 2.0;
	frac->top = 2.0;
	frac->bot = -2.0;
	frac->x_scale = (frac->right - frac->left) / WIDTH;
	frac->y_scale = (frac->top - frac->bot) / HEIGHT;
	render_julia(frac, cx, cy);
}

void	check_and_start_julia(char **argv, t_frac *frac)
{
	check_argument_j(argv, frac);
	init_j_constants(argv, frac);
	frac->mlx = mlx_init();
	if (!frac->mlx)
	{
		ft_printerr("Mlx_function fail!");
		free(frac);
		exit(1);
	}
	frac->w = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "fractol");
	if (!frac->w)
		clear_funct(frac, 1);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
		clear_funct(frac, 2);
	frac->addrs = mlx_get_data_addr(frac->img, &frac->bp, &frac->sl, &frac->ed);
	if (!frac->addrs)
		clear_funct(frac, 3);
	frac->frac_type = JULIA;
	calc_and_render_julia(frac, frac->cxj, frac->cyj);
	mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	mlx_hook(frac->w, 2, (1L << 0), esc_exit, frac);
	mlx_hook(frac->w, 17, 0, cross_exit, frac);
	mlx_hook(frac->w, 4, (1L << 2), mouse_zoom, frac);
	mlx_loop(frac->mlx);
}
