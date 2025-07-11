/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_start.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:31:41 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 14:27:26 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	join_threads(t_philo *philo, t_table *table)
{
	int	i;
	
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_join(philo->ph_thread[i], NULL) != 0)
		{
			exit_free(philo, table, "Error in pthread_join");
		}
		i++;
	}
}


void	time_and_wait_init(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	philo->start_t = get_current_time(0);
	philo->start = 0;
	while (i < philo->num_of_philo)
	{
		table[i].start_time = philo->start_t;
		table[i].last_eat = philo->start_t;
		i++;
	}
}

void	free_back(t_philo *philo, int i)
{
	while(*philo->ph_thread && i >= 0)
	{
		free(philo->ph_thread);
		philo->ph_thread++;
		i--;
	}
}

void	sho(t_philo *philo)
{
	pthread_mutex_lock(&philo->sim);
	philo->start = 1;
	pthread_mutex_unlock(&philo->sim);	
	
}

int	start_feast(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	time_and_wait_init(philo, table);
	while (i < philo->num_of_philo)
	{
		if (pthread_create(&philo->ph_thread[i], NULL, &ft_feast, &table[i]) != 0)
		{
			full_exit(philo, table, "Error in pthread_create");
		}
		i++;
	}
	sho(philo);
	if (pthread_create(&philo->mon_death, NULL, &monitor_death, (void *)philo) != 0
		&& pthread_create(&philo->mon_meals, NULL, &monitor_meals, (void *)philo) != 0)
	{
		full_exit(philo, table, "Error in pthread_create for monitor_death");
	}
	join_threads(philo, table);
	return (0);
}
