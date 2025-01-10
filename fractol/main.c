/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:39:48 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/10 17:55:14 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == '\0' && s2[j] == '\0' && s1[i] == s2[j])
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
}

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

void	check_and_start_julia(char **argv)
{
	printf("%s\n%s\n%s\n", argv[1], argv[2], argv[3]);
}
void	check_and_start_mandelbrot(char **argv)
{
	int		len;
	void	*mlx;
	void	*w;
	void	*img;

	len = ft_strlen(argv[1]);
	if (ft_strncmp("julia", argv[1], len) == 0 
		|| ft_strncmp("Julia", argv[1], len) == 0)
	{
		print_mess();
		exit(1);
	}
	printf("Mandel %s\n", argv[1]);
	mlx = mlx_init();	
	w = mlx_new_window(mlx, 1920, 939, "fractol");
	img = mlx_new_image(mlx, 1920, 939);
	mlx_loop(mlx);
}

int main(int argc, char **argv)
{
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
