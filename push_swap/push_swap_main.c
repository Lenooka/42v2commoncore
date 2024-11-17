/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 13:41:35 by oltolmac          #+#    #+#             */
/*   Updated: 2024/11/13 14:43:43 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static t_stack	*ft_lstneb(void)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}
static t_stack	*ft_lstne(int content)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_stack	*fill_struct(char **argv, int t)
{
	int	i;
	int j;
	t_stack *head;
	t_stack *node;

	if (t == 0)
	{
		i = 1;
		j = 0;
	}
	else
	{
		i = 2;
		j = 1;
	}
	head = ft_lstne((int)ft_atoi(argv[j]));
	node = head;
	while (argv[i])
	{
		node->next = ft_lstne((int)atoi(argv[i]));
		node = node->next;
		i++;
	}
	return (head);
}

int	valid_char(char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] && s != NULL)
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
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
			if (!ft_isdigit(argv[i][x]) && argv[i][x] != '-'  && argv[i][x] != '+')
					return (1);
			x++;
		}
		i++;
	}
	return (0);
}

int	stack_a_print(t_stack *head_a)
{

	while (head_a)
	{
		printf("head_a->content = %d\n", head_a->content);
		head_a = head_a->next;
	}
	return (0);
}

char	**free_arr(char **str)
{
	int	a;

	a = 0;
	while (str[a] != NULL)
	{
		free(str[a]);
		a++;
	}
	free(str);
	return (NULL);
}

int	elem_count(t_stack *a)
{
	int c;

	c = 0;
	while (a)
	{
		c++;
		a = a->next;
	}
	return (c);
}


int	swap(t_stack *stack, int ind)
{
	int s;

	if (!stack || !stack->next)
		return (0);
	s = stack->content;
	stack->content = stack->next->content;
	stack->next->content = s;
	if (!ind)
		ft_printf("sa\n");
	else if (ind == 1)
		ft_printf("sb\n");
	return (1);
}

void	ss_swap(t_stack *a, t_stack *b)
{	
	swap(a, 2);
	swap(b, 2);
	ft_printf("ss\n");
}

void	push_on_top(t_stack **a, t_stack **b, int ind)
{
	t_stack *temp;

	if (!a)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	if (!ind)
		ft_printf("pa\n");
	else if (ind == 1)
		ft_printf("pb\n");
	
}

t_stack *rotaa(t_stack **a)
{
	int size;
	int i;
	t_stack *head;

	size = elem_count(*a);
	i = 0;
	printf("size %d\n", size);
	while (i < size)
	{
		while ((*a)->next)
			*a = (*a)->next;	
		i++;
		head = *a;
		(*a)->next = head;
		*a = (*a)->next;
		head = head->next;
		(*a)->next = NULL;
	}
	return (head);
}

t_stack *rota(t_stack **a, int ind)
{
	int size;
	int i;
	int	f_el;
	t_stack *head;

	size = elem_count(*a);
	i = 0;
	head = *a;
	f_el = (*a)->content;
	while (i < size - 1 && (*a)->next)
	{
		(*a)->content = (*a)->next->content;
		(*a) = (*a)->next;
		i++;
	}
	(*a)->content = f_el;
	if (!ind)
		ft_printf("ra\n");
	else if (ind == 1)
		ft_printf("rb\n");
	return (head);
}

void	sort_threee(t_stack *a)
{
	int i;
	int temp;
	t_stack *head;

	head = a;
	i = 0;
	temp = 0;
	while (i <= 3 && a)
	{
		a = head;
		while (a->next)
		{
			temp = a->next->content;
			if (a->content > temp)
			{
				swap(a, A); //SWAPS WHATEVER I GIVE BUT NOT JUST FIRST TWO ELEM LOGIC WRONG
			}
			a = a->next;
		}
		i++;
	}
}

int	sorted(t_stack *stack)
{
	int i;

	i = 0;
	while (stack && stack->next)
	{
		if (stack->content > stack->next->content)
		{
			return (0);
		}
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_stack *a, t_stack *b)
{
	int		i;
	t_stack *head;

	head = a;
	if (!sorted(a))
	{
		i = 1;
		if (i == 0)		
			push_on_top(&a, &b, B);
		else if (i == 1)
		{
			if (a->content > a->next->content)
				swap(a, A);
			else
				rota(&a, A);
		}
		if (!sorted(a))
		// else
		{
			if (a->content > a->next->content)
				swap(a, A);
		}
	}
	while (b->next)
	{
		push_on_top(&b, &a, A);
	}
}

void	start_sorting(t_stack *head_a, t_stack *head_b)
{
	int	elem_am;

	elem_am = elem_count(head_a);
	if (!sorted(head_a) && elem_am == 3)
		sort_three(head_a, head_b);
	// push_on_top(&head_a, &head_b, B); NEED TO ADD CHECK FOR DUP AND INT OVERFLOW X.X =_= 
	// push_on_top(&head_a, &head_b, B);
	// while (head_b->next)
	// {
	// 	push_on_top(&head_b, &head_a, A);
	// }
	//head_a = rota(&head_a, A);
	stack_a_print(head_a);
	printf("H\n");
	stack_a_print(head_b);
	
}

int	argv_split(t_stack *head_a, t_stack *head_b, char **argv)
{
	char	**argv_split;

	argv_split = ft_split(argv[1], ' ');
	if (!argv_split)
	{			
		ft_printf("Error\n");
		return (0);
	}
	if (check_arg(argv_split))
	{
		ft_printf("Error\n");
		return (0);
	}
	head_a = fill_struct(argv_split, 0);
	if (!head_a)
		return (ft_printf("Error\n"), 0);
	head_b = ft_lstneb();
	if (!head_b)
	{
		free(head_a);
		return (ft_printf("Error\n"), 0);
	}
	start_sorting(head_a, head_b);
	free_arr(argv_split);
	return (0);
}

int	handle_mult_argv(char **argv, t_stack *head_a, t_stack *head_b)
{
	if (check_arg(argv))
	{
		ft_printf("Error\n");
		return (0);
	}
	head_a = fill_struct(argv, 1);
	if (!head_a)
		return (ft_printf("Error\n"), 0);
	head_b = ft_lstneb();
	if (!head_b)
	{
		free(head_a);
		return (ft_printf("Error\n"), 0);
	}
	start_sorting(head_a, head_b);
	return (0);
}
int main(int argc, char **argv)
{
	t_stack *head_a;
	t_stack *head_b;

	if (argc == 2)
	{
		argv_split(head_a, head_b, argv);
		return (0);
	} 
	if (argc > 2)
	{
		handle_mult_argv(argv, head_a, head_b);
	}
	return (0);
}
