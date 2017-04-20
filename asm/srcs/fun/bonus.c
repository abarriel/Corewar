/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/31 16:21:31 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/17 15:56:09 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_arg_fun(t_cmd *c, t_op op_t)
{
	short	index;
	int		i;

	index = 0;
	while (index != op_t.nbr_args)
	{
		i = 0;
		while (c->type[index][i])
		{
			if (c->type[index][i] == ' ' || c->type[index][i] == '\t')
				c->type[index][i] = 0;
			i++;
		}
		if (c->typs[index] & T_REG)
			ft_printf("{3} %12s", c->type[index]);
		else if (c->typs[index] & T_DIR)
			ft_printf("{8} %12s", c->type[index]);
		else if (c->typs[index] & T_IND)
			ft_printf("{6} %12s", c->type[index]);
		index++;
	}
}

void	write_arg_size_(t_cmd *c, t_op op_t, short index)
{
	char	*tmp;

	if (c->typs[index] & T_REG)
	{
		c->r[index] = ft_atoi(c->type[index] + 1);
		ft_printf("{3}%#10.02x ", c->r[index]);
	}
	if (c->typs[index] & T_DIR)
	{
		tmp = (c->type[index] + 1);
		if (op_t.idk1)
		{
			c->d2[index] = swap_usint(c->d2[index]);
			ft_printf("{8}%#10.02x ", c->d2[index]);
		}
		else
		{
			c->d4[index] = swap_uint(c->d4[index]);
			ft_printf("{8}%#10.04x ", c->d4[index]);
		}
	}
}

void	write_arg_size(t_cmd *c, t_op op_t)
{
	char	*tmp;
	short	index;

	index = 0;
	while (index != op_t.nbr_args)
	{
		write_arg_size_(c, op_t, index);
		if (c->typs[index] & T_IND)
		{
			tmp = (c->type[index]);
			if (*tmp == LABEL_CHAR)
				ft_printf("{6}%#10.04x ", c->d2[index]);
			else
				ft_printf("{6}%#10.04x ", c->ind[index]);
		}
		index++;
	}
}

void	write_cmd_fun(t_cmd *c)
{
	short	index;

	index = 0;
	while (c)
	{
		ft_printf("\t \e[38;5;6m%d (%d) \e[38;5;9m%4s\e[38;5;94m%7s",
			c->t_bytes - c->bytes, c->bytes, c->op, "Codage");
		while (ft_strcmp(g_op[index].mnemonique, c->op))
			index++;
		write_arg_fun(c, g_op[index]);
		ft_putchar('\n');
		ft_printf("{7}\t      %#5.02x", g_op[index].code);
		if (g_op[index].nbr_args != 1)
			ft_printf("{9}   %#02.2x ", c->barg);
		else
			ft_printf("{9}   %s ", "----");
		write_arg_size(c, g_op[index]);
		ft_putstr("\n\n");
		index = 0;
		c = c->next;
	}
}

void	bonus(t_asm *a, t_lab *l, t_header *h)
{
	unsigned int	size;

	if (!l)
	{
		ft_dprintf(2, "No instructions found for %s\n", h->prog_name);
		exit(0);
	}
	size = swap_uint(a->total_bytes);
	ft_putstr("Dumping annotated program on standar output\n");
	ft_printf("{6}Programme size : %d bytes\n", size);
	ft_printf("{1}Name :\"%s\"\n", h->prog_name);
	ft_printf("{1}Comment :\"%s\"\n\n", h->comment);
	while (l)
	{
		ft_printf("\e[38;5;6m%3d\033[0m : ", l->bytes);
		ft_printf("%s\n\n", l->label);
		write_cmd_fun(l->cmd);
		l = l->next;
	}
}
