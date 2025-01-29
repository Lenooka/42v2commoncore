/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:40:01 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/29 18:46:08 by oltolmac         ###   ########.fr       */
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
# include <math.h>
# include <unistd.h>
# include <limits.h>
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
	int		bp;
	int		sl;
	int		ed;
	int		tg;
	char	*addrs;
	double	left;
	double	right;
	double	top;
	double	bot;
	double	x_scale;
	double	y_scale;
	int		x;
	int		y;
	double	cx;
	double	cy;
	double	cxj;
	double	cyj;
	double	zoom_factor;
}	t_frac;

void	print_mess(void);
int		not_correct_name(char *s);
void	calc_and_render_m(t_frac *frac);
void	check_and_start_mandelbrot(char **argv, t_frac *frac);
t_frac	*init_struct(void);
void	init_j_constants(char **argv, t_frac *frac);
void	check_argument(char **argv, t_frac *frac);
void	check_and_start_julia(char **argv, t_frac *frac);
int		get_color(int iter);
int		get_color_julia(int iter);
void	clear_funct(t_frac *frac, int step);
int		esc_exit(int key, t_frac *frac);
int		cross_exit(t_frac *frac);
int		calc_real_img(double cx, double cy);
void	update_adr(t_frac *data, int x, int y, int color);
void	render_mandel(t_frac *fr, double cy, double cx);
void	calc_and_render_m(t_frac *frac);
void	check_and_start_mandelbrot(char **argv, t_frac *frac);
int		calc_real_img_julia(double real, double img, double cx, double cy);
void	render_julia(t_frac *fr, double cx, double cy);
void	calc_and_render_julia(t_frac *frac, double cx, double cy);
void	check_and_start_julia(char **argv, t_frac *frac);
void	ren_ch(t_frac *frac);
void	update_borders(t_frac *frac, double zoom, int x, int y);
int		mouse_zoom(int button, int x, int y, t_frac *frac);
void	check_argument_j(char **argv, t_frac *frac);

#endif
