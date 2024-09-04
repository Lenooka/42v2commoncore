/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:24:12 by olena             #+#    #+#             */
/*   Updated: 2024/09/03 22:38:33 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>


void    *ft_memmove(void *dest, const void *src, size_t n)
{
    unsigned char	*dp;
    unsigned char	*sp;

    if (!dest && !src)
        return (NULL);
    dp = (unsigned char *)dest;
    sp = (unsigned char *)src;
    if (dp < sp)
        while (n--)
            *dp++ = *sp++;
    else
    {
        dp += n;
        sp += n;
        while (n--)
            *--dp = *--sp;
    }
    return (dest);
}

/*int main() {
    char str[] = "Hello, world!";
    char buffer[20];

    ft_memmove(buffer, str + 7, 6);
    printf("ftmemmove: %s\n", buffer);
    memmove(buffer, str + 7, 6);
    printf("memmove: %s\n", buffer);

    return 0;
}*/