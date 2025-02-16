/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:05:53 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/13 20:07:11 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	calc_real_img(double cx, double cy)
{
	double	real;
	double	img;
	double	temp_real;
	int		i;

	real = 0;
	img = 0;
	i = 0;
	while ((real * real + img * img < 4) && i < 200)
	{
		temp_real = real * real - img * img + cx;
		img = 2 * real * img + cy;
		real = temp_real;
		i++;
	}
	return (i);
}

/*
	cy imaginary number
  	cx real number
  */

void	render_mandel(t_frac *fr, double cy, double cx)
{
	int		i;
	int		color;

	fr->y = 0;
	fr->x = 0;
	while (fr->y < HEIGHT)
	{
		fr->x = 0;
		while (fr->x < WIDTH)
		{
			cx = fr->left + fr->x * fr->x_scale;
			cy = fr->top - fr->y * fr->y_scale;
			i = calc_real_img(cx, cy);
			color = get_color(i);
			update_adr(fr, fr->x, fr->y, color);
			fr->x++;
		}
		fr->y++;
	}
}

void	calc_and_render_m(t_frac *frac)
{
	frac->left = -2.0;
	frac->right = 1.0;
	frac->top = 1.5;
	frac->bot = -1.5;
	frac->x_scale = (frac->right - frac->left) / WIDTH;
	frac->y_scale = (frac->top - frac->bot) / HEIGHT;
	frac->cx = frac->left + frac->x * frac->x_scale;
	frac->cy = frac->top - frac->y * frac->y_scale;
	render_mandel(frac, frac->cy, frac->cx);
}

void	check_and_start_mandelbrot(char **argv, t_frac *frac)
{
	check_argument(argv, frac);
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
	frac->frac_type = MANDEL;
	calc_and_render_m(frac);
	mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	mlx_hook(frac->w, 17, 0, cross_exit, frac);
	mlx_hook(frac->w, 2, (1L << 0), esc_exit, frac);
	mlx_hook(frac->w, 4, (1L << 2), mouse_zoom, frac);
	mlx_loop(frac->mlx);
}
