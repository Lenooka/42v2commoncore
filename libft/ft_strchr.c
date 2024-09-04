/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:17:06 by olena             #+#    #+#             */
/*   Updated: 2024/09/04 23:19:25 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	size_t i;

	if (!s)
		return (NULL);
	i = 0;
	if (c == '\0')
        return ((char *)s + ft_strlen(s));
	while (s[i])
    {
        if (s[i] == c)
            return ((char *)s + i);
        i++;
    }
	return (NULL);	
}