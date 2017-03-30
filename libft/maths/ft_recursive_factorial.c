/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/02 15:42:27 by abarriel          #+#    #+#             */
/*   Updated: 2016/11/02 15:42:29 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_recursive_factorial(int nb)
{
	if (nb == 1 || nb == 0)
		return (1);
	if (nb > 1 && nb < 13)
		return (nb * ft_recursive_factorial(nb - 1));
	else
		return (0);
}
