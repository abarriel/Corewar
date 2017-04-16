/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:27:34 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/16 20:51:31 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#define D "'"
void 	print_winner(t_player *p)
{
	ft_printf("Constestant %d, \"%s\", has won !\n", (unsigned int)p->nb, p->name);
}

void 	print_is_alive(char *name)
{
	ft_printf("Le joueur %s est en vie\n", name);
}

void 	nbr_allready_used(int nb)
{
	ft_printf("Prog number %d already used\n", nb);
	exit(0);
}

void 	error_executable(void)
{
	ft_printf("File_name is not a corewar executable\n");
	exit(0);
}

void 	print_players_start(t_player	*p)
{
	while (p)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				(unsigned int)p->id, p->weight, p->name, p->comment);
		p = p->next;
	}
}
