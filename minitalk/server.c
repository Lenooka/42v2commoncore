/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:08 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/17 19:15:52 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <unistd.h>

char	*staic_alloc(char rec, int i)
{
	static	char str[2097152];

	if (rec != '\0')
	{
		str[i] = rec;
	}
	return (str);
}

void	put(char *s, int len)
{
	write(1, s, len);
}

void	functuin(int signum, siginfo_t *a, void *what)
{
	static	char	recive = 0;
	static	char	num = 0;
	static	char	*str;
	static int i = 0;

	(void) what;
	if (signum == 10)
		recive = recive + (1 << num);
	num++;
	if (num == 8)
	{
		if (recive == '\0')
		{
			// ft_putstr_fd(str, 1);
			put(str, i);
			i = 0;
			kill(a->si_pid, SIGUSR2);
		}
		else
		{
			str = staic_alloc(recive, i);
			i++;
		}
		num = 0;
		recive = 0;
	}
	kill(a->si_pid, SIGUSR1);
}

int	main()
{
	struct sigaction sa;
	__pid_t pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_sigaction = functuin;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&(sa.sa_mask));
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		usleep(1);
	}	
	return (0);
}