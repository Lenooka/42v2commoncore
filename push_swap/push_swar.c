/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swar.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:28:57 by oltolmac          #+#    #+#             */
/*   Updated: 2024/12/15 05:12:45 by olena            ###   ########.fr       */
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
	char 	*endptr;
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
	stacks = (t_stacks *)malloc(sizeof(t_stacks));
	if (!stacks)
		return (NULL);
	stacks->stacka = (long *)malloc(sizeof(long) * elem_am + 1);
	if (!stacks->stacka)
	{
		free(stacks);
		return(NULL);
	}
	stacks->stackb = (long *)malloc(sizeof(long) * elem_am + 1);
	if (!stacks->stackb)
	{
		free(stacks->stacka);
		free(stacks);
		return(NULL);
	}
	return (stacks);
}

void	free_handle()
{
	exit(1);
}

int	check_arg(char **argv)
{
	int	i;
	int	x;

	i = 1;
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

void	rrb(t_stacks *stacks, int both)
{
	int	temp;
	int	i;

	i = stacks->lensb - 1;
	temp = stacks->stackb[stacks->lensb - 1];
	while (i > 0)
	{
		stacks->stackb[i] = stacks->stackb[i - 1];
		i--;
	}
	stacks->stackb[0] = temp;
	if (!both)
		ft_printf("rrb\n");

}

void	rrr(t_stacks *stacks)
{
	rra(stacks, 1);
	rrb(stacks, 1);
	ft_printf("rrr\n");
}

void	rr(t_stacks *stacks)
{
	ra(stacks, 1);
	rb(stacks, 1);
	ft_printf("rr\n");
}

void	pa(t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->lensa)
	{
		st->stacka[st->lensa - i] = st->stacka[st->lensa - i - 1];
		i++;
	}
	st->stacka[0] = st->stackb[0];
	st->lensb--;
	st->lensa++;
	i = 0;
	while (i < st->lensb)
	{
		st->stackb[i] = st->stackb[i + 1];
		i++;
	}
	st->stackb[i] = 0;
	ft_printf("pa\n");
}

void	pb(t_stacks *st)
{
	int	i;

	i = 0;
	while (i < st->lensb)
	{
		st->stackb[st->lensb - i] = st->stackb[st->lensb - i - 1];
		i++;
	}
	st->stackb[0] = st->stacka[0];
	st->lensb += 1;
	st->lensa -= 1;
	i = 0;
	while (i < st->lensa)
	{
		st->stacka[i] = st->stacka[i + 1];
		i++;
	}
	st->stacka[i] = 0;
	ft_printf("pb\n");
}

// void	findmindex(t_stacks *stacks)
// {
// 	int	i;

// 	i = 0;
// 	stacks->min_indx = 0;
// 	while (i < stacks->lensa)
// 	{
// 		if (stacks->stacka[stacks->min_indx] > stacks->stacka[i])
// 			stacks->min_indx = i;
// 		i++;
// 	}
// }

// void	posofmin(t_stacks *stacks, int middlensa)
// {
// 	if (stacks->min_indx < middlensa)
// 	{
// 		ra(stacks, 0);
// 	}
// 	else if (stacks->min_indx >= middlensa)
// 	{
// 		rra(stacks, 0);
// 	}
// }

// void	shortsort(t_stacks *stacks)
// {
// 	int	middlen;

// 	while (stacks->lensa != 1 && is_not_sorted(stacks))
// 	{
// 		middlen = stacks->lensa / 2;
// 		findmindex(stacks);
// 		if (stacks->min_indx == 0)
// 			pb(stacks);
// 		else if (stacks->min_indx == 1)
// 		{
// 			if (stacks->stacka[0] > stacks->stacka[stacks->lensa - 1])
// 				ra(stacks, 0);
// 			else
// 				sa(stacks, 0);
// 		}
// 		else
// 		{
// 			if (stacks->stacka[0] > stacks->stacka[1])
// 				sa(stacks, 0);
// 			posofmin(stacks, middlen);
// 		}
// 	}
// 	while (stacks->lensb > 0)
// 		pa(stacks);
// }
// void	longsort(t_stacks *stacks)
// {
// 	int min;
// 	int max;

// 	while (is_not_sorted(stacks))
// 	{
// 		findmindex(stacks);
// 		findmaxndex(stacks);
// 		min = stacks->stacka[stacks->min_indx];
// 		max = stacks->stacka[stacks->max_indx];
// 		while (min != stacks->stacka[0])
// 		{
// 			ra(stacks, 0);
// 		}
// 		pb(stacks);
// 	}
// 	int i = 0;
// 	int len = stacks->lensb; 
// 	while (len >= i)
// 	{
// 		pa(stacks);
// 		i++;	
// 	}
// 	//print_stacks(stacks);
// }


// void	longsort(t_stacks *stacks)
// {

// 	while (is_not_sorted(stacks))
// 	{
// 		pb(stacks);
// 		if (stacks->stackb[0] < stacks->stacka[0])
// 		{
// 			pa(stacks);
// 			ra(stacks, 0);
// 		}
// 		else
// 		{
// 			while (!(stacks->stackb[0] < stacks->stacka[0]))
// 			{
// 				ra(stacks, 0);
// 				pb(stacks);	
// 			}
// 		}
// 	}
// 	int i = 0;
// 	int len = stacks->lensb; 
// 	while (len >= i)
// 	{
// 		pa(stacks);
// 		i++;	
// 	}
// 	print_stacks(stacks);
// }
// void	step_one(t_stacks *stacks)
// {
// 	int min;

// 	findmindex(stacks);
// 	min = stacks->min_indx;
// 	if (stacks->stacka[0] > stacks->stacka[3])
// 		ra(stacks, 0);
// 	else if (min == 1 && stacks->stacka[0] < stacks->stacka[2])
// 		sa(stacks, 0);
// 	else if (stacks->stacka[0] < stacks->stacka[3] 
// 		&& stacks->stacka[0] > stacks->stacka[2])
// 	{
// 		rra(stacks, 0);
// 		pb(stacks);
// 		sort_three(stacks);
// 		pa(stacks);
// 		ra(stacks, 0);
// 	}
// }

// void	step_two(t_stacks *stacks)
// {
// 	int min;
	
// 	findmindex(stacks);
// 	min = stacks->min_indx;
// 	while (is_not_sorted(stacks))
// 	{
// 		if (stacks->stacka[0] > stacks->stacka[4])
// 			ra(stacks, 0);
// 		else if (min == 1 && stacks->stacka[0] < stacks->stacka[2])
// 			sa(stacks, 0);
// 		else if (stacks->stacka[0] < stacks->stacka[4] 
// 			&& stacks->stacka[0] > stacks->stacka[2] && stacks->stacka[0] < stacks->stacka[3])
// 		{
// 			rra(stacks, 0);
// 			pb(stacks);
// 			sort_three(stacks);
// 			pa(stacks);
// 			ra(stacks, 0);
// 		}
// 		else if (min == 1 && stacks->stacka[0] > stacks->stacka[2] && stacks->stacka[0] < stacks->stacka[3])
// 		{
// 			pb(stacks);
// 			pb(stacks);
// 			pb(stacks);
// 			rrb(stacks, 0);
// 			sb(stacks, 0);
// 			rb(stacks, 0);
// 			pa(stacks);
// 			pa(stacks);
// 			pa(stacks);
// 			sa(stacks, 0);
// 		}
// 	}
// }

// void	findmindex(t_stacks *stacks)
// {
// 	int	i;

// 	i = 0;
// 	stacks->min_indx = 0;
// 	while (i < stacks->lensa)
// 	{
// 		if (stacks->stacka[stacks->min_indx] > stacks->stacka[i])
// 			stacks->min_indx = i;
// 		i++;
// 	}
// }

// void	posofmin(t_stacks *stacks, int middlensa)
// {
// 	if (stacks->min_indx < middlensa)
// 	{
// 		ra(stacks, 0);
// 	}
// 	else if (stacks->min_indx >= middlensa)
// 	{
// 		rra(stacks, 0);
// 	}

// void	findmindex(t_stacks *stacks)
// {
// 	int	i;

// 	i = 0;
// 	stacks->min_indx = 0;
// 	while (i < stacks->lensa)
// 	{
// 		if (stacks->stacka[stacks->min_indx] > stacks->stacka[i])
// 			stacks->min_indx = i;
// 		i++;
// 	}
// }

// void	sort_five(t_stacks *stacks)
// {
// 	int midlen;

// 	sort_three(stacks);
// 	if (is_not_sorted(stacks))
// 		mid_len_sort(stacks, midlen);
// 	while (stacks->lensb > 0)
// 		pa(stacks);
// }

// void	asign_index(t_stacks *stacks)
// {
// 	int			i;
// 	int			j;
// 	int			indx;
// 	long		*tempa;

// 	tempa = malloc(stacks->lensa * sizeof * tempa);
// 	// if (!tempa)
// 	i = 0;
// 	while (i < stacks->lensa)
// 	{
// 		indx = 0;
// 		j = -1;
// 		while (++j < stacks->lensa)
// 			if (stacks->stacka[i] > stacks->stacka[j])
// 				indx++;
// 		tempa[i] = indx;
// 		i++;
// 	}
// 	i = stacks->lensa;
// 	while (i--)
// 	{
// 		stacks->stacka[i] = tempa[i];
// 	}
// 	free(tempa);
// }
// }
int	is_not_sorted(t_stacks *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stacks->lensa)
	{
		while (j < stacks->lensa)
		{
			if (stacks->stacka[i] > stacks->stacka[j] && i < j)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

void	findmindexb(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->min_indxb = 0;
	while (i < stacks->lensb)
	{
		if (stacks->stackb[stacks->min_indxb] > stacks->stackb[i])
			stacks->min_indxb = i;
		i++;
	}
}

void	findmindex(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->min_indx = 0;
	while (i < stacks->lensa)
	{
		if (stacks->stacka[stacks->min_indx] > stacks->stacka[i])
			stacks->min_indx = i;
		i++;
	}
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
	while (i <= stacks->lensb)
	{
		printf("stack b  %ld\n", stacks->stackb[i]);
		i++;
	}
	if (!is_not_sorted(stacks))
		printf("OK\n");
}

void	findmaxndex(t_stacks *stacks)
{
	int	i;

	i = 0;
	stacks->max_indx = 0;
	while (i < stacks->lensa)
	{
		if (stacks->stacka[stacks->max_indx] < stacks->stacka[i])
			stacks->max_indx = i;
		i++;
	}
}
void	findmaxnextndex(t_stacks *stacks)
{
	int	i;
	int next;

	i = 0;
	next = 0;
	while (i < stacks->lensa)
	{
		if (stacks->stacka[stacks->max_indx] < stacks->stacka[i] && i != stacks->max_indx)
		{
			stacks->max_indx = i;
			next = i;
		}
		i++;
	}
}


void	sort_three(t_stacks *stacks)
{
	int min;
	int max;

	findmindex(stacks);
 	findmaxndex(stacks);
 	min = stacks->min_indx;
 	max = stacks->max_indx;
	if (min == 1 && max == 2)
		sa(stacks, 0);
	else if (min == 2 && max == 0)
	{
		sa(stacks, 0);
		rra(stacks, 0);
	}
	else if (min == 1 && max == 0)
		ra(stacks, 0);
	else if (min == 0 && max == 1)
	{
		sa(stacks, 0);
		ra(stacks, 0);
	}
	else if (min == 2 && max == 1)
		rra(stacks, 0);
}	

void	mid_len_sort(t_stacks *stacks, int middlen)
{
	while (stacks->lensa != 1 && is_not_sorted(stacks))
	{
		middlen = stacks->lensa / 2;
		findmindex(stacks);
		if (stacks->min_indx == 0)
			pb(stacks);
		else if (stacks->min_indx == 1)
		{
			if (stacks->stacka[0] > stacks->stacka[stacks->lensa - 1])
				ra(stacks, 0);
			else
				sa(stacks, 0);
		}
		else
		{
			if (stacks->stacka[0] > stacks->stacka[1])
				sa(stacks, 0);
			if (stacks->min_indx < middlen)
				ra(stacks, 0);
			else if (stacks->min_indx >= middlen)
				rra(stacks, 0);
		}
	}
	while (stacks->lensb > 0)
		pa(stacks);
}

void	asign_index(t_stacks *stacks)
{
	long		*tempa;
	long		*indx_temp;
	tempa = malloc(stacks->lensa * sizeof * tempa);
	//if (!tempa)
	indx_temp = malloc(stacks->lensa * sizeof * tempa);
	int i = 0;
	while (i < stacks->lensa)
	{
		tempa[i] = stacks->stacka[i];
		//printf("%ld\n", tempa[i]);
		//printf("%ld\n",stacks->stacka[i]);
		i++; 
	}
	//tempa = ft_sort_int_tab(tempa, stacks->lensa);
	i = 0;
	while (i < stacks->lensa)
	{
		tempa[i] = stacks->stacka[i];
		//printf("%ld\n", tempa[i]);
		//printf("%ld\n",stacks->stacka[i]);
		i++; 
	}
	i = 0;
	int j = 0;
	int inf = 0;
	while (i < stacks->lensa)
	{
		j = 0;
		inf = 0;
		while (j < stacks->lensa)
		{
			if (tempa[i] > stacks->stacka[j])
			{
				inf++;
			}
			j++;
		}
		indx_temp[i] = inf;
		i++;
	}
	i = 0;
	while (i < stacks->lensa)
	{
		stacks->stacka[i] = indx_temp[i];
		//printf("%ld\n", indx_temp[i]);
		//printf("%ld\n", tempa[i]);
		i++;
	}
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



long	*lng_inc_subs(t_stacks *stacks)
{
	long	*temp; //lengtg of the longest increasing subsequence
	long	*temp2; //index of the previous element in the subsequence
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	temp = malloc(stacks->lensa * sizeof *temp);
	temp2 = malloc(stacks->lensa * sizeof *temp2);
	while (i < stacks->lensa)
	{
		temp[i] = 1;
		temp2[i] = -1;
		i++;
	}
	i = 1;
	while (i < stacks->lensa)
	{
		j = 0;
		while (j < i)
		{
			if (stacks->stacka[i] > stacks->stacka[j] && temp[i] < temp[j] + 1)
			{
				temp[i] = temp[j] + 1;
				temp2[i] = j;
			}
			j++;
		}
		i++;
	}
	return (temp);
}

void	sorting_max(t_stacks *stacks)
{
	asign_index(stacks);
	min_to_the_top(stacks);
	stacks->stacka = lng_inc_subs(stacks);
	print_stacks(stacks);
}

void	start_sorting(t_stacks *stacks)
{
	if (stacks->lensa == 3)
		sort_three(stacks);
	//else if (stacks->lensa <= 5)
		//mid_len_sort(stacks, 0);
	else
		sorting_max(stacks);
	//print_stacks(stacks);
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


int	argv_split(t_stacks *stacks, char **argv)
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

int	handle_mult_argv(char **argv, t_stacks *stacks)
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
	// if (!check_doubles(stacks->stacka, stacks->lensa))
	// {
	// 	ft_printf("Error\n");
	// 	free_handle();
	// }
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
		argv_split(stacks, argv);
		return (0);
	} 
	if (argc > 2)
	{
		handle_mult_argv(argv, stacks);
		return (0);
	}
	return (0);
}
