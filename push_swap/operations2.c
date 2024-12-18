/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations 2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:26:43 by oltolmac          #+#    #+#             */
/*   Updated: 2024/12/18 07:27:40 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rb(t_stacks *stacks, int both)
{
	int	temp;
	int	i;

	i = 0;
	temp = stacks->stackb[0];
	while (i < stacks->lensb - 1)
	{
		stacks->stackb[i] = stacks->stackb[i + 1];
		i++;
	}
	stacks->stackb[stacks->lensb - 1] = temp;
	if (!both)
		ft_printf("rb\n");
}

void	rra(t_stacks *stacks, int both)
{
	int	temp;
	int	i;

	i = stacks->lensa - 1;
	temp = stacks->stacka[stacks->lensa - 1];
	while (i > 0)
	{
		stacks->stacka[i] = stacks->stacka[i - 1];
		i--;
	}
	stacks->stacka[0] = temp;
	if (!both)
		ft_printf("rra\n");
}


void	sa(t_stacks *stacks, int both)
{
	int	swap;

	if (!stacks->stacka)
		return ;
	swap = stacks->stacka[0];
	stacks->stacka[0] = stacks->stacka[1];
	stacks->stacka[1] = swap;
	if (!both)
		ft_printf("sa\n");
}

void	sb(t_stacks *stacks, int both)
{
	int	swap;

	if (!stacks->stackb)
		return ;
	swap = stacks->stackb[0];
	stacks->stackb[0] = stacks->stackb[1];
	stacks->stackb[1] = swap;
	if (!both)
		ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	sa(stacks, 1);
	sb(stacks, 1);
	ft_printf("ss\n");
}