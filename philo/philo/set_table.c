/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:55:21 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 20:16:33 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	destroy_back(t_philo *philo, int i)
{
	int	a;

	a = 0;
	while (a != i)
	{
		pthread_mutex_destroy(&philo->fork[a]);
		a++;
	}
}

void	set_mutex(t_philo *philo, t_table *table)
{
	philo->end = 0;
	philo->fork = NULL;
	if (pthread_mutex_init(&philo->write, NULL) != 0)
		exit_free(philo, table, "Mutex write init fail, set_up_table");
	if (pthread_mutex_init(&philo->sim, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->write);
		exit_free(philo, table, "Mutex write init fail, set_up_table");
	}
	if (pthread_mutex_init(&philo->death, NULL) != 0)
	{
		pthread_mutex_destroy(&philo->write);
		pthread_mutex_destroy(&philo->death);
		exit_free(philo, table, "Mutex death init fail, set_up_table");
	}
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
	if (!philo->fork)
	{
		pthread_mutex_destroy(&philo->write);
		pthread_mutex_destroy(&philo->death);
		pthread_mutex_destroy(&philo->sim);
		exit_free(philo, table, "Malloc fork fail, set_up_table");
	}
	init_mutex_forks(philo);
}

void	exit_one(t_philo *philo, t_table *table, char *s)
{
	free(table);
	(void)philo;
	exit_just_mess(s);
}

void	exit_loop(t_philo *philo, t_table *table, char *s, int i)
{
	pthread_mutex_destroy(&philo->write);
	pthread_mutex_destroy(&philo->death);
	pthread_mutex_destroy(&philo->sim);
	while (i >= 0)
	{
		pthread_mutex_destroy(&table[i].eat);
		pthread_mutex_destroy(&table[i].meals_mx);
		i--;
	}
	exit_free(philo, table, s);
}

t_table	*set_up_table(t_philo *philo, int i)
{
	philo->table = malloc(sizeof(t_table) * philo->num_of_philo);
	if (!philo->table)
		exit_just_mess("Malloc table fail, set_up_table");
	philo->ph = malloc(sizeof(pthread_t) * philo->num_of_philo);
	if (!philo->ph)
		exit_one(philo, philo->table, "Malloc ph_thread fail, set_up_table");
	set_mutex(philo, philo->table);
	while (i < philo->num_of_philo)
	{
		philo->table[i].indx = i + 1;
		philo->table[i].philo = philo;
		philo->table[i].done_eating = 0;
		philo->table[i].all_eaten = 0;
		philo->table[i].num_ph = philo->num_of_philo;
		philo->table[i].leftf = &philo->fork[i];
		philo->table[i].rightf = &philo->fork[(i + 1) % philo->num_of_philo];
		if (pthread_mutex_init(&philo->table[i].eat, NULL) != 0)
			exit_loop(philo, philo->table, "Mutex eat init fail", i);
		if (pthread_mutex_init(&philo->table[i].meals_mx, NULL) != 0)
			exit_loop(philo, philo->table, "Mutex meals init fail", i);
		if (pthread_mutex_init(&philo->table[i].done, NULL) != 0)
			exit_loop(philo, philo->table, "Mutex done init fail", i);
		i++;
	}
	return (philo->table);
}
