/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:40:01 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/26 17:11:42 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FRACTOL_H
# define FT_FRACTOL_H

# include "libftper/libft.h"
# include <mlx.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
#include <math.h>
# include <unistd.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"
# define WIDTH 1000
# define HEIGHT 1000
# define JULIA 1
# define MANDEL 0




typedef struct s_frac
{
	int		frac_type;
	void	*mlx;
	void	*w;
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		tg;
	char	*addrs;
	double left;
	double right;
	double top;
	double bot;
	double x_scale;
	double y_scale;
	int		x;
	int		y;
	double cx;
	double cy;
	double cxj;
	double cyj;
	double zoom_factor;
} t_frac;

typedef struct s_complex {
    double re;
    double im;
} t_complex;

void	print_mess();
int	not_correct_name(char *s);
void	calc_and_render_m(t_frac *frac);
void	check_and_start_mandelbrot(char **argv, t_frac *frac);
int	window_start(t_frac *frac);
t_frac	*init_struct();
void	check_convert_float(char **a);
void	check_and_start_julia(char **argv, t_frac *frac);
#endif
