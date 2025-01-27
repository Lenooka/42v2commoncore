/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:32:25 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/27 16:01:04 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

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
	double	new;

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

int	mouse_zoom(int button, int x, int y, t_frac *frac)
{
	double	zoom_out;
	double	zoom_in;

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
	frac->addrs = mlx_get_data_addr(frac->img, &frac->bp, &frac->sl, &frac->ed);
	if (!frac->addrs)
		clear_funct(frac, 3);
	ren_ch(frac);
	mlx_put_image_to_window(frac->mlx, frac->w, frac->img, 0, 0);
	return (0);
}
