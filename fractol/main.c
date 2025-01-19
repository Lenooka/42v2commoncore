/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:39:48 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/19 21:10:56 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	print_mess()
{
	ft_printf("%s=================================", KRED);
	ft_printf("\n%s|      INVALID PARAMETERS!      |\n", KRED);
	ft_printf("%s|-------------------------------|\n", KRED);
	ft_printf("%s|     Available parameters      |\n", KYEL);
	ft_printf("%s|-------------------------------|\n", KYEL);
	ft_printf("%s| 1. Julia usage:               |\n", KGRN);
	ft_printf("|   ./fracrol Julia 0.26 -0.07  |\n");
	ft_printf("|   ./fractol julia 0 0.8       |\n");
	ft_printf("%s|-------------------------------|\n", KGRN);
	ft_printf("%s| 2. Mandelbrot usage :         |\n", KBLU);
	ft_printf("|   ./fracrol Mandelbrot        |\n");
	ft_printf("|   ./fracrol mandelbrot        |\n");
	ft_printf("%s=================================\n", KBLU);
	ft_printf("%s", KNRM);
}

int	not_correct_name(char *s)
{
	int len;

	len = ft_strlen(s);
	if (ft_strncmp("julia", s, len) == 0 
		|| ft_strncmp("Julia", s, len) == 0
		|| ft_strncmp("mandelbrot", s, len) == 0 
		|| ft_strncmp("Mandelbrot", s, len) == 0)
	{
		return (0);
	}
	return (1);
}


int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}


int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}
int	window_start(t_frac *frac)
{
	frac->mlx = mlx_init();
	if (!frac->mlx)
		return (0);	
	frac->w = mlx_new_window(frac->mlx, 1920, 939, "fractol");
	if (!frac->w)
	{
		mlx_destroy_display(frac->mlx);
		return (0);	
	}
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
		ft_printerr("%sError!\nMlx function fail!\n", KMAG);
		exit(1);
	}
	return (frac);
}

void	calc_and_render_m(t_frac *frac)
{
	int	w;
	int h;
	char *c;
	int color;
	
	w = 60;
	h = 60;
	color = 0x00FF0000;
	frac->img = mlx_new_image(frac->mlx, w, h);
	c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
	*(unsigned int *)c = color;
	int s = 0;
	int i = 0;
	int x = 0;
	while (x < 1920)
	{
		i = 0;
		s = 0;
		while (i < 1000)
		{
			if (i < 400)
			{
				color = 0x00101891;
				c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
				*(unsigned int *)c = color;
			}
			else
			{
				color = 0x00ffbf50;
				c = mlx_get_data_addr(frac->img, &frac->bits_per_pixel, &frac->size_line, &frac->endian);
				*(unsigned int *)c = color;
			}
			mlx_put_image_to_window(frac->mlx, frac->w, frac->img, s, x);
			i++;
			s++;
		}
		x++;
	}
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
	calc_and_render_m(frac);
	mlx_loop(frac->mlx);
}
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
int main(int argc, char **argv)
{
	if (argc == 1)
		return(print_mess(), 1);
	if (argc <= 4 && argc > 1)
	{
		if (not_correct_name(argv[1]) || ft_strlen(argv[1]) == 0)
			return(print_mess(), 1);
		if (argc == 4)
			check_and_start_julia(argv);
		if (argc == 2 && argv[1])  // maybe I can make it colorfull or black and white???
			check_and_start_mandelbrot(argv);
	}
	return (0);
	
}
