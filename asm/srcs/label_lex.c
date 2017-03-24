/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_lex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:19:11 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 10:19:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_cmd	*init_cmd(char *op, char *args)
{
	t_cmd	*cmd;

	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
		ft_exit("Failed to Malloc");
	cmd->op = op;
	cmd->args = args;
	cmd->nb_struct = -1;
	cmd->next = NULL;
	return (cmd);
}

void	add_cmd(t_cmd **t, char *op, char *args)
{
	t_cmd	*tmp;
	t_cmd	*r;

	tmp = *t;
	r = *t;
	if (!tmp)
	{
		*t = init_cmd(op, args);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = init_cmd(op, args);
}

void 	get_cmd(t_lab *b, char *s)
{
	t_lab 	*tmp;
	char 	*op;
	char 	*args;

	tmp = b;
	while (b->next)
		b = b->next;
	op = ft_strndup(s, ft_strslen(s,SP));
	s = s + ft_strlen(op);
	skip_space(&s);
	args = ft_strdup(s);
	add_cmd(&b->cmd, op, args);
}


int		check_label_name(char *s)
{
	int i;
	int good;
	int len;

	i = 0;
	len = 0;
	good = 0;
	while (s[i] != '\0')
	{
		if (ft_strchr(LABEL_CHARS, s[i]))
			good++;
		else if (s[i] != LABEL_CHAR && s[i] != DIRECT_CHAR && s[i] != SEPARATOR_CHAR && !ft_strchr(SP,s[i]))
			return(i);
		i++;
	}
	return (0);
}


int		check_first(char c)
{
	if(!ft_strchr(LABEL_CHARS,c))
		return(1);
	return (0);
}

void 	check_label(char *s, t_lab *lab, t_asm *a)
{
	int i;
	int len;
	char *name;

	i = 0;
	name = NULL;
	a->len_line = skip_space(&s);
	if (*s == COMMENT_CHAR)
		return ; 
	len = ft_strlchr(s,LABEL_CHAR);
	if (check_first(*s))
		return (lexical_error(a->count_line, 1));
	if (len == 0 && *s != ':')
	{
		get_cmd(lab, s);
		return ;
	}	
	if ((i = check_label_name(s)) || *s == ':')
		return (lexical_error(a->count_line, i + a->len_line));
	if ((s[len - 1] == DIRECT_CHAR || ft_strchr(SP,s[len - 1])) && ft_strchr(LABEL_CHARS,s[len + 1]))
	{
		get_cmd(lab, s);
				return ;
	}
	name = ft_strndup(s,len);
	add_back_lab(&lab,name,a);
		s = s + len + 1;
	skip_space(&s);
	if (*s != '\0')
	get_cmd(lab, s);

}

void 	remove_first_label(t_lab **begin)
{
	t_lab	*temp;

	if (*begin != NULL)
	{
		if (!(*begin)->cmd)
		{
			temp = *begin;
			*begin = (*begin)->next;
			free(temp);
		}
	}
}

t_lab	*get_label(t_asm *a)
{
	char	*line;
	t_lab	*lab;

	lab = NULL;
	add_back_lab(&lab, "@@", a);
	while (get_next_line(a->fd_champ, &line) > 0)
	{
		if (*line != COMMENT_CHAR && *line != '\0')
		{
			check_label(line, lab, a);
			a->count_line++;
		}
		free(line);
		
	}
	a->count_line += 1;
	// exit(0);
	remove_first_label(&lab);
	return(lab);
}
