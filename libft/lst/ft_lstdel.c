/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 00:28:39 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/12 04:02:23 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *new;

	if (alst && del)
	{
		while (*alst)
		{
			new = (*alst)->next;
			ft_lstdelone(alst, del);
			(*alst) = new;
		}
		(*alst) = NULL;
	}
}
