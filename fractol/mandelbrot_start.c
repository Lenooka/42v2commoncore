/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_start.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:05:53 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/26 17:20:34 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"



	// 	char *c;
	//  int color;
	// color = 0x00FF0000;
	// frac->img = mlx_new_image(frac->mlx, w, h);
	// c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	// *(unsigned int *)c = color;

int	get_color(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == 100)
		return (0x000000);
	r = (int)(127.5 * (1 + cos(iter * 0.1))); // Smooth oscillation for red
	g = (int)(100.5 * (1 + sin(iter * 0.1))); // Smooth oscillation for green
	b = (int)(127.5 * (1 + cos(iter * 0.1 + 3.1415 / 2))); // Offset for blue
	return ((r << 16) | (g << 8) | b);
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

int	get_color_julia(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == 100)
		return (0x000000); // Black background for escape condition

	// Gradient from deep purple to a vibrant orange
	r = (int)(180 + 75 * cos(iter * 0.1));      // Stronger red component
	g = (int)(80 + 70 * sin(iter * 0.15));      // Increased green for warmer tones
	b = (int)(150 + 50 * cos(iter * 0.1 + 1));  // Reduced blue for a warmer orange hue

	return ((r << 16) | (g << 8) | b);
}
// 				count++;
// 			}
// 		color = get_color(count);
// 		*(unsigned int *)c = color;
// 		x++;
// 	} 
// 	// color = 0x00FF0000;
// 	// frac->img = mlx_new_image(frac->mlx, w, h);
// 	// c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
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

void update_adr(t_frac *data, int x, int y, int color) 
{
    char *dst;

    if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
        return;
    dst = data->addrs + (y * data->size_line + x * (data->bits_per_pixel / 8));
    *(unsigned int *)dst = color;
}

void	render_mandel(t_frac *fr, double cy, double cx)
{
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
			update_adr(fr, fr->x, fr->y, color);
			fr->x++;
		}
		fr->y++;
	}
	
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

void	check_argument(char **argv)
{
	int		len;

	len = ft_strlen(argv[1]);
	if (ft_strncmp("julia", argv[1], len) == 0 
		|| ft_strncmp("Julia", argv[1], len) == 0)
	{
		print_mess();
		exit(1);
	}
}

void	ren_ch(t_frac *frac)
{
	if (frac->frac_type == JULIA)
		render_julia(frac, frac->cxj, frac->cyj);
	else if (frac->frac_type == MANDEL)
		render_mandel(frac, frac->cy, frac->cx);
}

void	update_borders(t_frac *frac, double zoom, int x, int y)
{
	double	zoom_x; 
	double	zoom_y;
	double new;
	
	zoom_x = frac->left + x * frac->x_scale;
    zoom_y = frac->top - y * frac->y_scale;
	new = zoom_x + (frac->left - zoom_x) * zoom;
    frac->left = new;
    new = zoom_x + (frac->right - zoom_x) * zoom;
    frac->right = new;
     new = zoom_y + (frac->top - zoom_y) * zoom;
     frac->top = new;
     new = zoom_y + (frac->bot - zoom_y) * zoom;
     frac->bot = new;
	
}

int mouse_zoom(int button, int x, int y, t_frac *frac)
{
    double zoom_out;
    double zoom_in;

	zoom_out = 1.2;
	zoom_in = 0.8;
    if (button == 4)
		update_borders(frac, zoom_in, x, y);
	else if (button == 5)
		update_borders(frac, zoom_out, x, y);
	else
        return (0);
    frac->x_scale = (frac->right - frac->left) / WIDTH;
    frac->y_scale = (frac->top - frac->bot) / HEIGHT;
	mlx_destroy_image(frac->mlx, frac->img);
	frac->img = mlx_new_image(frac->mlx, WIDTH, HEIGHT);
	if (!frac->img)
		clear_funct(frac, 2);
	frac->addrs = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	if (!frac->addrs)
		clear_funct(frac, 3);
	ren_ch(frac);
    mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
    return (0);
}

// int	mouse_zoom_j(int button, int x, int y, t_frac *frac)
// {
//     double zoom_increment = 0.1;
//     double zoom_out_factor = 1.0 + zoom_increment;
//     double zoom_in_factor = 1.0 - zoom_increment;
//     double zoom_factor;
//     double new_left, new_right, new_top, new_bot;
//     double zoom_x, zoom_y;

//     // Calculate the fractal's center relative to the mouse position
//     zoom_x = frac->left + x * frac->x_scale;
//     zoom_y = frac->top - y * frac->y_scale;

//     // Adjust zoom factor based on scroll direction
//     if (button == 4) // Scroll up (zoom in)
//         zoom_factor = zoom_in_factor;
//     else if (button == 5) // Scroll down (zoom out)
//         zoom_factor = zoom_out_factor;
//     else
//         return (0);

//     // Recalculate the boundaries based on the zoom factor
//     new_left = zoom_x + (frac->left - zoom_x) * zoom_factor;
//     new_right = zoom_x + (frac->right - zoom_x) * zoom_factor;
//     new_top = zoom_y + (frac->top - zoom_y) * zoom_factor;
//     new_bot = zoom_y + (frac->bot - zoom_y) * zoom_factor;

//     // Update the boundaries of the fractal
//     frac->left = new_left;
//     frac->right = new_right;
//     frac->top = new_top;
//     frac->bot = new_bot;

//     // Recalculate scaling factors
//     frac->x_scale = (frac->right - frac->left) / WIDTH;
//     frac->y_scale = (frac->top - frac->bot) / HEIGHT;

//     render_julia(frac, -0.70176, -0.3842);
//     mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);

//     return (0);
// }


void	check_and_start_mandelbrot(char **argv, t_frac *frac)
{
	check_argument(argv);
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
	frac->addrs = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	if (!frac->addrs)
		clear_funct(frac, 3);
	frac->frac_type = MANDEL;
	calc_and_render_m(frac);
	mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	mlx_hook(frac->w, 17, 0, cross_exit, frac);
	mlx_hook(frac->w, 2, (1L << 0), esc_exit, frac);
	mlx_hook(frac->w, 4, 1L<<2, mouse_zoom, frac);  // 4 is the event for mouse scroll
	mlx_loop(frac->mlx);
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




