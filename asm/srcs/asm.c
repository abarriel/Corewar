/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:00:18 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/21 12:14:54 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	create_file(t_asm *a)
{
	if ((a->fd_cor = open(a->cor, O_CREAT | O_WRONLY | O_APPEND, 0644)) < 0)
		ft_exit("Cannot create file");
}

void	get_info_asm(char *s, t_asm *a)
{
	if ((a->fd_champ = open(s, O_RDONLY)) < 0)
		ft_exit("Cannot Open file");
	if ((ft_strrncmp(s, "s.", 2)) || ft_strlen(s) == 2)
		ft_exit("Not good extension/Not good file");
	if (!(a->champ_name = ft_strndup(s, ft_strlen(s) - 2)))
		ft_exit("Error strdup");
	a->cor = a->champ_name;
	ft_strcat(a->cor, ".cor");
}

int		main(int av, char **ac)
{
	t_asm	*a;
	t_header *h;

	a = init_asm();
	h = init_header();
	if (av != 2)
		ft_exit("Usage: ./asm <champion.s>");
	get_info_asm(ac[1], a);
	create_file(a);
	header_champ(a, h);
	return (0);
}
