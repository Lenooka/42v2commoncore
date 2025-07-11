/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitors.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:28:01 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 14:17:56 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

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

void	to_die_force(t_philo *philo)
{
	pthread_mutex_lock(&philo->death);
	philo->end = 1;
	pthread_mutex_unlock(&philo->death);
}

void	*monitor_meals(void *ph)
{
	t_philo	*philo;
	t_table	*table;
	int		i;

	philo = (t_philo *)ph;
	table = philo->table;
	if (philo->num_of_meals == -1 || philo->num_of_philo < 1)
		return (NULL);
	if (are_we_done(philo) == 0)
	{
		while (not_dead(philo) == 0)
		{
			i = 0;
			while (i < philo->num_of_philo)
			{
				if (food_count(&table[i]) < philo->num_of_meals)
					break ;
				i++;
			}
			if (i == philo->num_of_philo)
			{
				to_die_force(philo);
				exit(0);
			}
			usleep(100);
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
	if (are_we_done(philo) == 0)
	{
		while (not_dead(philo) != 1)
		{
			i = 0;
			while (i < philo->num_of_philo)
			{
				if (get_current_time((last_meal_time(&table[i]))) > (u_int64_t)philo->time_to_die)
				{
					to_die_force(philo);
					mess_out(&table[i], "died", 5);
					exit(1);
				}
				i++;
			}
			usleep(100);
		}
	}
	return (NULL);
}
