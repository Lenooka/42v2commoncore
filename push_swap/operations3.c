/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:26:43 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/03 16:03:31 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ra(t_stacks *stacks, int both)
{
	int	temp;
	int	i;

	i = 0;
	temp = stacks->stacka[0];
	while (i < stacks->lensa - 1)
	{
		stacks->stacka[i] = stacks->stacka[i + 1];
		i++;
	}
	stacks->stacka[stacks->lensa - 1] = temp;
	if (!both)
		ft_printf("ra\n");
}
