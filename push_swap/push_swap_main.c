#include "ft_push_swap.h"

static t_list_a	*ft_lstne(int content)
{
	t_list_a	*new;

	new = (t_list_a *)malloc(sizeof(t_list_a));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list_a	*fill_struct(char **argv, int t)
{
	int	i;
	int j;
	t_list_a *head;
	t_list_a *node;

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

int	stack_a_print(t_list_a *head_a)
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

int	elem_count(t_list_a *a)
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

void	swap(t_list_a *stack, t_list_a *stackn, int ind)
{
	int s;

	s = stack->content;
	stack->content = stackn->content;
	stackn->content = s;
	if (!ind)
		ft_printf("sa\n");
	else
		ft_printf("sb\n");

}

void	sort_three(t_list_a *a)
{
	int i;
	int temp;
	t_list_a *head;

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
				swap(a, a->next, A); //SWAPS WHATEVER I GIVE BUT NOT JUST FIRST TWO ELEM LOGIC WRONG
			}
			a = a->next;
		}
		i++;
	}
}

void	start_sorting(t_list_a *head_a, t_list_a *head_b)
{
	int	elem_am;

	elem_am = elem_count(head_a);
	sort_three(head_a);
}

int	argv_split(t_list_a *head_a, t_list_a *head_b, char **argv)
{
	char	**argv_split;

	argv_split = ft_split(argv[1], ' ');
	if (!argv_split)
	{			
		ft_printf("Malloc fail in split!\n");
		return (0);
	}
	if (check_arg(argv_split))
	{
		ft_printf("Invalid characters in argument!\n");
		return (0);
	}
	head_a = fill_struct(argv_split, 0);
	head_b = ft_lstne(0);
	start_sorting(head_a, head_b);
	free_arr(argv_split);
	return (0);
}

int main(int argc, char **argv)
{
	t_list_a *head_a;
	t_list_a *head_b;

	if (argc == 2)
	{
		argv_split(head_a, head_b, argv);
		return (0);
	}
	if (argc > 2)
	{
		if (check_arg(argv))
		{
			ft_printf("Invalid characters in arguments!\n");
			return (0);
		}
		head_a = fill_struct(argv, 1);
		head_b = ft_lstne(0);
		start_sorting(head_a, head_b);
	}
	return 0;
}
