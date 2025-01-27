/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:25:10 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/27 16:02:03 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	update_adr(t_frac *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addrs + (y * data->sl + x * (data->bp / 8));
	*(unsigned int *)dst = color;
}

int	get_color(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == 100)
		return (0x000000);
	r = (int)(127.5 * (1 + cos(iter * 0.1)));
	g = (int)(100.5 * (1 + sin(iter * 0.1)));
	b = (int)(127.5 * (1 + cos(iter * 0.1 + 3.1415 / 2)));
	return ((r << 16) | (g << 8) | b);
}

int	get_color_julia(int iter)
{
	int	r;
	int	g;
	int	b;

	if (iter == 100)
		return (0x000000);
	r = (int)(180 + 75 * cos(iter * 0.1));
	g = (int)(80 + 70 * sin(iter * 0.15));
	b = (int)(150 + 50 * cos(iter * 0.1 + 1));
	return ((r << 16) | (g << 8) | b);
}
