/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:21:20 by oltolmac          #+#    #+#             */
/*   Updated: 2025/04/18 15:04:26 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <stddef.h>
# include <unistd.h>
# include "limits.h"
# include <sys/time.h>
# include <sys/types.h>
# include <stdlib.h>
# define MAX_INT 2147483647
# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"


typedef	struct s_table
{
	pthread_t	philos;
	int			indx;
	pthread_mutex_t	*fork;
	struct s_philo *philo;
	
	
} t_table;
typedef	struct s_philo
{
	int	time_to_die;
	int	num_of_philo;
	int	time_to_sleep;
	int	time_to_eat;
	int	num_of_meals;
	t_table	*table;
	
} t_philo;

int	check_atoi(char **argv);
int	ft_atoi(const char *str);
int	fill_struct(t_philo *data, char **s);
t_table	*set_up_table(t_philo *philo, t_table *table);
void	exit_just_mess(char *str);



#endif