/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:08 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/11 18:20:15 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <unistd.h>


void	make_s(void)
{
	
}

void	functuin(int signum, siginfo_t *a, void *what)
{
	if (signum == 10)
	{
		
	}
	else if (signum == 12)
	{	

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