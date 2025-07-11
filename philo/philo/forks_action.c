/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_action.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:26:50 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 17:39:28 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	untake_forks(t_table *inst)
{
	if (inst->indx % 2)
	{
		pthread_mutex_unlock(inst->leftf);
		pthread_mutex_unlock(inst->rightf);
	}
	else
	{
		pthread_mutex_unlock(inst->rightf);
		pthread_mutex_unlock(inst->leftf);
	}
}

void	take_forks(t_table *inst)
{
	if (inst->indx % 2)
	{
		pthread_mutex_lock(inst->leftf);
		if (not_dead(inst->philo) == 1)
			return ;
		mess_out(inst, "has taken a fork", 1);
		if (not_dead(inst->philo) == 1)
			return ;
		pthread_mutex_lock(inst->rightf);
		mess_out(inst, "has taken a fork", 1);
	}
	else
	{
		pthread_mutex_lock(inst->rightf);
		if (not_dead(inst->philo) == 1)
			return ;
		mess_out(inst, "has taken a fork", 1);
		if (not_dead(inst->philo) == 1)
			return ;
		pthread_mutex_lock(inst->leftf);
		mess_out(inst, "has taken a fork", 1);		
	}
}

void	forks_action(t_table *inst, int take)
{
	if (take == 0)
		take_forks(inst);
	else
		untake_forks(inst);
}