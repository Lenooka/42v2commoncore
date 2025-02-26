/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:20:43 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/26 19:32:41 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	check_meals(int argc, char **argv)
{
	if (ft_atoi(argv[5]) < 0)
	{
		printf("Philosophers can't eat absence of meals!\n");
		printf("Ammount of meals : %s\n", argv[5]);
		return (1);
	}
	return (0);
}

void	checkfill_arguments(t_philo *phil, char **argv, int argc)
{
	int	i;
	int	j;

	j = 1;
	if (argc == 6)
		check_meals(argc, argv);
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				printf("Invalid argument : %s\n", argv[j]);
				exit(1);	
			}
			i++;
		}
		j++;
	}
	if (!check_atoi(argv))
		exit(1);
	fill_struct(phil, argv);
}

void	exit_just_mess(char *str)
{
	printf("%s%s\n", KRED, str);
	printf("%s", KNRM);
	exit(1);
}

void	set_up_table(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	while (i < philo->num_of_philo)
	{
		table[i].fork
		i++;
	}
	
}

	// 1 philo.num_of_philo);
	// 2 philo.time_to_die);
	// 3 philo.time_to_eat);
	// 4 philo.time_to_sleep);
	// 5 philo.num_of_meals);
	
int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		exit_just_mess("Wrong amount of arguments");
	checkfill_arguments(&philo, argv, argc);
	set_up_table(&philo, philo.table);
	return (0);
}