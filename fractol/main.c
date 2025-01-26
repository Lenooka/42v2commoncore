/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:39:48 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/26 17:14:28 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int main(int argc, char **argv)
{
	t_frac *frac;

	if (argc == 1)
		return(print_mess(), 1);
	frac = init_struct();
	if (argc <= 4 && argc > 1)
	{
		if (not_correct_name(argv[1]) || ft_strlen(argv[1]) == 0)
			return(print_mess(), 1);
		if (argc == 4)
			check_and_start_julia(argv, frac);
		if (argc == 2 && argv[1])  // maybe I can make it colorfull or black and white???
			check_and_start_mandelbrot(argv, frac);
	}
	return (0);
	
}
