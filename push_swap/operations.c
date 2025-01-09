/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:26:43 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/09 19:42:00 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rrb(t_stacks *stacks, int both)
{
	int	temp;
	int	i;

	i = stacks->lensb - 1;
	temp = stacks->stackb[stacks->lensb - 1];
	while (i > 0)
	{
		stacks->stackb[i] = stacks->stackb[i - 1];
		i--;
	}
	stacks->stackb[0] = temp;
	if (!both)
		ft_printf("rrb\n");
}

void	rrr(t_stacks *stacks)
{
	rra(stacks, 1);
	rrb(stacks, 1);
	ft_printf("rrr\n");
}

void	rr(t_stacks *stacks)
{
	ra(stacks, 1);
	rb(stacks, 1);
	ft_printf("rr\n");
}

void	pa(t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->lensa)
	{
		st->stacka[st->lensa - i] = st->stacka[st->lensa - i - 1];
		i++;
	}
	st->stacka[0] = st->stackb[0];
	st->lensb--;
	st->lensa++;
	i = 0;
	while (i < st->lensb)
	{
		st->stackb[i] = st->stackb[i + 1];
		i++;
	}
	st->stackb[i] = 0;
	ft_printf("pa\n");
}

void	pb(t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->lensb)
	{
		st->stackb[st->lensb - i] = st->stackb[st->lensb - i - 1];
		i++;
	}
	st->stackb[0] = st->stacka[0];
	st->lensb += 1;
	st->lensa -= 1;
	i = 0;
	while (i < st->lensa)
	{
		st->stacka[i] = st->stacka[i + 1];
		i++;
	}
	st->stacka[i] = 0;
	ft_printf("pb\n");
}
