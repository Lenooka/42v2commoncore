/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:34:58 by oltolmac          #+#    #+#             */
/*   Updated: 2025/04/18 14:55:50 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	error_arguments(char *s, char *mess)
{
	printf("Invalid argument [%s]!", s);
	printf("%s%s!\n", mess, KRED);
	printf("%s\n", KNRM);
	exit(1);
	return (1);
}

int	fill_struct(t_philo *data, char **s)
{
	data->num_of_philo = ft_atoi(s[1]);
	if (data->num_of_philo < 1)
		return (error_arguments(s[1], "There is no life without philosophers"));
	data->time_to_die = ft_atoi(s[2]);
	if (data->time_to_die < 0)
		return (error_arguments(s[2],
				"We all eventually die, even philosophers\n"));
	data->time_to_eat = ft_atoi(s[3]);
	if (data->time_to_eat < 0)
		return (error_arguments(s[3], "Philosophers need time to eat too"));
	data->time_to_sleep = ft_atoi(s[4]);
	if (data->time_to_sleep < 0)
		return (error_arguments(s[4], "Philosophers need to sleep too\n"));
	if (s[5])
		data->num_of_meals = ft_atoi(s[5]);
	else
		data->num_of_meals = -1;
	if (data->num_of_meals == 0)
		return (error_arguments(s[5],
				"Philosophers need to eat at least once"));
	return (0);
}