/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/26 00:39:07 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/26 00:39:19 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		write_c(t_cmd *c, t_op op_t)
{
	short	index;
	int		mask;

	c->barg = 0;
	mask = 6;
	index = 0;
	while (index != op_t.nbr_args)
	{
		if (c->typs[index] & T_REG)
			c->barg |= (REG_CODE) << mask;
		if (c->typs[index] & T_DIR)
			c->barg |= (DIR_CODE) << mask;
		if (c->typs[index] & T_IND)
			c->barg |= (IND_CODE) << mask;
		index++;
		mask -= 2;
	}
}

static void		write_arg_(t_cmd *c, t_op op_t, int index)
{
	char *tmp; 

	if (c->typs[index] & T_DIR)
	{
		tmp = (c->type[index] + 1);
		if ((!op_t.idk && op_t.idk1) || (op_t.idk & op_t.idk1))
		{
			c->d2[index] = ft_atoi(tmp);
			c->d2[index] = swap_usint(c->d2[index]);
			c->bytes += sizeof(c->d2[index]);
		}
		else
		{
			c->d4[index] = ft_atoi(tmp);
			c->d4[index] = swap_uint(c->d4[index]);
			c->bytes += sizeof(c->d4[index]);
		}
	}
	if (c->typs[index] & T_IND)
	{
		c->ind[index] = ft_atoi(c->type[index]);
		c->ind[index] = swap_usint(c->ind[index]);
		c->bytes += sizeof(c->ind[index]);
	}
}

static void		write_arg(t_cmd *c, t_op op_t)
{
	char	*tmp;
	short	index;
	short	get_reg;

	index = 0;
	while (index != op_t.nbr_args)
	{
		if (c->typs[index] & T_REG)
		{
			tmp = (c->type[index] + 1);
			get_reg = ft_atoi(tmp);
			c->r[index] = get_reg;
			c->bytes += sizeof(c->r[index]);
		}
		write_arg_(c, op_t, index);
		index++;
	}
}

static void		handles_code(t_asm *a, t_cmd *c)
{
	int			i;
	static int	tmp;

	i = 0;
	while (c)
	{
		c->code = g_op[c->nb_struct].code;
		c->bytes += sizeof(c->code);
		if (g_op[c->nb_struct].idk == 1)
		{
			write_c(c, g_op[c->nb_struct]);
			c->bytes += sizeof(c->barg);
		}
		write_arg(c, g_op[c->nb_struct]);
		tmp += c->bytes;
		c->t_bytes = tmp;
		c = c->next;
	}
	a->total_bytes = tmp;
}

void			write_op(t_asm *a, t_lab *l)
{
	l->bytes = 0;
	while (l)
	{
		handles_code(a, l->cmd);
		l = l->next;
		if (l)
			l->bytes = a->total_bytes;
	}
	a->total_bytes = swap_uint(a->total_bytes);
}
