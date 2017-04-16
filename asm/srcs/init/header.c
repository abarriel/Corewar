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

void			header_name(char *line, t_header *h, t_asm *a)
{
	unsigned int i;
	char *name;
	char *tmp;

	i = 0;
	a->header_passage += 1;
	skip_space(&line);
	if (*line != '"' && !ft_strchr(LABEL_CHARS, *line))
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	line++;
	name = line;
	if(!ft_strchr(line,'"'))
		name = ft_strjoin(name, "\n");
	while(!ft_strchr(line,'"'))
	{
		// ft_strjoin(name, line);
		get_next_line(a->fd_champ,&line);
		name = ft_strjoin(name, line);
		a->count_line++;
		if(ft_strchr(name,'"'))
			break;
		name = ft_strjoin(name, "\n");
		free(line);
	}
	// ft_printf("{7}[%s]",name);
	if ((ft_strlen(name) - 1) > PROG_NAME_LENGTH)
		length_error(2);
	ft_bzero(h->prog_name, PROG_NAME_LENGTH + 1);
	i = ft_strlchr(name, '"');
	ft_strncpy(h->prog_name, name, i);
	header_verif_name_comment(name, a);
}

void			header_comment(char *line, t_header *h, t_asm *a)
{
	static int		tmp = 0;
	unsigned int	i;

	a->header_passage += 1;
	if (tmp == 1)
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	skip_space(&line);
	if (*line != '"' && !ft_strchr(LABEL_CHARS, *line))
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	line++;
	if ((ft_strlen(line) - 1) > COMMENT_LENGTH)
		length_error(1);
	ft_bzero(h->comment, COMMENT_LENGTH + 1);
	i = ft_strlchr(line, '"');
	ft_strncpy(h->comment, line, i);
	header_verif_name_comment(line, a);
	tmp = 1;
}

int				header_parser(char *line, t_header *h, t_asm *a)
{
	a->len_line = ft_strlen(line) + 1;
	skip_space(&line);
	if (!ft_strncmp(line, NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		header_name(line + ft_strlen(NAME_CMD_STRING), h, a);
	else if (!ft_strncmp(line, COMMENT_CMD_STRING,
				ft_strlen(COMMENT_CMD_STRING)))
		header_comment(line + ft_strlen(COMMENT_CMD_STRING), h, a);
	else if (check_full_space_line(line) == 0)
		;
	else
		token_error(line, a->count_line, a->len_line - ft_strlen(line));
	return (0);
}

void			header_magic_code(t_header *h)
{
	char		str[4];
	int			b0;
	int			b1;
	int			b2;
	int			b3;

	b0 = (COREWAR_EXEC_MAGIC & 0x000000FF) >> 0;
	b1 = (COREWAR_EXEC_MAGIC & 0x0000FF00) >> 8;
	b2 = (COREWAR_EXEC_MAGIC & 0x00FF0000) >> 16;
	b3 = (COREWAR_EXEC_MAGIC & 0xFF000000) >> 24;
	h->magic = (b0 << 24) | (b1 << 16) | (b2 << 8) | (b3 << 0);
	str[0] = h->magic >> 0;
	str[1] = h->magic >> 8;
	str[2] = h->magic >> 16;
	str[3] = h->magic >> 24;
}

void			header_champ(t_asm *a, t_header *h)
{
	char		*line;

	a->count_line = 1;
	header_magic_code(h);
	while (a->header_passage != 2)
	{
		get_next_line(a->fd_champ, &line);
		if (*line != COMMENT_CHAR)
			header_parser(line, h, a);
		a->count_line++;
		free(line);
	}
}
