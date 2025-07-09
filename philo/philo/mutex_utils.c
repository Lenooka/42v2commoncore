/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 14:29:59 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/09 18:52:54 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	not_dead(t_philo *philo)
{
	int	r;

	pthread_mutex_lock(&philo->death);
	r = philo->end;
	pthread_mutex_unlock(&philo->death);
	return (r);
}

void	wait_for_creation(t_philo *philo)
{
	pthread_mutex_lock(&philo->sim);
	while (1)
	{
		if (philo->start == 1)
			break ;
	}
	pthread_mutex_unlock(&philo->sim);
}