/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:07:12 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/09 18:23:40 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

// 1 philo.num_of_philo);
	// 2 philo.time_to_die);
	// 3 philo.time_to_eat);
	// 4 philo.time_to_sleep);
	// 5 philo.num_of_meals);
	
int	main(int argc, char **argv)
{
	t_philo	philo;

	if (argc != 5 && argc != 6)
		exit_just_mess("Wrong amount of arguments!");
	checkfill_arguments(&philo, argv, argc);
	philo.table = set_up_table(&philo, philo.table, 0);
	if (start_feast(&philo, philo.table) == -1)
	{
		exit_free(&philo, philo.table, "Error in start_feast");
	}
	return (0);
}
 