/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:24:16 by oltolmac          #+#    #+#             */
/*   Updated: 2024/12/18 07:26:13 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	findmaxndex_arg(long *stack)
{
	int	i;
	int len;
	int max_indx;

	i = 0;
	max_indx = 0;
	len = stack_len(stack);
	while (i < len)
	{
		if (stack[max_indx] < stack[i])
			max_indx = stack[i];
		i++;
	}
	return (max_indx);
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
