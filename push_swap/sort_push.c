/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:32:12 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/04 20:41:49 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	findminndex_ret(t_stacks *stacks)
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
	return (stacks->min_indx);
}

int	insert_pos(t_stacks *stacks, int el)
{
	int	i;

	i = 0;
	while (i < stacks->lensa)
	{
		if (el > stacks->stacka[i]
			&& el < stacks->stacka[(i + 1) % stacks->lensa])
			return (i + 1);
		i++;
	}
	i = findminndex_ret(stacks);
	return (i);
}

int	calc_cost(int ib, int ta, t_stacks *stacks)
{
	int	cost_b;
	int	cost_a;

	if (ib <= stacks->lensb / 2)
	{
		cost_b = ib;
	}
	else
	{
		cost_b = stacks->lensb - ib;
	}
	if (ta <= stacks->lensa / 2)
	{
		cost_a = ta;
	}
	else
	{
		cost_a = stacks->lensa - ta;
	}
	return (cost_b + cost_a);
}

int	bestmove(t_stacks *stacks, int best)
{
	int	i;
	int	best_cost;
	int	cost;
	int	el;
	int	ta;	

	best = 0;
	i = 0;
	best_cost = MAX;
	while (i < stacks->lensb)
	{
		el = stacks->stackb[i];
		ta = insert_pos(stacks, el);
		cost = calc_cost(i, ta, stacks);
		if (cost < best_cost)
		{
			best_cost = cost;
			best = i;
		}
		i++;
	}
	return (best);
}

void	push_back_to_a(t_stacks *stacks)
{
	int	best_move;
	int	el;
	int	ta;

	while (stacks->lensb > 0)
	{
		best_move = bestmove(stacks, best_move);
		el = stacks->stackb[best_move];
		ta = insert_pos(stacks, el);
		rotat_b(stacks, best_move);
		rotat_a(stacks, ta);
		pa(stacks);
	}
	min_to_the_top(stacks);
}
