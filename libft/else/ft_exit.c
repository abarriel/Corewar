/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 01:59:56 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/19 06:21:58 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ext(const char *message, int i)
{
	if (message != NULL)
		ft_putendl_fd(message, 2);
	return (i);
}

void	ft_exit(const char *message)
{
	if (message != NULL)
		ft_putendl_fd(message, 2);
	exit(0);
}
