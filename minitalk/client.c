/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:00 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/21 17:09:43 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

int	g_sleep = 0;

void	cryption_handle(unsigned char c, int pid)
{
	int				bit;

	bit = 8;
	while (bit--)
	{
		g_sleep = 1;
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		while (g_sleep == 1)
			sleep(1);
		c >>= 1;
	}
}

void	handshake_handle(int signum, siginfo_t *info, void *cntx)
{
	(void) info;
	(void) cntx;
	if (signum == SIGUSR1)
	{
		g_sleep = 0;
	}
	if (signum == SIGUSR2)
	{
		write(1, "Message received\n", 17);
	}
}

void	clinet_signals_init(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handshake_handle;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigemptyset(&(sa.sa_mask));
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (pid < 3)
		{
			ft_printf("%s\nInvalid pid", KRED);
			exit(1);
		}
		clinet_signals_init();
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
