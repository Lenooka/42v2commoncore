		if (head_a->content > head_a->next->content)
		{
			head_b->content = head_a->content;
			head_a->content = head_a->next->content;
			head_a->next->content = head_b->content;
		}


		void	swap_b(t_stack *stack)
{
	int s;

	s = stack->content;
	stack->content = stack->next->content;
	stack->next->content = s;
	ft_printf("sb\n");
}

void	swap_a(t_stack *stack)
{
	int s;

	s = stack->content;
	stack->content = stack->next->content;
	stack->next->content = s;
	ft_printf("sa\n");
}