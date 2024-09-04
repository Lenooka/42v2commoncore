/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 19:04:20 by oltolmac          #+#    #+#             */
/*   Updated: 2024/09/05 00:18:56 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strrchr(const char *s, int c)
{
	int i;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	if (c == '\0')
		return ((char *)s + i);
	while (i >= 0)
	{
		if (s[i] == c)
			return ((char *)s + i);
		i--;
	}
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