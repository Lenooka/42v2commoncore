/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:28:01 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 17:25:18 by oltolmac         ###   ########.fr       */
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

	philo = (t_philo *)ph;
	table = philo->table;
	if (philo->num_of_meals == -1)
		return (NULL);
	while (not_dead(philo) == 0)
	{
		i = 0;
		while (i < philo->num_of_philo)
		{
			if (food_count(&table[i]) < philo->num_of_meals)
				break ;
			i++;
			if (i == philo->num_of_philo)
			{
				to_die_force(philo);
				return (NULL);

			}
			usleep(1000);
		}
	}
	return (NULL);
}


void	*monitor_death(void *ph)
{
	t_philo	*philo;
	t_table	*table;
	int		i;

	philo = (t_philo *)ph;
	table = philo->table;
	while (not_dead(philo) != 1)
		{
			i = 0;
			while (i < philo->num_of_philo)
			{
				if (get_current_time((last_meal_time(&table[i]))) > (u_int64_t)philo->time_to_die)
				{
					pthread_mutex_lock(&philo->death);
					philo->end = 1;
					pthread_mutex_unlock(&philo->death);
					mess_out(&table[i], "died", 5);
					return NULL;// full_exit(philo, table, NULL);
				}
				i++;
			}
		usleep(1000);
	}
	return (NULL);
}