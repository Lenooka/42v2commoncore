/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swapold.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:39 by oltolmac          #+#    #+#             */
/*   Updated: 2024/11/19 13:25:01 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAPO_H
#define FT_PUSH_SWAPO_H

#define A 0
#define B 1
#define BOTH 2

#include "libftp/libft.h"

typedef struct s_stack
{
	int			content;
	struct s_stack	*next;
}	t_stack;

#endif