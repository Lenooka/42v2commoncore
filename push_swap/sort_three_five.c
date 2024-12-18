/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_five.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:28:54 by oltolmac          #+#    #+#             */
/*   Updated: 2024/12/18 07:29:33 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sort_three(t_stacks *stacks)
{
	int min;
	int max;

	findmindex(stacks);
 	findmaxndex(stacks);
 	min = stacks->min_indx;
 	max = stacks->max_indx;
	if (min == 1 && max == 2)
		sa(stacks, 0);
	else if (min == 2 && max == 0)
	{
		sa(stacks, 0);
		rra(stacks, 0);
	}
	else if (min == 1 && max == 0)
		ra(stacks, 0);
	else if (min == 0 && max == 1)
	{
		sa(stacks, 0);
		ra(stacks, 0);
	}
	else if (min == 2 && max == 1)
		rra(stacks, 0);
}

void	mid_len_sort(t_stacks *stacks, int middlen)
{
	while (stacks->lensa != 1 && is_not_sorted(stacks))
	{
		middlen = stacks->lensa / 2;
		findmindex(stacks);
		if (stacks->min_indx == 0)
			pb(stacks);
		else if (stacks->min_indx == 1)
		{
			if (stacks->stacka[0] > stacks->stacka[stacks->lensa - 1])
				ra(stacks, 0);
			else
				sa(stacks, 0);
		}
		else
		{
			if (stacks->stacka[0] > stacks->stacka[1])
				sa(stacks, 0);
			if (stacks->min_indx < middlen)
				ra(stacks, 0);
			else if (stacks->min_indx >= middlen)
				rra(stacks, 0);
		}
	}
	while (stacks->lensb > 0)
		pa(stacks);
}