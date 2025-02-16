/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:08 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/16 17:33:23 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <unistd.h>


void	functuin(int signum, siginfo_t *a, void *what)
{
	static	char	recive = 0;
	static	char	num = 0;

	(void) what;
	(void) a;
	if (signum == 10)
		recive += 1 << num;
	num++;
	if (num == 8)
	{
		if (recive == '\0')
		{
			kill(a->si_pid, SIGUSR2);
			printf("END\n");
		}
		else
		{
			ft_putchar_fd(recive, 1);
		num = 0;
		recive = 0;
		}
	}
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