/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:39:07 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/05 15:26:59 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	print_stacks_arg(long *stacks)
{
	int i = 0;
	int len = stack_len(stacks);

	len = 10;
	printf("=|=|=|=|=|=|=|=|=|=|=|=|=|=|=\n");
	while (i < len)
	{
		printf(" %ld\n", stacks[i]);
		i++;
	}
	i = 0;
	printf("=|=|=|=|=|=|=|=|=|=|=|=|=|=|=\n");
}

void	print_stacks(t_stacks  *stacks)
{
	int i = 0;

	printf("===============\n");
	while (i < stacks->lensa)
	{
		printf("stack a  %ld\n", stacks->stacka[i]);
		i++;
	}
	i = 0;
	printf("===============\n");
	stacks->lensb = stack_len(stacks->stackb);
	if (stacks->lensb != 0)
	{
		while (i <= stacks->lensb)
		{
			printf("stack b  %ld\n", stacks->stackb[i]);
			i++;
		}
	}
	if (!is_not_sorted(stacks))
		printf("OK\n");
}

void	print_stacks_argg(long *stacks, int len)
{
	int i = 0;

	printf("=|=|=|=|=|=|=|=|=|=|=|=|=|=|=\n");
	while (i < len)
	{
		printf(" %ld\n", stacks[i]);
		i++;
	}
	i = 0;
	printf("=|=|=|=|=|=|=|=|=|=|=|=|=|=|=\n");
}