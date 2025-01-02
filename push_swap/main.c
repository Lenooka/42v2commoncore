/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:20:17 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/02 18:06:30 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	start_sorting(t_stacks *stacks)
{
	if (stacks->lensa == 3)
		sort_three(stacks);
	else if (stacks->lensa <= 5)
		mid_len_sort(stacks, 0);
	else
		sorting_max(stacks);
	//print_stacks(stacks);
}

int argv_split(t_stacks *stacks, char **argv)
{
	char	**argv_split;

	argv_split = ft_split(argv[1], ' ');
	if (!argv_split)
			return (ft_printf("Error\n"), 0);
	if (check_arg(argv_split))
		return (ft_printf("Error\n"), 0);
	stacks = alloc_struct(argv_split, stacks, 0);
	if (!stacks)
		return (ft_printf("Error\n"), 0);
	if (fill_struct(stacks, argv_split, 0) == 1)
	{
		ft_printf("Error\n");
		free_handle();
	}
	if (!check_doubles(stacks->stacka, stacks->lensa))
	{
		ft_printf("Error\n");
		free_handle();
	}
	if (is_not_sorted(stacks))
		start_sorting(stacks);
	//free_arr(argv_split);
	//free_handle;
	return (0);
}

int handle_mult_argv(char **argv, t_stacks *stacks)
{
	if (check_arg(argv))
		return (ft_printf("Error\n"), 0);
	stacks = alloc_struct(argv, stacks, 1);
	if (!stacks)
		return (ft_printf("Error\n"), 0);
	if (fill_struct(stacks, argv, 1) == 1)
	{
		ft_printf("Error\n");
		free_handle();
	}
	if (!check_doubles(stacks->stacka, stacks->lensa))
	{
		ft_printf("Error\n");
		free_handle();
	}
	if (is_not_sorted(stacks))
		start_sorting(stacks);
	//free_handle;
	return (0);
}

int	main(int argc, char **argv)
{
	t_stacks *stacks;
	
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