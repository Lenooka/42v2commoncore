/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:20:43 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/25 17:21:55 by oltolmac         ###   ########.fr       */
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
				return (1);
			}
			i++;
		}
		j++;
	}
	if (!check_atoi(argv));
		exit(1);
	fill_struct(phil, argv);
	return (0);
}

void	exit_just_mess(char *str)
{
	printf("%s%s\n", KRED, str);
	printf("%s", KNRM);
	exit(1);
}
int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 || argc != 6)
		exit_just_mess("Wrong amount of arguments");
	checkfill_arguments(&philo, argv, argc);
		
	return (0);
}