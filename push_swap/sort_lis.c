/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:30:04 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/09 15:18:28 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	calc_lislen_indxlis(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	while (i < stacks->lensa)
	{
		j = 0;
		while (j < i)
		{
			if (stacks->stacka[i] > stacks->stacka[j])
			{
				if (stacks->lenlis[i] < stacks->lenlis[j] + 1)
				{
					stacks->lenlis[i] = stacks->lenlis[j] + 1;
					stacks->indxlis[i] = j;
				}
			}
			j++;
		}
		i++;
	}
}

void	get_lis_len(t_stacks *stacks)
{
	int	i;
	int	max;
	int	len;

	len = stacks->lensa - 1;
	max = findmaxndex_arg(stacks->lenlis, len);
	stacks->max_lis = max;
	while (len >= 0)
	{
		if (stacks->lenlis[len] == max)
		{
			i = len;
			break ;
		}
		else
			i = 0;
		len--;
	}
	stacks->lis_len = i;
	free(stacks->lenlis);
}

void	init_lislen_indxlis(t_stacks *stacks)
{
	int		i;

	i = 0;
	stacks->lenlis = malloc(stacks->lensa * sizeof * stacks->stacka);
	if (!stacks->lenlis)
		free_handle(stacks);
	stacks->indxlis = malloc(stacks->lensa * sizeof * stacks->stacka);
	if (!stacks->indxlis)
	{
		free(stacks->lenlis);
		free_handle(stacks);
	}
	while (i < stacks->lensa)
	{
		stacks->lenlis[i] = 1;
		stacks->indxlis[i] = -1;
		i++;
	}
	calc_lislen_indxlis(stacks);
	get_lis_len(stacks);
}

void	init_lis(t_stacks *stacks)
{
	int	i;
	int	max;

	i = stacks->lis_len;
	max = stacks->max_lis;
	while (i != 0)
	{
		--max;
		stacks->lis[max] = stacks->stacka[i];
		if (i == 0)
			break ;
		i = stacks->indxlis[i];
	}
	stacks->lis[0] = stacks->stacka[0];
	free(stacks->indxlis);
}

void	push_notsubseq(t_stacks *stacks)
{
	int	i;
	int	j;
	int	len;

	i = stacks->lensa;
	len = stacks->max_lis;
	j = 0;
	while (i)
	{
		if (j <= len - 1)
		{
			if (stacks->lis[0] == stacks->stacka[0])
			{
				ra(stacks, 0);
				lisr(stacks->lis, stacks->lensa);
				j++;
			}
			else
				pb(stacks);
		}
		else
			pb(stacks);
		i--;
	}
	free(stacks->lis);
}
