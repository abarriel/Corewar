/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 01:13:57 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/12 03:47:40 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *tmp;

	new = NULL;
	if (lst && f)
	{
		new = f(lst);
		tmp = new;
		while (lst->next)
		{
			tmp->next = (*f)(lst->next);
			tmp = tmp->next;
			lst = lst->next;
		}
	}
	return (new);
}
