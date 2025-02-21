/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:08 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/21 17:12:45 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <unistd.h>

char	*static_str_handle(char rec)
{
	static char	*tmp;
	static char	*str;

	if (str == NULL)
	{
		str = ft_calloc(sizeof(char), 1);
		if (str == NULL)
			return (NULL);
	}
	if (rec == '\0')
		return (str = NULL);
	else
	{
		tmp = malloc(sizeof(char) * 2);
		if (!tmp)
			return (NULL);
		tmp[0] = rec;
		tmp[1] = '\0';
		str = ft_strjoin(str, tmp);
		free(tmp);
		if (!str)
			return (NULL);
	}
	return (str);
}

void	put(char *s, int len)
{
	write(1, s, len);
}

void	functuin(int signum, siginfo_t *info, void *cntx)
{
	static char	recive = 0;
	static char	num = 0;
	static char	*str;

	(void) cntx;
	if (signum == SIGUSR1)
		recive |= (1 << num);
	num++;
	if (num == 8)
	{
		if (recive == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("%s\n", str);
			free(str);
			str = NULL;
		}
		str = static_str_handle(recive);
		num = 0;
		recive = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;
	pid_t				pid;

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
