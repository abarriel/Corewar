/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 04:06:20 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 10:24:25 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
/*
** SKIP LE CMP AVEC LE PREMIER MAILLION CAR IL NEXISTE PAS
**	ft_printf("{6}DI = [%d]\n", T_DIR | T_IND);
**	ft_printf("{6}IR = [%d]\n", T_IND | T_REG);
**	// ft_printf("{6}[%d]", T_DIR | T_REG);
**	ft_printf("{6}RDI =[%d]\n", RID);
**	ft_printf("{6}RID = [%d]\n", RDI);
*/
int	cmp_struct_op(char *op, t_op *op_struct)
{
	int index;

	index = 0;
	while(index < 16)
	{
		if (!ft_strcmp(op,op_struct[index].mnemonique))
			return(index);	
		// ft_printf("{2}%s\n",op_struct[index].mnemonique);
		index++;
	}
	return (-1);
}

int handles_reg(t_asm *a, char *arg, t_cmd *c)
{
	char *str;

	str = arg;
	if (*arg != 'r')
		return(0);
	arg++;
	if(*arg == '\0')
		syntax_error(str,c->colon,c->line);

	c->reg = ft_atoi_p(&(arg));
	(c->reg <= REG_NUMBER) ? NULL: syntax_error(str,c->colon,c->line);
	if (*arg != '\0' && *arg != ';' && *arg != ' ' && *arg != '\t')
		syntax_error(str,c->colon,c->line);
			return(1);
}

int handles_dir(t_asm *a, char *arg, t_cmd *c)
{
	char *str;
	int i;
	int len;

	i = -1;
	str = arg;
	if (*arg != '%')
	{
		return(0);
		// syntax_error(arg,c->colon, c->line);
	}
	if(*arg == '%')
		arg++;
	if (*arg == LABEL_CHAR)
		{
			arg++;
				// exit(1);
			while(++i < a->nb_label)
			{	
				if(!ft_strcmp(arg,a->label[i]))
					break;
			}
			if (i == a->nb_label)
			{
				return(0);
				// no_label_error(arg,str,c->colon,c->line - (ft_strlen(str) - 1));
			}
			return (1);
		}
	else
	{
		if(*arg == '-' && *(arg) + 1 != '\0')
			arg++;
		while(ft_isdigit(arg[++i]))
			;
		len = ft_strlen(arg);
		arg = arg + i;
		len -= skip_space_len(&arg);
		if (i != len)
		{
			return(0);
			// syntax_error(arg,c->colon, c->line - i);
		}
			return(1);
	}
}

int handles_ind(t_asm *a, char *arg, t_cmd *c)
{
	char *str;
	int i;
	int len;


	i = -1;
	str = arg;
	// ft_printf("{%s}",arg);
	// arg++;
	if (*arg == LABEL_CHAR)
		{
			arg++;
			while(++i < a->nb_label)
			{
				if(!ft_strcmp(arg,a->label[i]))
					break;
			}
			if (i == a->nb_label)
			{
				// return(0);
				no_label_error(arg,str,c->colon,c->line - (ft_strlen(str) - 1));
			}
			return (1);
		}
	else
	{
		if(*arg == '-' && *(arg) + 1 != '\0')
			arg++;
		while(ft_isdigit(arg[++i]))
			;
			len = ft_strlen(arg);
		arg = arg + i;
		len -= skip_space_len(&arg);
		if (i != len)
		{
			return(0);
			syntax_error(arg,c->colon, c->line - i);
		}
		return(1);

	}
}

void check_type(t_asm *a, t_cmd *c, t_op *op_struct, short index)
{
	int binary;
	int red;

	red = 0;
	binary = 0;
	// ft_printf("{8}[%d]",op_struct[c->nb_struct].type[index]);
	if((op_struct[c->nb_struct].type[index]) & T_REG)
	{
		red = handles_reg(a, c->type[index], c);
		// ft_printf(" R:[%d][%s] ",red,c->type[index]);
	}
	if((op_struct[c->nb_struct].type[index]) & T_DIR)
	{
		// ft_printf("-DIR-");
		red += handles_dir(a, c->type[index], c);
		// ft_printf("D:[%d]",red,c->type[index]);

	}
	if((op_struct[c->nb_struct].type[index]) & T_IND)
	{
		red += handles_ind(a, c->type[index], c);
		// ft_printf("-IND-");
		// ft_printf("I:[%d]-",red,c->type[index]);

	}
	if((op_struct[c->nb_struct].type[index]) & T_LAB)
	{
		ft_printf("-LAB-");
	}
	if (red == 0)
		syntax_error(c->type[index],c->colon, c->line);
	// ft_printf("{9}[%d]",red);
}

void check_instructions(t_asm *a, t_cmd *c, t_op *op_struct)
{
	short index;

	index = 0;
	// ft_printf("{9}%s = ",c->op);
	while(c->type[index])
	{
		// ft_printf("{2}%s,",c->type[index], a->line_);
		check_type(a, c, op_struct, index);
	// ft_printf("\n");
			
		index++;
	}
	// ft_printf("\n");
}

void handles_instructions(t_asm *a, t_cmd *c, t_op *op_struct)
{
	char **args;
	size_t index;

	index = 0;
	// a->line_ = ft_strlen(c->args);
	args = ft_strsplit(c->args, SEPARATOR_CHAR);
	while (args[index])
		index++;
	if (index != op_struct[c->nb_struct].nbr_args)
		invalid_error(c->op, index);
	index = 0;
	while (index != op_struct[c->nb_struct].nbr_args)
	{
		skip_space(&args[index]);
		c->type[index] = args[index];
		index++;
	}
	c->type[index]  = NULL;
	// c->type[index]  = NULL;
	// c->type[index]  = NULL;
}

void handles_cmd_name(t_asm *a, t_cmd *c, t_op *op_struct, int count_line)
{
	int i;

	i = 0;
	while (c)
		{

			if ((c->nb_struct = cmp_struct_op(c->op, op_struct)) == -1)
			{
				return (token_error(c->op, count_line + i, ft_strlen(c->op) + 1));
			}
			else
			{	
				c->line+= i;
				// a->line_ += i;
				// a->len_line = ft_strlen(c->op) + 1;
				// a->count_line = count_line  + i;
				handles_instructions(a,c,op_struct);
				check_instructions(a,c,op_struct);
			}
			i++;
			// ft_printf("{5}%s\n",c->args);
			c = c->next;
		}
		// ft_printf("\n");

}
void handles_op(t_asm *a, t_lab *l, t_op *op_struct)
{
	while (l)
	{
		handles_cmd_name(a, l->cmd, op_struct, l->count_line);
		l = l->next;
	}
}
void check_operation(t_asm *a, t_lab *l)
{
	t_op *op_struct;

	op_struct = get_op();
	// t_lab	*lab;
	// op = get_op();
	// ft_printf("{8}{%d}",c->colon);
	handles_op(a, l, op_struct);
	print_label(l);
	
}	