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

t_op g_op[17] = {{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {RDI, RID, T_REG}, 6, 6, "r1,r2,r3. r1&r2 -> r3", 1, 0},
	{"or", 3, {RID, RID, T_REG}, 7, 6, "r1,r2,r3. r1 | r2 -> r3", 1, 0},
	{"xor", 3, {RID, RID, T_REG}, 8, 6, "r1,r2,r3. r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {RDI, T_DIR | T_REG, T_REG}, 10, 25, "load index", 1, 1},
	{"sti", 3, {T_REG, RDI, T_DIR | T_REG}, 11, 25, "store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {RDI, T_DIR | T_REG, T_REG}, 14, 50, "lng lod idx", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}};

void write_arg_fun(t_cmd *c, t_op op_t)
{
	char	*tmp;
	short	index;
	short	get_reg;
	int 	i;

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

// Codage [0000000000r4] [0000000000%0] [000000000r3	]
	   // 0x06   0x64 [        0x04] [      0x0000] [        0x03]
void write_arg_size(t_cmd *c, t_op op_t)
{
	char	*tmp;
	short	index;

	index = 0;
	while (index != op_t.nbr_args)
	{
		if (c->typs[index] & T_REG)
		{
			c->r[index] = ft_atoi(c->type[index] + 1);
			ft_dprintf(2, "{3}%#10.02x ", c->r[index]);
		}
		if (c->typs[index] & T_DIR)
		{
			tmp = (c->type[index] + 1);
			if (op_t.idk1)
			{
				c->d2[index] = swap_usint(c->d2[index]);
				ft_dprintf(2, "{8}%#10.02x ", c->d2[index]);
			}
			else
			{
				c->d4[index] = swap_uint(c->d4[index]);
				ft_dprintf(2, "{8}%#10.04x ", c->d4[index]);
			}
		}
		if (c->typs[index] & T_IND)
		{
			tmp = (c->type[index]);
			if (*tmp == LABEL_CHAR)
			ft_dprintf(2, "{6}%#10.04x ", c->d2[index]);
			else
			ft_dprintf(2, "{6}%#10.04x ", c->ind[index]);
		}
		index++;
	}
}

void write_cmd_fun(t_cmd *c)
{
	short index;

	index = 0;
	while(c)
		{
			ft_printf("\t \e[38;5;6m%d \e[38;5;9m%4s\e[38;5;94m%7s",c->bytes, c->op, "Codage");
			while(ft_strcmp(g_op[index].mnemonique,c->op))
				index++;
			write_arg_fun(c,g_op[index ]);
			ft_printf("\n");
			ft_printf("{7}\t%#5.02x",g_op[index].code);
			if(g_op[index].nbr_args != 1)
				ft_printf("{9}   %#02.2x ",c->barg);
			else
				ft_printf("{9}   %s ","----");
			write_arg_size(c,g_op[index ]);
			ft_printf("\n\n");
			index = 0;
			c = c->next;
	}
}
void bonus(t_asm *a, t_lab *l, t_header *h, t_op *op)
{
	unsigned int size;

	if (!l)
	{
		ft_printf("No instructions found for %s\n",h->prog_name);
		exit(0);
	}
	size = swap_uint(a->total_bytes);
	ft_printf("Dumping annotated program on standar output\n");
	ft_printf("{6}Programme size : %d bytes\n",size);
	ft_printf("{1}Name :\"%s\"\n",h->prog_name);
	ft_printf("{1}Comment :\"%s\"\n\n",h->comment);
	while(l)
	{
		ft_printf("\e[38;5;6m%3d\033[0m : ",l->bytes);
		ft_printf("%s\n\n",l->label);
		write_cmd_fun(l->cmd);
		l = l->next;
	}
}
