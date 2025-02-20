/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:08 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/20 16:37:34 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <unistd.h>

char	*staic_alloc(char rec, int res)
{
	static	char str[131072];
	static	int i = 0;

	if (res)
	{
		i = 0;
		// ft_memset(str, 0, ft_strlen(str));
		str[0] = '\0';
		return (str);
	}
	if (i == 131072)
	{
		i = 0;
		str[0] = '\0';
		ft_putstr_fd("Error: message is too long\n", 1);
		exit(1);
	}
	str[i] = rec;
	i++;
	str[i] = '\0';
	return (str);
}

void	put(char *s, int len)
{
	write(1, s, len);
}

void	functuin(int signum, siginfo_t *info, void *cntx)
{
	static	char	recive = 0;
	static	char	num = 0;
	static	char	*str;

	(void) cntx;
	if (signum == SIGUSR1)
		 recive |= (1 << num);
	num++;
	if (num == 8)
	{
		if (recive == '\0')
		{
			ft_putstr_fd(str, 1);
			//put(str, ft_strlen(str));
			str = staic_alloc(0, 1);
			kill(info->si_pid, SIGUSR2);
		}
		else
			str = staic_alloc(recive, 0);
		num = 0;
		recive = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main()
{
	struct sigaction sa;
	pid_t pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_sigaction = functuin;
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sigemptyset(&(sa.sa_mask));
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		sleep(1);
	}	
	return (0);
}