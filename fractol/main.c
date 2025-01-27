/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:39:48 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/27 15:29:41 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

t_frac	*init_struct(void)
{
	t_frac	*frac;

	frac = (t_frac *)malloc(sizeof(t_frac));
	if (!frac)
	{
		ft_printerr("%sError!\nMalloc fail! in inut_struct!", KMAG);
		exit(1);
	}
	return (frac);
}

int	main(int argc, char **argv)
{
	t_frac	*frac;

	if (argc == 1)
		return (print_mess(), 1);
	frac = init_struct();
	if (argc <= 4 && argc > 1)
	{
		if (not_correct_name(argv[1]) || ft_strlen(argv[1]) == 0)
		{
			free(frac);
			return (print_mess(), 1);
		}
		if (argc == 4)
			check_and_start_julia(argv, frac);
		if (argc == 2 && argv[1])
			check_and_start_mandelbrot(argv, frac);
		else
		{
			free(frac);
			return (print_mess(), 1);
		}
	}
	clear_funct(frac, 3);
	return (0);
}
