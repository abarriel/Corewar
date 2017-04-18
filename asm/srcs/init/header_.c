/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 22:27:52 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/22 22:27:54 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		header_parser(char *line, t_header *h, t_asm *a)
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

int		check_full_space_line(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' || str[i] != '\0')
			return (1);
		i++;
	}
	return (0);
}

void	header_verif_name_comment(char *line, t_asm *a)
{
	while (*(line++) && *line != '"')
		;
	line++;
	while (*(line++))
	{
		if (*line != ' ' && *line != '\0')
			return (lexical_error(a->count_line, a->len_line -
				ft_strlen(line)));
	}
	return ;
}

void	header_magic_code(t_header *h)
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
