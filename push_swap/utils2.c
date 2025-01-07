/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:24:16 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/07 21:21:33 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	findmaxndex_arg(long *stack, int len)
{
	int	i;
	int	max;

	i = 0;
	max = stack[0];
	while (i <= len)
	{
		if (max < stack[i])
			max = stack[i];
		i++;
	}
	return (max);
}

void	findmaxndex(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->max_indx = 0;
	while (i < stacks->lensa)
	{
		if (stacks->stacka[stacks->max_indx] < stacks->stacka[i])
			stacks->max_indx = i;
		i++;
	}
}
