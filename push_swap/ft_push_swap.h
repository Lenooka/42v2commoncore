/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:00:39 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/03 16:15:46 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# define A 0
# define B 1
# define BOTH 2
# define MAX 2147483647

# include "libftp/libft.h"
# include <limits.h>

typedef struct s_stacks
{
	long			*stacka;
	long			*stackb;
	long			*lenlis;
	long			*indxlis;
	long			*lis;
	int				lis_len;
	int				lensa;
	int				lensb;
	int				min_indx;
	int				max_indx;
	int				min_indxb;
	int				max_indxb;
	long			*rot_a;
	long			*rot_b;
}	t_stacks;

void		sa(t_stacks *stacks, int op);
void		sb(t_stacks *stacks, int op);
void		ss(t_stacks *stacks);
void		rra(t_stacks *stacks, int op);
void		rrb(t_stacks *stacks, int op);
void		rrr(t_stacks *stacks);
void		ra(t_stacks *stacks, int op);
void		rb(t_stacks *stacks, int op);
void		rr(t_stacks *stacks);
void		pa(t_stacks *stacks);
void		pb(t_stacks *stacks);
void		free_handle(t_stacks *stacks);
void		free_arr(char **str);
long		ft_strtol(const char *str, char **endptr, int minus);
int			fill_struct(t_stacks *stacks, char **argv, int i);
t_stacks	*alloc_struct(char **argv, t_stacks *stacks, int elem_am);
int			check_doubles(long *stack, int len);
int			check_arg(char **argv);
void		start_sorting(t_stacks *stacks);
int			argv_split(t_stacks *stacks, char **argv);
int			handle_mult_argv(char **argv, t_stacks *stacks);
void		start_sorting(t_stacks *stacks);
void		sorting_max(t_stacks *stacks);
void		init_lis(t_stacks *stacks);
void		initlistwo(t_stacks *stacks, int max, int i);
void		init_lislen_indxlis(t_stacks *stacks);
void		calc_lislen_indxlis(t_stacks *stacks);
void		min_to_the_top(t_stacks *stacks);
void		sort_three(t_stacks *stacks);
void		mid_len_sort(t_stacks *stacks, int middlen);
int			stack_len(long *stack);
void		findmindex(t_stacks *stacks);
void		findmindexb(t_stacks *stacks);
int			is_not_sorted(t_stacks *stacks);
int			findmaxndex_arg(long *stack, int len);
void		findmaxndex(t_stacks *stacks);
void		print_stacks_arg(long *stacks);
void		lisr(long *s, int len);
void		print_stacks(t_stacks *stacks);
void		rotat_a(t_stacks *stacks, int ta);
void		rotat_b(t_stacks *stacks, int best);
void		push_notsubseq(t_stacks *stacks);
void		push_back_to_a(t_stacks *stacks);
int			bestmove(t_stacks *stacks, int best);
#endif