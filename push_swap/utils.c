/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:24:16 by oltolmac          #+#    #+#             */
/*   Updated: 2024/12/27 14:39:24 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	is_not_sorted(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stacks->lensa)
	{
		while (j < stacks->lensa)
		{
			if (stacks->stacka[i] > stacks->stacka[j] && i < j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	findmindexb(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->min_indxb = 0;
	while (i < stacks->lensb)
	{
		if (stacks->stackb[stacks->min_indxb] > stacks->stackb[i])
			stacks->min_indxb = i;
		i++;
	}
}

void	findmindex(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->min_indx = 0;
	while (i < stacks->lensa)
	{
		if (stacks->stacka[stacks->min_indx] > stacks->stacka[i])
			stacks->min_indx = i;
		i++;
	}
}
int	stack_len(long *stack)
{
	int	i;

	i = 0;
	while (stack[i])
		i++;
	return (i);
}

