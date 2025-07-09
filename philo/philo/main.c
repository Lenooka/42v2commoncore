/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:07:12 by oltolmac          #+#    #+#             */
/*   Updated: 2025/07/06 16:34:12 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_philo.h"

int	food_count(t_table *inst)
{
	int	count;

	pthread_mutex_lock(&inst->meals_mx);
	count = inst->all_eaten;
	pthread_mutex_unlock(&inst->meals_mx);
	return (count);
}

u_int64_t	last_meal_time(t_table *philo)
{
	u_int64_t	time;

	pthread_mutex_lock(&philo->eat);
	time = philo->last_eat;
	pthread_mutex_unlock(&philo->eat);
	return (time);
}

void	time_action(u_int64_t t)
{
	usleep(t);
}

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
	pthread_mutex_lock(&philo->death);
	if (philo->end == 1)
	{
		pthread_mutex_unlock(&philo->death);
		return (1);
	}
	pthread_mutex_unlock(&philo->death);
	return (0);
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
		mess_out(inst, "has taken a fork", 1);
		pthread_mutex_lock(inst->rightf);
		mess_out(inst, "has taken a fork", 1);
	}
	else
	{
		pthread_mutex_lock(inst->rightf);
		mess_out(inst, "has taken a fork", 1);
		pthread_mutex_lock(inst->leftf);
		mess_out(inst, "has taken a fork", 1);		
	}
}

void	forks_action(t_table *inst, int take)
{
	if (take == 0)
		take_forks(inst);
	else
		untake_forks(inst);
}

void	pass_time(u_int64_t time)
{
	u_int64_t	start_time;

	start_time = get_current_time(0);
	while (get_current_time(start_time) < time)
		usleep(500);
}

int	eat_action(t_table *inst)
{
	forks_action(inst, 0);
	pthread_mutex_lock(&inst->eat);
	inst->last_eat = get_current_time(0);
	pthread_mutex_unlock(&inst->eat);
	if (not_dead(inst->philo) == 1)
	{
		forks_action(inst, 0);
		return (-1);
	}
	mess_out(inst, "is eating", 2);
	pass_time(inst->philo->time_to_eat);
	forks_action(inst, 1);
	return (0);
	
}

void	meal_counter(t_table *inst)
{
	pthread_mutex_lock(&inst->meals_mx);
	inst->all_eaten++;
	pthread_mutex_unlock(&inst->meals_mx);
}

void	limited_meals(t_table *inst)
{
	while (food_count(inst) < inst->philo->num_of_meals && not_dead(inst->philo) == 0)
	{
		if (eat_action(inst) == -1)
			break ;
		meal_counter(inst);
		if (food_count(inst) >= inst->philo->num_of_meals)
			return ;
		if (not_dead(inst->philo) == 1)
			break ;
		mess_out(inst, "is sleeping", 3);
		pass_time(inst->philo->time_to_sleep);
		mess_out(inst, "is thinking", 4);
		if ((inst->num_ph % 2) && not_dead(inst->philo) == 0)
			pass_time(inst->philo->time_to_eat * 2 - inst->philo->time_to_sleep);
	}
}

char	*choose_color(int i)
{
	if (i == 1)
		return (KRED);
	if (i == 2)
		return (KYEL);
	if (i == 3)
		return (KGRN);
	if (i == 4)
		return (KCYN);
	if (i == 5)
		return (KMAG);
	return (KCYN);
}

void	mess_out(t_table *inst, char *mess, int c)
{
	u_int64_t time;
	char	*color;

	time = get_current_time(inst->philo->start_t);
	pthread_mutex_lock(&inst->philo->write);
	color = choose_color(c);
	printf("%s%lu %d %s\n", color, time, inst->indx, mess);
	printf("%s", KNRM);
	pthread_mutex_unlock(&inst->philo->write);
}
void	*one_philo_handler(t_table *table)
{
	pthread_mutex_lock(table->leftf);
	mess_out(table, "has taken a fork", 1);
	pthread_mutex_unlock(table->leftf);
	mess_out(table, "died", 5);
	return (NULL);
}

int	meal_count(t_table *inst)
{
	pthread_mutex_lock(&inst->meals_mx);
	inst->all_eaten++;
	pthread_mutex_unlock(&inst->meals_mx);
	
	return (0);
}

void	*ft_feast(void *ph)
{
	t_table	*inst;

	inst = (t_table *)ph;
	if (inst->num_ph == 1)
		return (one_philo_handler(inst));
	if (inst->indx % 2 == 0) //prevent deadlock and race condition
		usleep(1000);
	if (inst->philo->num_of_meals == -1)
	{
		while (not_dead(inst->philo) == 0)
		{
			if (eat_action(inst) == -1)
				break ;
			if (not_dead(inst->philo) == 1)
				break ;
			mess_out(inst, "is sleeping", 3);
			pass_time(inst->philo->time_to_sleep);
			mess_out(inst, "is thinking", 4);
			if ((inst->num_ph % 2) && not_dead(inst->philo) == 0)
				pass_time(inst->philo->time_to_eat * 2 - inst->philo->time_to_sleep);
		}
	}
	else
		limited_meals(inst);
	return (NULL);
}

void	*monitor_death(void *ph)
{
	t_philo	*philo;
	t_table	*table;
	int		i;

	philo = (t_philo *)ph;
	table = philo->table;
	while (not_dead(philo) != 1)
	{
		i = 0;
		while (i < philo->num_of_philo)
		{
			if (get_current_time((last_meal_time(&table[i]))) > (u_int64_t)philo->time_to_die)
			{
				pthread_mutex_lock(&philo->death);
				philo->end = 1;
				pthread_mutex_unlock(&philo->death);
				mess_out(&table[i], "died", 5);
				exit(1);
			}
			i++;
		}
		usleep(100);
	}
	return (NULL);
}

void	*monitor_meals(void *ph)
{
	t_philo	*philo;
	t_table	*table;
	int		i;

	philo = (t_philo *)ph;
	table = philo->table;
	if (philo->num_of_meals == -1)
		return (NULL);
	while (not_dead(philo) == 0)
	{
		i = 0;
		while (i < philo->num_of_philo)
		{
			if (food_count(&table[i]) < philo->num_of_meals)
			{
				break ;
			}
			i++;
		}
		if (i == philo->num_of_philo)
		{
			pthread_mutex_lock(&philo->death);
			philo->end = 1;
			pthread_mutex_unlock(&philo->death);
			exit(0);
		}
		usleep(100);
	}
	return (NULL);
}

int	start_feast(t_philo *philo, t_table *table)
{
	int	i;

	i = 0;
	philo->start_t = get_current_time(0);
	while (i < philo->num_of_philo)
	{
		table[i].start_time = philo->start_t;
		table[i].last_eat = philo->start_t;
		i++;
	}
	i = 0;
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
			&& pthread_create(&philo->mon_meals, NULL, &monitor_meals, (void *)philo) != 0)
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
 