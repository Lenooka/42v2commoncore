/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olena <olena@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 23:07:29 by olena             #+#    #+#             */
/*   Updated: 2024/09/04 23:08:41 by olena            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_lst;
    t_list *new_elem;

    if (!lst || !f)
        return (NULL);
    new_lst = NULL;
    while (lst)
    {
        new_elem = ft_lstnew(f(lst->content));
        if (!new_elem)
        {
            ft_lstclear(&new_lst, del);
            return (NULL);
        }
        ft_lstadd_back(&new_lst, new_elem);
        lst = lst->next;
    }
    return (new_lst);
}
