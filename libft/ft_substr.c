/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:12:01 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/04 19:22:34 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	char *sub;
	int	i;
	int x;

	sub = (char *)malloc(sizeof(char) * len + 1);
	if (!sub)
		return (NULL);
	i = start;
	x = 0;
	while (s[i] && x <= len)
	{
		sub[x] = s[i]; 
		x++;
		i++;
	}
	sub[x] = '\0';
	return (sub);
}

/*int	main()
{
	char str[] = "Hello, world!";
	printf("%s\n", ft_substr(str, 0, 100));
}*/