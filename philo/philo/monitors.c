/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:28:01 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 18:19:39 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	to_die_force(t_philo *philo)
{
	pthread_mutex_lock(&philo->death);
	philo->end = 1;
	pthread_mutex_unlock(&philo->death);
}

int	are_we_done(t_philo *data)
{
	pthread_mutex_lock(&data->sim);
	if (data->start == 0)
	{
		pthread_mutex_unlock(&data->sim);
		return (1);
	}
	pthread_mutex_unlock(&data->sim);
	return (0);
}

void	*monitor_meals(void *ph)
{
	t_philo	*philo;
	t_table	*table;
	int		i;
	int		all_done;

	philo = (t_philo *)ph;
	table = philo->table;
	if (philo->num_of_meals == -1)
		return (NULL);
	while (not_dead(philo) == 0)
	{
		all_done = 1;
		i = 0;
		while (i < philo->num_of_philo)
		{
			if (table[i].done_eating == 0)
			{
				all_done = 0;
				break;
			}
			i++;
		}
		if (all_done)
		{
			to_die_force(philo);
			return (NULL);
		}
		usleep(1000);
	}
	return (NULL);
}




void	*monitor_death(void *ph)
{
	t_philo	*philo = (t_philo *)ph;
	t_table	*table = philo->table;
	int		i;

	while (1)
	{
		if (not_dead(philo) == 1)
			return (NULL);
		i = 0;
		while (i < philo->num_of_philo)
		{
			// Skip this philosopher if they've eaten enough
if (philo->num_of_meals != -1 && table[i].done_eating == 1)
{
	i++;
	continue;
}
			if (get_current_time(last_meal_time(&table[i])) > (u_int64_t)philo->time_to_die)
			{
				pthread_mutex_lock(&philo->death);
				if (philo->end == 0)
				{
					philo->end = 1;
					pthread_mutex_unlock(&philo->death);
					mess_out(&table[i], "died", 5);
				}
				else
					pthread_mutex_unlock(&philo->death);
				return (NULL);
			}
			i++;
		}
		usleep(1000);
	}
}
