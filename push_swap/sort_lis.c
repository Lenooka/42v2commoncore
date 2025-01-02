/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:30:04 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/02 17:33:16 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	sz(long *stack)
{
	unsigned long a = sizeof(stack);
	unsigned long b = sizeof(stack[0]);
	int l = a / b;
	printf("aaaaaaaaaaaaaa %d\n", l);
	return (l);
}

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
	stacks->lenlis = malloc(stacks->lensa * sizeof *stacks->stacka);
	if (!stacks->lenlis)
		free_handle();
	stacks->indxlis = malloc(stacks->lensa * sizeof *stacks->stacka);
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

	len = stacks->lensa - 1;
	max = findmaxndex_arg(stacks->lenlis, stacks->lensa);
	stacks->lis = malloc(stacks->lensa * sizeof *stacks->stacka);
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
	stacks->lis_len = max;
	while (i != 0)
	{
		stacks->lis[--max] = stacks->stacka[i];
		if (i == 0)
			break ;
		i = stacks->indxlis[i];
	}
	stacks->lis[0] = stacks->stacka[0];
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

//CONDITIONAL JUMP
//add sentiel val to lis 
void	push_notsubseq(t_stacks *stacks)
{
	int i;
	int j;
	int len; 

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

long *op_b(t_stacks *stacks)
{
	long *b;
	int len;
	int i;

	len = stack_len(stacks->stackb);
	if (len == 0)
		return (0);
	b = malloc(len * sizeof *b);
	if (!b)
		free_handle();
	i = 0;
	while (i < len)
	{
		b[i] = i - (i > len / 2) * len;
		i++;
	}
	return (b);
}
// long	*op_a(t_stacks *stacks)
// {
// 	long	*a;
// 	int 	i;
// 	int		len;

// 	i = 0;
// 	len = stack_len(stacks->stacka);
// 	a = malloc(len * sizeof *a);
// 	if (!a)
// 		free_handle();
// 	while (i < len)
// 	{
// 		a[i] = 
// 	}
	
	
	
// }

void	calculate_rotates(t_stacks *stacks)
{
	// while (stack_len(stacks->stackb))
	// {
	// 	stacks->rot_a = op_a(stacks);
		stacks->rot_b = op_b(stacks);
	// }
}


void	sorting_max(t_stacks *stacks)
{
	//asign_index(stacks);
	min_to_the_top(stacks);
	init_lislen_indxlis(stacks);
	init_lis(stacks);
//	print_stacks_arg(stacks->lis);
	push_notsubseq(stacks);	
	// print_stacks_arg(stacks->stacka);
	// print_stacks_arg(stacks->stackb);
	 //print_stacks_arg(stacks->lis);
	//calculate_rotates(stacks);
	print_stacks(stacks);
}