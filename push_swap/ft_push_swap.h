/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:39 by oltolmac          #+#    #+#             */
/*   Updated: 2024/12/15 14:39:12 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
#define FT_PUSH_SWAP_H

#define A 0
#define B 1
#define BOTH 2

#include "libftp/libft.h"
#include <limits.h>

typedef struct s_stacks
{
	long			*stacka;
	long			*stackb;
	long			*lenlis;
	long			*indxlis;
	long			*lis;
	int				lensa;
	int				lensb;
	int				min_indx;
	int				max_indx;
	int				min_indxb;
	int				max_indxb;
	

}	t_stacks;

#endif