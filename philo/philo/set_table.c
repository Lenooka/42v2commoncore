/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_table.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:55:21 by oltolmac          #+#    #+#             */
/*   Updated: 2025/04/19 15:51:44 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

t_table	*set_up_table(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	table = malloc(sizeof(t_table) * philo->num_of_philo);
	if (!table)
		exit_just_mess("Malloc table fail, set_up_table");
	philo->fork = malloc(sizeof(pthread_mutex_t) * philo->num_of_philo);
	if (!philo->fork)
		exit_free(philo, table, "Malloc fork fail, set_up_table");
	while (i < philo->num_of_philo)
	{
		table[i].indx = i + 1;
		table[i].philo = philo;
		table[i].meals = 0;
		table[i].rightf = &philo->fork;
		table[i].leftf = //division here?0
		
		
		i++;
	}
	return (table);
}