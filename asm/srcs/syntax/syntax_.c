/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 23:23:39 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/25 23:23:41 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** 	A LA PLACE DE T_REG PEUT ETRE REG_CODE
*/

int		handles_reg(char *arg, t_cmd *c)
{
	char	*str;

	str = arg;
	if (*arg != 'r')
		return (0);
	arg++;
	if (*arg == '\0')
		syntax_error(str, c->colon, c->line);
	c->reg = ft_atoi_p(&(arg));
	(c->reg <= REG_NUMBER) ? NULL : syntax_error(str, c->colon, c->line);
	if (*arg != '\0' && *arg != ';' && *arg != ' ' && *arg != '\t')
		syntax_error(str, c->colon, c->line);
	return (T_REG);
}

void	check_type(t_asm *a, t_cmd *c, t_op *op_struct, short index)
{
	int		binary;
	int		red;

	red = 0;
	binary = 0;
	if ((op_struct[c->nb_struct].type[index]) & T_REG)
		red = handles_reg(c->type[index], c);
	if ((op_struct[c->nb_struct].type[index]) & T_DIR)
		red += handles_dir(a, c->type[index]);
	if ((op_struct[c->nb_struct].type[index]) & T_IND)
		red += handles_ind(a, c->type[index], c);
	// if ((op_struct[c->nb_struct].type[index]) & T_LAB)
	// 	ft_printf("-LAB-");
	if (red == 0)
		syntax_error(c->type[index], c->colon, c->line);
	c->typs[index] = red;
}

void	check_instructions(t_asm *a, t_cmd *c, t_op *op_struct)
{
	short	index;

	index = 0;
	while (index != op_struct[c->nb_struct].nbr_args)
	{
		check_type(a, c, op_struct, index);
		index++;
	}
}
