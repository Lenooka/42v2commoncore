/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:20:17 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/09 17:29:50 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sorting_max(t_stacks *stacks)
{
	min_to_the_top(stacks);
	if (!is_not_sorted(stacks))
		free_handle(stacks);
	init_lislen_indxlis(stacks);
	stacks->lis = malloc(stacks->lensa * sizeof * stacks->stacka);
	if (!stacks->lis)
	{
		free(stacks->indxlis);
		free_handle(stacks);
	}
	init_lis(stacks);
	push_notsubseq(stacks);
	push_back_to_a(stacks);
}

void	start_sorting(t_stacks *stacks)
{
	if (stacks->lensa == 3)
		sort_three(stacks);
	else if (stacks->lensa <= 5)
		mid_len_sort(stacks, 0);
	else
		sorting_max(stacks);
}

int	argv_split(t_stacks *stacks, char **argv)
{
	stacks->arg_s = ft_split(argv[1], ' ');
	if (!stacks->arg_s)
		return (free(stacks), ft_putendl_fd("Error", 2), 0);
	if (check_arg(stacks->arg_s, 0))
		return (free(stacks), f_a(stacks->arg_s), ft_putendl_fd("Error", 2), 0);
	stacks = alloc_struct(stacks->arg_s, stacks, 0);
	if (!stacks)
		return (ft_putendl_fd("Error", 2), 0);
	if (fill_struct(stacks, stacks->arg_s, 0) == 1)
	{
		ft_putendl_fd("Error", 2);
		free_handle(stacks);
	}
	if (!check_doubles(stacks->stacka, stacks->lensa))
	{
		ft_putendl_fd("Error", 2);
		free_handle(stacks);
	}
	if (is_not_sorted(stacks))
		start_sorting(stacks);
	free_handle(stacks);
	return (0);
}

int	handle_mult_argv(char **argv, t_stacks *stacks)
{
	stacks->arg_s = NULL;
	if (check_arg(argv, 1))
		return (free(stacks), ft_putendl_fd("Error", 2), 0);
	stacks = alloc_struct(argv, stacks, 1);
	if (!stacks)
		return (free(stacks), ft_putendl_fd("Error", 2), 0);
	if (fill_struct(stacks, argv, 1) == 1)
	{
		ft_putendl_fd("Error", 2);
		free_handle(stacks);
	}
	if (!check_doubles(stacks->stacka, stacks->lensa))
	{
		ft_putendl_fd("Error", 2);
		free_handle(stacks);
	}
	if (is_not_sorted(stacks))
		start_sorting(stacks);
	free_handle(stacks);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	if (argc == 2)
	{
		stacks = (t_stacks *)malloc(sizeof(t_stacks));
		if (!stacks)
			return (0);
		argv_split(stacks, argv);
		return (0);
	}
	if (argc > 2)
	{
		stacks = (t_stacks *)malloc(sizeof(t_stacks));
		if (!stacks)
			return (0);
		handle_mult_argv(argv, stacks);
		return (0);
	}
	return (0);
}
