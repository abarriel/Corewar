/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_lex_.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 23:37:27 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/25 23:37:28 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*init_cmd(char *op, char *args, int line, int colon)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_exit("Failed to Malloc");
	cmd->op = op;
	cmd->line = line;
	cmd->colon = colon;
	cmd->args = args;
	cmd->nb_struct = -1;
	cmd->next = NULL;
	return (cmd);
}

void	add_cmd(t_cmd **t, char *op, char *args, t_lab *b)
{
	t_cmd	*tmp;
	t_cmd	*r;

	tmp = *t;
	r = *t;
	if (!tmp)
	{
		*t = init_cmd(op, args, b->line, b->colon);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = init_cmd(op, args, b->line, b->colon);
}

void	get_cmd(t_lab *b, char *s, t_asm *a)
{
	t_lab	*tmp;
	char	*op;
	char	*args;
	int		i;
	int		ok;

	tmp = b;
	i = b->line;
	ok = b->colon;
	while (b->next)
		b = b->next;
	b->line = i;
	b->colon = ok;
	op = ft_strndup(s, ft_strslen(s, SP));
	s = s + ft_strlen(op);
	skip_space(&s);
	args = ft_strdup(s);
	add_cmd(&b->cmd, op, args, b);
}

void	remove_first_label(t_asm *a, t_lab **begin)
{
	t_lab	*temp;

	if (*begin != NULL)
	{
		if (!(*begin)->cmd)
		{
			temp = *begin;
			*begin = (*begin)->next;
			a->nb_label--;
			free(temp);
		}
	}
}

char	**add_label(t_lab **l, t_asm *a)
{
	t_lab	*lab;
	int		index;
	char	**label;

	lab = *l;
	index = 0;
	label = (char **)malloc(sizeof(char *) * a->nb_label);
	while (*l)
	{
		label[index] = (*l)->label;
		index++;
		*l = (*l)->next;
	}
	// label[index] = NULL;
	*l = lab;
	return (label);
}
