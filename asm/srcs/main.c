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

// void	create_file(t_asm *a, t_lab *l)
// {
// 	if ((a->fd_cor = open(a->cor, O_CREAT | O_WRONLY | O_APPEND, 0644)) < 0)
// 		ft_exit("Cannot create file");
// 	// write(a->fd_cor, &(str), sizeof(COREWAR_EXEC_MAGIC));
// 	// write(a->fd_cor, &(h->prog_name), sizeof(h->prog_name));
// 	// write(a->fd_cor, &(h->comment), sizeof(h->comment));
// 	while(l)
// 	{
// 		while(l->cmd)
// 		{
// 			write(a->fd->c)
// 			write(1,&(typs),sizeof(typs));		
// 			l->cmd = l->cmd->next;
// 		}
// 		l = l->next;
		
// 	}

// }

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
	t_asm		*a;
	t_header	*h;
	t_lab		*l;

	l = NULL;
	a = init_asm();
	h = init_header();
	if (av != 2)
		ft_exit("Usage: ./asm <champion.s>");
	get_info_asm(ac[1], a);
	// create_file(a);
	header_champ(a, h);
	l = get_label(a);
	check_operation(a, l);
	write_op(a, l);
	// create_file(a, l);
	return (0);
}
