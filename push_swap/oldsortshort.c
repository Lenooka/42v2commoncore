#include "ft_push_swap.h"

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

void	posofmin(t_stacks *stacks, int middlensa)
{
	if (stacks->min_indx < middlensa)
	{
		ra(stacks, 0);
	}
	else if (stacks->min_indx >= middlensa)
	{
		rra(stacks, 0);
	}
}

void	shortsort(t_stacks *stacks)
{
	int	middlen;

	while (stacks->lensa != 1 && issorted(stacks))
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
			posofmin(stacks, middlen);
		}
	}
	while (stacks->lensb > 0)
		pa(stacks);
}