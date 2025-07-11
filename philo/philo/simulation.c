/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:32:18 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 17:26:48 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	*one_philo_handler(t_table *table)
{
	pthread_mutex_lock(table->leftf);
	mess_out(table, "has taken a fork", 1);
	pthread_mutex_unlock(table->leftf);
	pthread_mutex_lock(&table->philo->death);
	table->philo->end = 1;
	pthread_mutex_unlock(&table->philo->death);
	mess_out(table, "died", 5);
	return (NULL);
}


//		if ((inst->num_ph % 2) && not_dead(inst->philo) == 0)
//	pass_time(inst->philo->time_to_eat * 2 - inst->philo->time_to_sleep);
// 			u_int64_t time_since_meal = get_current_time(0) - last_meal_time(inst);
// if (time_since_meal + inst->philo->time_to_eat < (u_int64_t)inst->philo->time_to_die)
// {
// 	mess_out(inst, "is thinking", 4);
// 	if ((inst->num_ph % 2) && not_dead(inst->philo) == 0)
// 		pass_time(inst->philo->time_to_eat * 2 - inst->philo->time_to_sleep);
// }




void	*ft_feast(void *ph)
{
	t_table	*inst;

	inst = (t_table *)ph;
	wait_for_creation(inst->philo);
	if (inst->num_ph == 1)
		return (one_philo_handler(inst));
	if (inst->indx % 2 == 0) //prevent deadlock and race condition
		usleep(50);
	if (inst->philo->num_of_meals == -1)
	{
		while (not_dead(inst->philo) == 0)
		{
			if (eat_action(inst) == -1)
				break ;
			if (not_dead(inst->philo) == 1)
				break ;
			mess_out(inst, "is sleeping", 3);
			pass_time(inst->philo->time_to_sleep);
			ft_think(inst);
		}
	}
	else
		limited_meals(inst);
	return (NULL);
}
