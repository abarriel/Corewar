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
**
**
0290 ffff fff0 05
01 e05a a4af 
0b 64 02 fff4 05 
0b 64 03 ffee 04 
0b 64 0a ffe8 06 
*/

__uint16_t get_pos_label(short bytes, char *s, t_lab *l)
{
	while (l)
	{
		if (!ft_strcmp(s, l->label))
		{
			if (l->cmd)
			{
				// ft_printf("{8}{%d}{%d}",
				// l->cmd->t_bytes - l->cmd->bytes, bytes);
				// ft_printf("{4}Final = [%d]\n",(l->cmd->t_bytes - l->cmd->bytes) - bytes);
				return ((l->cmd->t_bytes - l->cmd->bytes) - bytes);
			}
			else
			{

				// ft_printf("{8}{%d}{%d}", l->bytes, bytes);
				return (l->bytes - bytes);
			}
		}
		l = l->next;
	}
	return (0);
}

void				recup_label(t_cmd *c, t_op op_t, t_lab *tmp)
{
	char	*new;
	short	index;

	index = 0;
	while (index != op_t.nbr_args)
	{
		if (c->typs[index] & T_DIR)
		{
			new = (c->type[index] + 1);
			if (*new == LABEL_CHAR)
			{
				new = new + 1;
				if (!op_t.idk1)
				{
					c->d4[index] = get_pos_label(c->t_bytes - c->bytes, new, tmp);
					c->d4[index] = swap_uint(c->d4[index]);
				}
				else
					c->d2[index] = get_pos_label(c->t_bytes - c->bytes, new, tmp);	
					c->d2[index] = swap_usint(c->d2[index]);
					// ft_printf("{1}[%x]",c->d2[index]);
			}
		}
		else if (c->typs[index] & T_IND)
		{
			new = (c->type[index]);
			// ft_printf("{4}[ll%sll]",new);
			if (*new == LABEL_CHAR)
			{
				new = new + 1;
				c->ind[index] = get_pos_label(c->t_bytes - c->bytes, new, tmp);	
				// ft_printf("{4}]]]]]%d[[[[[ %d ",c->ind[index],index);
				c->d2[index] = c->ind[index];
				c->ind[index] = swap_usint(c->ind[index]);
			}
		}
		index++;
	}
}

void				handles_label(t_cmd *c, t_lab *tmp)
{
	int	i;

	i = 0;
	while (c)
	{
		recup_label(c, g_op[c->nb_struct], tmp);
		c = c->next;
	}
}

void				write_label(t_lab *l)
{
	t_lab *tmp;

	tmp = l;
	while (l)
	{
		handles_label(l->cmd, tmp);
		l = l->next;
	}
}
