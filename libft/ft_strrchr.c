/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oltolmac <oltolmac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:04:20 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/09 20:15:41 by oltolmac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i > 0)
	{
		if (s[i] == (char)c && i >= 0)
			return ((char *)s + i);
		i--;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)s);
	return (NULL);
}

/*int main ()
{
  char str[] = "This is a sample string";
  char * pch;
  pch= ft_strrchr(str,'s');
  printf ("Last occurence of 's' found at %ld \n",pch-str+1);
  return 0;
}*/