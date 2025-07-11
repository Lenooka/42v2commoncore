/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:55:21 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 17:51:46 by olena            ###   ########.fr       */
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

void	init_mutex_forks(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL) != 0)
		{
			pthread_mutex_destroy(&philo->write);
			pthread_mutex_destroy(&philo->death);
			pthread_mutex_destroy(&philo->sim);
			destroy_back(philo, i);
			exit_free(philo, NULL, "Mutex fork init fail, init_mutex_forks");
		}
		i++;
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
	exit_free(philo, NULL, s);
}

t_table	*set_up_table(t_philo *philo, t_table *table, int i)
{
	table = malloc(sizeof(t_table) * philo->num_of_philo);
	if (!table)
		exit_just_mess("Malloc table fail, set_up_table");
	philo->ph_thread = malloc(sizeof(pthread_t) * philo->num_of_philo);
	if (!philo->ph_thread)
		exit_one(philo, table, "Malloc ph_thread fail, set_up_table");
	set_mutex(philo, table);
	while (i < philo->num_of_philo)
	{
		table[i].indx = i + 1;
		table[i].philo = philo;
		table[i].all_eaten = 0;
		table[i].num_ph = philo->num_of_philo;
		table[i].leftf = &philo->fork[i];
		table[i].rightf = &philo->fork[(i + 1) % philo->num_of_philo]; 
		if (pthread_mutex_init(&table[i].eat, NULL) != 0)
			exit_loop(philo, table, "Mutex eat init fail, set_up_table", i);
		if (pthread_mutex_init(&table[i].meals_mx, NULL) != 0)
			exit_loop(philo, table, "Mutex eat init fail, set_up_table", i);
		i++;
	}
	return (table);
}
