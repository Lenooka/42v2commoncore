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

t_list_a	*fill_struct(char **argv)
{
	int	i;
	t_list_a *head;
	t_list_a *node;

	i = 2;
	head = ft_lstne((int)atoi(argv[1]));
	node = head;
	while (argv[i])
	{
		node->next = ft_lstne((int)atoi(argv[i]));
		node = node->next;
		i++;
	}
	return (head);
}

int main(int argc, char **argv)
{
	t_list_a *head_a;
	t_list_a *head_b;

	if (argc > 2)
		head_a = fill_struct(argv);
	head_b = ft_lstne(0);
	if (head_a->content > head_a->next->content)
	{
		head_b->content = head_a->content;
		head_a->content = head_a->next->content;
		head_a->next->content = head_b->content;
	}
	printf("head_a->content = %d\n", head_a->content);
	printf("head_a->next->content = %d\n", head_a->next->content);
	return 0;
}