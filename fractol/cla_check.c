/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cla_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 14:02:45 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/21 14:03:27 by oltolmac         ###   ########.fr       */
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