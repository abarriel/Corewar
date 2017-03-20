/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:00:18 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/20 01:13:10 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_file(t_asm *a)
{
	if ((a->fd_cor = open(a->cor, O_CREAT | O_WRONLY | O_TRUNC, 0644)) < 0)
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

	a = init_asm();
	if (av != 2)
		ft_exit("Usage: ./asm <champion.s>");
	get_info_asm(ac[1], a);
	check_file(a);
	while (1)
		;
	return (0);
}
