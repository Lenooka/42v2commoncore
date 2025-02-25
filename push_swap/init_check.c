/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:21:42 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/25 16:25:17 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

long	ft_strtol(const char *str, char **endptr, int minus)
{
	long	result;

	result = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX - (*str - '0')) / 10)
		{
			if (endptr != NULL)
				*endptr = (char *)str;
			return (LONG_MAX);
		}
		result = result * 10 + (*str - '0');
		str++;
	}
	if (endptr != NULL)
		*endptr = (char *)str;
	return (result * minus);
}

int	fill_struct(t_stacks *stacks, char **argv, int i)
{
	long	val;
	char	*endptr;
	int		j;

	j = 0;
	while (argv[i])
	{
		val = ft_strtol(argv[i], &endptr, 1);
		if (*endptr != '\0')
		{
			return (1);
		}
		if (val > INT_MAX || val < INT_MIN)
		{
			return (1);
		}
		stacks->stacka[j] = val;
		i++;
		j++;
	}
	stacks->lensa = j;
	stacks->lensb = 0;
	return (0);
}

t_stacks	*alloc_struct(char **argv, t_stacks *stacks, int elem_am)
{
	while (argv[elem_am])
		elem_am++;
	stacks->stacka = (long *)malloc(sizeof(long) * elem_am + 1);
	if (!stacks->stacka)
	{
		f_a(stacks->arg_s);
		free(stacks);
		return (NULL);
	}
	stacks->stackb = (long *)malloc(sizeof(long) * elem_am + 1);
	if (!stacks->stackb)
	{
		f_a(stacks->arg_s);
		free(stacks->stacka);
		free(stacks);
		return (NULL);
	}
	return (stacks);
}

int	check_doubles(long *stack, int len)
{
	int	i;
	int	dob;

	i = 0;
	dob = 0;
	while (i < len)
	{
		while (dob < len)
		{
			if (stack[i] == stack[dob] && i != dob)
				return (0);
			dob++;
		}
		dob = 0;
		i++;
	}
	return (1);
}

int	check_arg(char **argv, int i)
{
	int	x;

	while (argv[i])
	{
		x = 0;
		while (argv[i][x])
		{
			if (!ft_isdigit(argv[i][x]) && argv[i][x] != '-'
				&& argv[i][x] != '+')
				return (1);
			x++;
		}
		i++;
	}
	return (0);
}
