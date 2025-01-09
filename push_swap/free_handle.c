/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 07:23:24 by oltolmac          #+#    #+#             */
/*   Updated: 2025/01/09 17:26:38 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	free_handle(t_stacks *s)
{
	if (s->arg_s != NULL)
		f_a(s->arg_s);
	free(s->stacka);
	free(s->stackb);
	free(s);
	exit(1);
}

void	f_a(char **str)
{
	int	a;

	a = 0;
	if (!str)
		return ;
	while (str[a] != NULL)
	{
		free(str[a]);
		a++;
	}
	free(str);
}
