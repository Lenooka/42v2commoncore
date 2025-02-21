/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:00 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/21 14:43:40 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	g_sleep = 0;

void	cryption_handle(unsigned char c, int pid)
{
	int	b;

	b = 1;
	while (b <= 8)
	{
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		b++;
		g_sleep = 1;
		while (g_sleep)
			sleep(1);
		c = c >> 1;
	}
}

void	handshake_handle(int signum, siginfo_t *a, void *what)
{
	(void) what;
	(void) a;
	if (signum == SIGUSR1)
	{
		g_sleep = 0;
	}
	if (signum == SIGUSR2)
	{
		ft_printf("Message recieved\n");
		exit(1);
	}
}

void	clinet_signals_init(void)
{
	struct sigaction sa;
	
	sa.sa_sigaction = handshake_handle;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&(sa.sa_mask));
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	int pid;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 3)
		{
			ft_printf("%s\nInvalid pid", KRED);
			exit(1);
		}
		clinet_signals_init();
		int i = 0;
		while (argv[2][i])
		{
			cryption_handle(argv[2][i], pid);
			i++;
		}
		cryption_handle(argv[2][i], pid);
		return (0);
	}
	return (0);
}
