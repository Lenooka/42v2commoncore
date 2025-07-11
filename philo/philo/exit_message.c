/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:58:10 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/11 14:22:21 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

void	ft_puterror_endl(char *s, int fd)
{
	char *red;
	char *nrm;

	red = KRED;
	nrm = KNRM;
	if (!s)
		return ;
	write(fd, red, ft_strlen(red));
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
	write(fd, nrm, ft_strlen(nrm));

}

void    free_table(t_table *table, t_philo *philo)
{
    int    i = 0;

    if (!table)
        return;

    while (i < philo->num_of_philo)
    {
        pthread_mutex_destroy(&table[i].eat);
        pthread_mutex_destroy(&table[i].meals_mx);
        i++;
    }
    free(table);
}

void    full_exit(t_philo *philo, t_table *table, char *mess)
{
    if (philo->ph_thread)
        free(philo->ph_thread);
    if (philo->fork)
        free(philo->fork);
    if (table)
        free_table(table, philo);
    pthread_mutex_destroy(&philo->write);
   // pthread_mutex_destroy(&philo->death);
    pthread_mutex_destroy(&philo->sim);
    ft_puterror_endl(mess, 2);
    exit(0);
}


void	exit_free(t_philo *philo, t_table *table, char *mess)
{
	if (philo->ph_thread)
		free(philo->ph_thread);
	if (philo->fork)
		free(philo->fork);
	if (table)
		free(table);
	ft_puterror_endl(mess, 2);
	exit(1);
}

int	ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while(*s)
	{
		i++;
		s++;
	}
	return (i);
}


void	exit_just_mess(char *str)
{
	ft_puterror_endl(str, 2);
	exit(1);
}