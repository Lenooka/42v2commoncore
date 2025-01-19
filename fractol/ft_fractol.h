/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 06:40:01 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/19 16:24:52 by oltolmac         ###   ########.fr       */
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
# include <unistd.h>

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct s_frac
{
	void	*mlx;
	void	*w;
	void	*img;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		tg;
} t_frac;


#endif
