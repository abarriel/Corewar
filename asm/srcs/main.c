/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:00:18 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/25 23:10:26 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
** PAS OUBLIER CHAMPIONS AVEC HEADER MAIS INSTRUCTION VIDE
**/
void	create_file(t_asm *a, t_lab *l)
{
	if ((a->fd_cor = open(a->cor, O_CREAT | O_WRONLY | O_APPEND | O_TRUNC, 0644)) < 0)
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
	ft_strcat(a->cor, ".cor\0");
}

int		main(int av, char **ac)
{
	t_asm		*a;
	t_header	*h;
	t_op        *op;
	t_lab		*l;

	l = NULL;
	a = init_asm();
	h = init_header();
	op = get_op();

	if (av != 2)
		ft_exit("Usage: ./asm <champion.s>");
	get_info_asm(ac[1], a);
	header_champ(a, h);
	l = get_label(a);
	check_operation(a, l);
	//print_label(l);
	// exit(0);
	write_op(a, l);
	write_label(a, l, op);
	h->prog_size = a->total_bytes;
	create_file(a, l);
	final_write(a, h, l, op);
	close(a->fd_champ);
	close(a->fd_cor);
	return (0);
}
