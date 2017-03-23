/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:19:11 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/23 08:57:15 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** j'ai(allan) remarquer que les label definisse un nb dinstruction, MAIS une instructions toute seul peut aussi
** etre accepter donc si on parse avec LABEL_CHARS  "ZJMP %: live" va etre compter comme une erreur lexical alors que non
** donc on doi parser en !LABEL_CHARS && != '%' && ! = ','   donc LABEL_CHARS, DIRECT CHAR, SPE CHAR, definisse lensemble
** des "ascii" que lon peu utliser dans corewar, donc le parser LEXICAL parse tout ca
** NOTICE = jAI DONNC declarer  le premier maillon de LABEL_LIST et on stockera les instruction denus de label dedans
** Petit trick  pour chaque new label maillon il y a  le  N LIGNE a la quel il a etait parser,
** jai tout stocker meme les zjmp: live dans un maillon alors que c pertinament une instruction qui appartien aux label precedent,
** mais vu quune instruction peu etre consider comme label
** la boucle est bouclee (EDIT= je pense c pas bien de stocker meme les inscrution)
*/

#include "asm.h"
#define SP " \t"


// t_cmd	*init_cmd(char *s)
// {
// 	t_cmd	*cmd;

// 	if (!(cmd = (t_cmd*)malloc(sizeof(t_cmd))))
// 		ft_exit("Failed to Malloc");
// 	cmd->op = ft_strdup(s);
// 	// u->op = s;
// 	cmd->next = NULL;
// 	return (cmd);
// }

// t_cmd	*add_cmd(t_cmd **t, char *s)
// {
// 	t_cmd	*tmp;
// 	t_cmd	*r;

// 	tmp = *t;
// 	r = *t;
// 	if (!tmp)
// 	{
// 		*t = init_cmd(s);
// 		return (*t);
// 	}
// 	while (tmp->next)
// 		tmp = tmp->next;
// 	tmp->next = init_cmd(s);
// 	return (r);
// }

// void 	get_cmd(t_lab **b, char *s)
// {
// 	// b->cmd = add_cmd(b->cmd, s);
// 	// je pense quon pourrai faire un traitement ici 
// 	// pour linstant juste rempli name
// }

int		check_label_name(char *s)
{
	int i;
	int good;
	int len;

	i = 0;
	len = 0;
	good = 0;
	while (s[i] != '\0' && s[i] != LABEL_CHAR)
	{
		if (ft_strchr(LABEL_CHARS, s[i]))
			good++;
		else if (s[i] != DIRECT_CHAR && s[i] != SEPARATOR_CHAR && !ft_strchr(SP,s[i]))
			return(i);
		i++;
	}
	return (0);
}

void 	check_label(char *s, t_lab *lab, t_asm *a)
{
	int i;
	int len;
	char *name;

	i = 0;
	len = ft_strlchr(s,LABEL_CHAR);
	if (len == 0 && *s != ':')
	{
				// doic etre s dans lab->args, mais jai la flemme
		return ;
	}
	a->len_line = (a->len_line == 1 && *s != ':') ? 0 : a->len_line;
	// ft_printf("{8}%s - %d\n",s,a->count_line);
	if ((i = check_label_name(s)) || *s == ':')
		return (lexical_error(a->count_line, i + a->len_line));
	if (s[len - 1] == DIRECT_CHAR && ft_strchr(LABEL_CHARS,s[len + 1]))
	{
				// doic etre s dans lab->args, mais jai la flemme
				return ;
	}
	/*
	** JE NEXT LES %:LABEL_CHARS car je c que meme en analyse lexical 
	** ca ne sera JAMAIS un label "%:LABELCHAR"
	** donc sa sert a rien de le mettre dans la struct
	*/ 
	name = ft_strndup(s,len);
	// ft_printf("{8}%s\n",name);
	add_back_lab(&lab,name,a);

}

void	get_label(t_asm *a)
{
	char	*line;
	t_op	*op;
	t_lab	*lab;

	op = get_op();
	lab = NULL;
	add_back_lab(&lab, "", a);
	while (get_next_line(a->fd_champ, &line) > 0)
	{
		if ((a->len_line = skip_space(&line)) && *line != COMMENT_CHAR)
			{
				// ft_printf("%s\n",line);
				check_label(line, lab, a);
			}
		a->count_line++;
	}
	// DEBUG
	print_label(lab);
}
