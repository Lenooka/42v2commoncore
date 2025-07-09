/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_message.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 14:58:10 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/09 18:19:04 by oltolmac         ###   ########.fr       */
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