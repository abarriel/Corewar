/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 08:04:28 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/27 08:04:37 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
** LABEL SANS CMD CHOPPE LE TRUC
*/
unsigned short int 	get_pos_label(short bytes, char *s, t_lab *l)
{
	while(l)
	{
		if (!ft_strcmp(s,l->label))
		{
			if (l->cmd)
			{
				ft_printf("{8}{%d}{%d}",l->cmd->t_bytes - l->cmd->bytes, bytes);
				return((l->cmd->t_bytes - l->cmd->bytes) - bytes);
				// ft_printf("{9}{%s}{%d}\n",l->label, l->cmd->t_bytes - l->cmd->bytes);
				// ft_printf("{8}{%s}{%d}",s, bytes);
			}
			else
			{
				ft_printf("{8}{%d}{%d}",l->bytes, bytes);
				return(l->bytes - bytes);
			}
			// ft_printf("{%s}[%s]",)
		}
		l= l->next;
	}
	return (0);
	// ft_printf("%s",s);
}

void 	recup_label(t_cmd *c, t_op op_t, t_lab *tmp)
{
	char *new;
	short index;

	index = 0;
	while(index != op_t.nbr_args)
	{
		if (c->typs[index] & T_DIR)
		{
			new = (c->type[index] + 1);
			if (*new == LABEL_CHAR)
			{
				new = new + 1;
				c->d2[index] = get_pos_label(c->t_bytes - c->bytes,new, tmp);
				ft_printf("{9}{%d}\n",c->d2[index]);
				c->d2[index] = swap_usint(c->d2[index]);
			}		
		}
		index++;
	}
}

void	handles_label(t_asm *a, t_cmd *c, t_op *op_struct, t_lab *tmp)
{
	int	i;
	
	i = 0;
	while (c)
	{	
		recup_label(c, op_struct[c->nb_struct], tmp);
		//ft_printf("\n");
		c = c->next;
	}
}

void	write_label(t_asm *a, t_lab *l, t_op *op)
{
	// t_op	*op_strut;
	t_lab *tmp;
	// op_strut = get_op();
	tmp = l;
	while (l)
	{
		handles_label(a, l->cmd, op,tmp);
		l = l->next;
	}
}