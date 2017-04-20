/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:27:52 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/25 23:09:55 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*header_name_(char *line, t_asm *a)
{
	char	*name;

	name = line;
	if (!ft_strchr(line, '"'))
		name = ft_strjoin(name, "\n");
	while (!ft_strchr(line, '"'))
	{
		if ((get_next_line(a->fd_champ, &line)) == 0)
			ft_exit("Only name.. wrong champ");
		name = ft_strjoin(name, line);
		a->count_line++;
		if (ft_strchr(name, '"'))
			break ;
		name = ft_strjoin(name, "\n");
		free(line);
	}
	return (name);
}

void			header_name(char *line, t_header *h, t_asm *a)
{
	unsigned int	i;
	char			*name;

	i = 0;
	a->header_passage += 1;
	skip_space(&line);
	if (*line != '"')
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	line++;
	name = header_name_(line, a);
	if ((ft_strlen(name) - 1) > PROG_NAME_LENGTH)
		length_error(2);
	ft_bzero(h->prog_name, PROG_NAME_LENGTH + 1);
	i = ft_strlchr(name, '"');
	ft_strncpy(h->prog_name, name, i);
	header_verif_name_comment(name, a);
}

char			*header_comment_(char *line, t_asm *a)
{
	char *name;

	name = line;
	if (!ft_strchr(line, '"'))
		name = ft_strjoin(name, "\n");
	while (!ft_strchr(line, '"'))
	{
		if ((get_next_line(a->fd_champ, &line)) == 0)
			ft_exit("Only comment.. wrong champ");
		name = ft_strjoin(name, line);
		a->count_line++;
		if (ft_strchr(name, '"'))
			break ;
		name = ft_strjoin(name, "\n");
		free(line);
	}
	return (name);
}

void			header_comment(char *line, t_header *h, t_asm *a)
{
	static int		tmp = 0;
	unsigned int	i;
	char			*name;

	a->header_passage += 1;
	if (tmp == 1)
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	skip_space(&line);
	if (*line != '"')
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	line++;
	name = header_comment_(line, a);
	if ((ft_strlen(name) - 1) > COMMENT_LENGTH)
		length_error(1);
	ft_bzero(h->comment, COMMENT_LENGTH + 1);
	i = ft_strlchr(name, '"');
	ft_strncpy(h->comment, name, i);
	header_verif_name_comment(name, a);
	tmp = 1;
}

void			header_champ(t_asm *a, t_header *h)
{
	char		*line;

	a->count_line = 1;
	header_magic_code(h);
	while (a->header_passage != 2)
	{
		if (get_next_line(a->fd_champ, &line) == 0)
			ft_exit("Empty file or Wrong header ?");
		if (*line != COMMENT_CHAR)
			header_parser(line, h, a);
		a->count_line++;
		free(line);
	}
}
