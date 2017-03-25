/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:27:34 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/25 05:27:44 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

voidprint_winner(t_player *p)
{
	printf("Constestant %d, \"%s\",		has won !\n", (unsigned int)p->id, p->name);
}

voidprint_is_alive(cha	r *name)
{
	ft_printf("Le joueur %s est en vie\n", name);
}

voidnbr_a	llready_used(int nb)
{
	ft_printf("Prog number %d already used\n", nb);
	exit(0);
}

voiderror_executable(void)
{
	ft_printf("File_name is not	 a corewar executable\n");
	exit(0);
}

voidprint_players_start(t_env	*p)
{
	while (p)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
				(unsigned int)p->id, p->weight, p->name, p->comment);
		p = p->next;
	}
}
