		if (head_a->content > head_a->next->content)
		{
			head_b->content = head_a->content;
			head_a->content = head_a->next->content;
			head_a->next->content = head_b->content;
		}