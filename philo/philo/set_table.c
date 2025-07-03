/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:55:21 by oltolmac          #+#    #+#             */
/*   Updated: 2025/06/27 18:27:50 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	init_mutex_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL) != 0)
		{
			exit_free(philo, NULL, "Mutex fork init fail, init_mutex_forks");
		}
		i++;
	}
}

t_table	*set_up_table(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	philo->ph_thread = malloc(sizeof(pthread_t) * philo->num_of_philo);
	if (!philo->ph_thread)
		exit_free(philo, table, "Malloc ph_thread fail, set_up_table");
	init_mutex_forks(philo);
	philo->end = 0;
	table = malloc(sizeof(t_table) * philo->num_of_philo);
	if (!table)
		exit_just_mess("Malloc table fail, set_up_table");
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
	if (!philo->fork)
		exit_free(philo, table, "Malloc fork fail, set_up_table");
	if (pthread_mutex_init(philo->write, NULL) != 0)
		exit_free(philo, table, "Mutex write init fail, set_up_table");
	if (pthread_mutex_init(philo->death, NULL) != 0)
		exit_free(philo, table, "Mutex death init fail, set_up_table");
	while (i < philo->num_of_philo)
	{
		table[i].indx = i + 1;
		table[i].philo = philo;
		table[i].all_eaten = 0;
		table[i].num_ph = philo->num_of_philo;
		table[i].leftf = &philo->fork[i];
		table[i].rightf = &philo->fork[(i + 1) % philo->num_of_philo]; 
		if (pthread_mutex_init(&table[i].eat, NULL) != 0)
			exit_free(philo, table, "Mutex eat init fail, set_up_table");
		if (pthread_mutex_init(&table[i].meals_mx, NULL) != 0)
			exit_free(philo, table, "Mutex meals_mx init fail, set_up_table");
		i++;
	}
	return (table);
}
