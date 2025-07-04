/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:07:12 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/04 20:23:19 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	check_meals(char **argv)
{
	if (ft_atoi(argv[5]) < 0)
	{
		printf("%s", KRED);
		printf("Philosophers can't eat absence of meals!\n");
		printf("%s", KNRM);
		printf("Ammount of meals : %s\n", argv[5]);
		exit(1);
	}
	return (0);
}

void	checkfill_arguments(t_philo *phil, char **argv, int argc)
{
	int	i;
	int	j;

	j = 1;
	if (argc == 6)
		check_meals(argv);
	while (argv[j])
	{
		i = 0;
		while (argv[j][i])
		{
			if (argv[j][i] < '0' || argv[j][i] > '9')
			{
				printf("%sInvalid argument : %s\n", KRED, argv[j]);
				printf("%s", KNRM);
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

int	not_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->death);
	if (philo->end)
	{
		pthread_mutex_unlock(philo->death);
		return (0);
	}
	pthread_mutex_unlock(philo->death);
	return (1);
}

void	untake_forks(t_table *inst)
{
	if (inst->indx % 2)
	{
		pthread_mutex_unlock(inst->leftf);
		pthread_mutex_unlock(inst->rightf);
	}
	else
	{
		pthread_mutex_unlock(inst->rightf);
		pthread_mutex_unlock(inst->leftf);
	}
}

void	take_forks(t_table *inst)
{
	if (inst->indx % 2)
	{
		pthread_mutex_lock(inst->leftf);
		mess_out(inst, "has taken a fork");
		pthread_mutex_lock(inst->rightf);
		mess_out(inst, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(inst->rightf);
		mess_out(inst, "has taken a fork");
		pthread_mutex_lock(inst->leftf);
		mess_out(inst, "has taken a fork");		
	}
}

void	forks_action(t_table *inst, int take)
{
	if (take == 0)
		take_forks(inst);
	else
		untake_forks(inst);
}

int	eat_action(t_table *inst)
{
	forks_action(inst, 0);
	mess_out(inst, "is eating");
	inst->last_eat = get_current_time(inst->start_time);
	if (!not_dead(inst->philo))
	{
		forks_action(inst, 0);
		return (1);
	}
	usleep(inst->philo->time_to_eat);
	forks_action(inst, 1);
	return (0);
	
}

void	limited_meals(t_table *inst)
{
	while (food_count(inst) < inst->philo->num_of_meals && not_dead(inst->philo))
	{
		if (eat_action(inst) == -1)
			break ;
		if (meal_counter(inst) && !not_dead(inst->philo))
			break ;
		mess_out(inst, "is sleeping");
		time_action(inst->philo->time_to_sleep);
		mess_out(inst, "is thinking");
		if ((inst->num_ph % 2) && not_dead(inst->philo))
			pass_time(inst->philo->time_to_eat * 2 - inst->philo->time_to_sleep);
	}
}

char	*choose_color(int philo_i)
{
	if (philo_i % 4)
		return (KCYN);
	if (philo_i % 3)
		return (KBLU);
	if (philo_i % 2)
		return (KRED);
	return (KGRN);
}
void	mess_out(t_table *inst, char *mess)
{
	u_int64_t time;
	char	*color;

	time = get_current_time(inst->philo->start_t);
	pthread_mutex_lock(inst->philo->write);
	color = choose_color(inst->indx);
	printf("%s[%ldu] philosopher N°%d %s\n", color, time, inst->indx, mess);
	pthread_mutex_unlock(inst->philo->write);
}
void	one_philo_handler(t_table *table)
{
	pthread_mutex_lock(table->leftf);
	mess_out(table, "has taken a fork");
	pthread_mutex_unlock(table->leftf);
	return (NULL);
}

int	meal_count(t_table *inst)
{
	pthread_mutex_lock(&inst->meals_mx);
	inst->all_eaten++;
	pthread_mutex_unlock(&inst->meals_mx);
}

void	time_action(u_int64_t t)
{
	usleep(t);
}

void	ft_feast(void *ph)
{
	t_table	*inst;

	inst = (t_table *)ph;
	if (inst->num_ph == 1)
		return (one_philo_handler(inst));
	if (inst->indx % 2 == 0) //prevent deadlock and race condition
		usleep(50);
	if (inst->philo->num_of_meals == -1)
	{
		while (not_dead(inst->philo))
		{
		if (eat_action(inst) == -1)
			break ;
		if (meal_counter(inst) && !not_dead(inst->philo))
			break ;
		mess_out(inst, "is sleeping");
		time_action(inst->philo->time_to_sleep);
		mess_out(inst, "is thinking");
		if ((inst->num_ph % 2) && not_dead(inst->philo))
			time_action(inst->philo->time_to_eat * 2 - inst->philo->time_to_sleep);
		}
	}
	else
		limited_meals(inst);
}


int	start_feast(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	philo->start_t = get_current_time(0);
	while (i < philo->num_of_philo)
	{
		table[i].last_eat = philo->start_t;
		i++;
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_create(&philo->ph_thread[i], NULL, &ft_feast, &table[i]) != 0)
		{
			exit_free(philo, table, "Error in pthread_create");
		}
		i++;
	}
	if (pthread_create(&philo->mon_death, NULL, &monitor_death, (void *)philo) != 0
		|| pthread_create(&philo->mon_meals, NULL, &monitor_meals, (void *)philo) != 0
		|| (philo->num_of_meals > 0 && philo->num_of_philo > 1
			&& pthread_create(&philo->mon_meals, NULL, &monitor_meals, (void *)philo) != 0))
	{
		exit_free(philo, table, "Error in pthread_create for monitor_death");
	}
	i = 0;
	while (i < philo->num_of_philo)
	{
		if (pthread_join(philo->ph_thread[i], NULL) != 0)
		{
			exit_free(philo, table, "Error in pthread_join");
		}
		i++;
	}
	return (0);
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
		exit_just_mess("Wrong amount of arguments!");
	checkfill_arguments(&philo, argv, argc);
	philo.table = set_up_table(&philo, philo.table);
	if (start_feast(&philo, philo.table) == -1)
	{
		exit_free(&philo, philo.table, "Error in start_feast");
	}
	free(philo.table);
	return (0);
}
 