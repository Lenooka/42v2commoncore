/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:30:04 by oltolmac          #+#    #+#             */
/*   Updated: 2024/12/22 20:50:45 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	min_to_the_top(t_stacks *stacks)
{
	int min;

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

void	calc_lislen_indxlis(t_stacks *stacks)
{
	int i;
	int j;
	
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
	stacks->lenlis = malloc(stacks->lensa * sizeof *stacks->lenlis);
	if (!stacks->lenlis)
		free_handle();
	stacks->indxlis = malloc(stacks->lensa * sizeof *stacks->indxlis);
	if (!stacks->indxlis)
		free_handle();
	while (i < stacks->lensa)
	{
		stacks->lenlis[i] = 1;
		stacks->indxlis[i] = -1;
		i++;
	}
	calc_lislen_indxlis(stacks);
}

int	get_index(long *arr, int value)
{
	int	len;

	len = stack_len(arr);
	while (len--)
	{
		if (arr[len] == value)
			return (len);
	}
	return (0);
}

void	init_lis(t_stacks *stacks)
{
	int i;
	int max;
	int len;

	len = stack_len(stacks->stacka);
	max = findmaxndex_arg(stacks->lenlis);
	stacks->lis = malloc(stacks->lenlis[max] * sizeof *stacks->lis);
	i = -1;
	while (++i < len)
	{
		if (stacks->lenlis[i] > max)
			max = stacks->lenlis[i];
	}
	while (len >= 0)
	{
		if (stacks->lenlis[len] == max)
		{
			i = len;
			break;
		}
		else
			i = 0;
		len--;
	}
	while (i != 0)
	{
		stacks->lis[--max] = stacks->stacka[i];
		if (i == 0)
			break ;
		i = stacks->indxlis[i];
	}
	stacks->lis[0] = stacks->stacka[0];
}


void	lisr(long *s)
{
	int	temp;
	int	i;
	int len;

	i = 0;
	temp = s[0];
	len = stack_len(s);
	while (i < len - 1)
	{
		s[i] = s[i + 1];
		i++;
	}
	s[len - 1] = temp;
}


void	push_notsubseq(t_stacks *stacks)
{
	int i;

	i = 0;
	i = stack_len(stacks->stacka);
	while (i)
	{
		if (stacks->stacka[0] == stacks->lis[0])
		{
			ra(stacks, 0);
			lisr(stacks->lis);
		}
		else
			pb(stacks);
		i--;
	}
	i = 0;
	while (stacks->stacka[i])
	{
		printf("li<s[%d] = %ld\n", i, stacks->stacka[i]);
		i++;
	}
}

void	sorting_max(t_stacks *stacks)
{
	//asign_index(stacks);
	min_to_the_top(stacks);
	init_lislen_indxlis(stacks);
	init_lis(stacks);
	push_notsubseq(stacks);
	print_stacks(stacks);
}