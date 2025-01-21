/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:05:53 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/21 19:48:13 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

	// 	char *c;
	//  int color;
	// color = 0x00FF0000;
	// frac->img = mlx_new_image(frac->mlx, w, h);
	// c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	// *(unsigned int *)c = color;

int get_color(int iter) 
{
    if (iter == 100)
        return 0x000000;
    int r = (iter * 9) % 256;
    int g = (iter * 7) % 256;
    int b = (iter * 3) % 256;
    return (r << 16) | (g << 8) | b;
}

// void	calc_and_render_m(t_frac *frac)
// {
// 	int	w;
// 	int h;
// 	char *c;
// 	int color;
// 	float left, top, xside, yside;
// 	float xscale, yscale, zx, zy, cx, tempx, cy;
// 	int x, y;
// 	int count;
  
//     left = -1.75; 
//     top = -0.25; 
//     xside = 0.25; 
//     yside = 0.45; 
// 	w = 1;
// 	h = 1;

// 	xscale = xside / 100; 
//     yscale = yside / 100;
// 	y = 1;
// 	count = 0;
// 	color = 0x00FF0000;
// 	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
// 	c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
// 	while (y <= 100)
// 	{
// 		x = 1;
// 		while (x <= 100)
// 		{
// 			cx = x * xscale + left;
// 			cy = y * yscale + top;
// 			zx = 0;
// 			zy = 0;
// 			while  ((zx * zx + zy * zy < 4)) 
//             {
//                 // Calculate Mandelbrot function 
//                 // z = z*z + c where z is a complex number 
  
//                 // tempx = z_real*_real - z_imaginary*z_imaginary + c_real 
//                 tempx = zx * zx - zy * zy + cx; 
  
//                 // 2*z_real*z_imaginary + c_imaginary 
//                 zy = 2 * zx * zy + cy; 
  
//                 // Updating z_real = tempx 
//                 zx = tempx;
// 				count++;
// 			}
// 		color = get_color(count);
// 		*(unsigned int *)c = color;
// 		x++;
// 	} 
// 	// color = 0x00FF0000;
// 	// frac->img = mlx_new_image(frac->mlx, w, h);
// 	// c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
// 	// *(unsigned int *)c = color;
// 	// mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 1919, 938);
// 	y++;
// 	}
// 	mlx_put_image_to_window(frac->mlx, frac->w, frac->img, x, y);
// }

int	calc_real_img(double cx, double cy)
{
	double	real;
	double	img;
	double	temp_real;
	int		i;

	real = 0;
	img = 0;
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

/*
	cy imaginary number
  	cx real number
  */

void my_mlx_pixel_put(t_frac *data, int x, int y, int color) 
{
    char *dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = data->addrs + (y * data->size_line + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	render_mandel(t_frac *fr)
{
	double	cy;
	double	cx;
	int		i;
	int		color;
	
	fr->y = 0;
	fr->x = 0;
	while (fr->y < HEIGHT)
	{
		fr->x = 0;
		while(fr->x < WIDTH)
		{
			cx = fr->left + fr->x * fr->x_scale;
			cy = fr->top - fr->y * fr->y_scale;
			i = calc_real_img(cx, cy);
			color = get_color(i); 
			my_mlx_pixel_put(fr, fr->x, fr->y, color);
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
	render_mandel(frac);
}

void	check_and_start_mandelbrot(char **argv)
{
	int		len;
	t_frac	*frac;

	len = ft_strlen(argv[1]);
	if (ft_strncmp("julia", argv[1], len) == 0 
		|| ft_strncmp("Julia", argv[1], len) == 0)
	{
		print_mess();
		exit(1);
	}
	frac = init_struct();
	frac->w = mlx_new_window(frac->mlx, WIDTH, HEIGHT, "fractol");
	if (!frac->w)
	{
		mlx_destroy_display(frac->mlx);
		exit(1);
	}
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	frac->addrs = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	calc_and_render_m(frac);
	mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	mlx_loop(frac->mlx);
}
