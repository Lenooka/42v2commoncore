/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_choice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:34:26 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/08 13:59:58 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	min_to_the_top(t_stacks *stacks)
{
	int	min;

	findmindex(stacks);
	min = stacks->stacka[stacks->min_indx];
	if (stacks->min_indx == 0)
		return ;
	if (stacks->lensa - stacks->min_indx < stacks->min_indx)
	{
		while (stacks->stacka[0] != min)
			rra(stacks, 0);
	}
	else
	{
		while (stacks->stacka[0] != min)
			ra(stacks, 0);
	}
}

void	lisr(long *s, int len)
{
	int	temp;
	int	i;

	i = 0;
	temp = s[0];
	while (i < len - 1)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[len - 1] = temp;
}

void	rotat_a(t_stacks *stacks, int ta)
{
	if (ta <= stacks->lensa / 2)
	{
		while (ta > 0)
		{
			ra(stacks, 0);
			ta--;
		}
	}
	else
	{
		while (ta < stacks->lensa)
		{
			rra(stacks, 0);
			ta++;
		}
	}
}

void	rotat_b(t_stacks *stacks, int best)
{
	if (best <= stacks->lensb / 2)
	{
		while (best > 0)
		{
			rb(stacks, 0);
			best--;
		}
	}
	else
	{
		while (best < stacks->lensb)
		{
			rrb(stacks, 0);
			best++;
		}
	}
}

void	rot_both(t_stacks *stacks, int best_move)
{
	if (best_move <= stacks->lensb / 2)
	{
		while (best_move > 0)
		{
			rr(stacks);
			best_move--;
		}
	}
	else
	{
		while (best_move < stacks->lensb)
		{
			rrr(stacks);
			best_move++;
		}
	}
}
