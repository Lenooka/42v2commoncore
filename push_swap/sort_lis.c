/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:30:04 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/07 21:25:21 by olena            ###   ########.fr       */
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
		stacks->lenlis[i] = 1;
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
}

void	initlistwo(t_stacks *stacks, int max, int i)
{
	stacks->lis_len = max;
	while (i != 0)
	{
		stacks->lis[--max] = stacks->stacka[i];
		if (i == 0)
			break ;
		i = stacks->indxlis[i];
	}
	stacks->lis[0] = stacks->stacka[0];
	free(stacks->lenlis);
	free(stacks->indxlis);
}

void	init_lis(t_stacks *stacks)
{
	int	i;
	int	max;
	int	len;

	len = stacks->lensa - 1;
	max = findmaxndex_arg(stacks->lenlis, len);
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
	initlistwo(stacks, max, i);
}

void	push_notsubseq(t_stacks *stacks)
{
	int	i;
	int	j;
	int	len;

	i = stacks->lensa;
	len = stacks->lis_len;
	j = 0;
	while (i)
	{
		if (j <= len - 1)
		{
			if (stacks->stacka[0] == stacks->lis[0])
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
