/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 14:22:00 by oltolmac          #+#    #+#             */
/*   Updated: 2025/02/16 17:35:26 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

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
		c = c >> 1;
		b++;
		usleep(100);
	}
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
		int i = 0;
		while (argv[2][i])
		{
			cryption_handle(argv[2][i], pid);
			i++;
		}
		cryption_handle(argv[2][i], pid);


	return (0);
	}
}
