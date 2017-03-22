/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 01:44:25 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/22 04:35:28 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */

#include "asm.h"
#include "locale.h"

void 	header_name(char *line, t_header *h, t_asm *a)
{
	skip_space(&line);
	if (*line != '"' && !ft_strchr(LABEL_CHARS, *line))
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	line++;
	if ((ft_strlen(line) - 1) > PROG_NAME_LENGTH)
		ft_printf("Champion name too long (Max length %d)\n", PROG_NAME_LENGTH);
	ft_bzero(h->prog_name, PROG_NAME_LENGTH + 1);
	ft_strncpy(h->prog_name, line, ft_strclen(line, '"'));
	write(a->fd_cor, &(h->prog_name), sizeof(h->prog_name));
}

void 	header_comment(char *line, t_header *h, t_asm *a)
{
	static int tmp = 0;

	if (tmp == 1)
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	skip_space(&line);
	if (*line != '"' && !ft_strchr(LABEL_CHARS, *line))
		return (lexical_error(a->count_line, a->len_line - ft_strlen(line)));
	line++;
	if ((ft_strlen(line) - 1) > COMMENT_LENGTH)
		ft_printf("Champion comment too long (Max length %d)\n", COMMENT_LENGTH);
	ft_bzero(h->comment, COMMENT_LENGTH);
	ft_strncpy(h->comment, line, ft_strclen(line, '"'));
	write(a->fd_cor, &(h->comment), sizeof(h->comment));
	tmp = 1;
}

int 	header_parser(char *line, t_header *h, t_asm *a)
{
	a->len_line = ft_strlen(line) + 1;
	skip_space(&line);
	if (!ft_strncmp(line,NAME_CMD_STRING, ft_strlen(NAME_CMD_STRING)))
		header_name(line + ft_strlen(NAME_CMD_STRING), h, a);
	else if (!ft_strncmp(line,COMMENT_CMD_STRING, ft_strlen(COMMENT_CMD_STRING)))
		header_comment(line + ft_strlen(COMMENT_CMD_STRING), h, a);
	return (0);
}

void	header_magic_code(t_asm *a, t_header *h)
{
	char str[4];
	int b0;
	int b1;
	int b2;
	int b3;

	b0= (COREWAR_EXEC_MAGIC & 0x000000FF)>>0;
    b1= (COREWAR_EXEC_MAGIC & 0x0000FF00)>>8;
    b2= (COREWAR_EXEC_MAGIC & 0x00FF0000)>>16;
    b3= (COREWAR_EXEC_MAGIC & 0xFF000000)>>24;
   	h->magic = (b0<<24) | (b1<<16) | (b2<<8) | (b3<<0);
   	str[0] = h->magic>>0;
   	str[1] = h->magic>>8;
   	str[2] = h->magic>>16;
   	str[3] = h->magic>>24;
	write(a->fd_cor, &(str), sizeof(COREWAR_EXEC_MAGIC));
}

void 	header_champ(t_asm *a, t_header *h)
{
	char	*line;

	a->count_line = 1;
	header_magic_code(a, h);
	while (get_next_line(a->fd_champ, &line))
	{
		if (*line != COMMENT_CHAR)
			header_parser(line, h, a);
		a->count_line++;
	}
	// char *line;
	// ft_bzero(name, PROG_NAME_LENGTH + 1);
	// ft_strcpy(name,"zork");
	// // write(a->fd_cor, &name, sizeof(name));
	// ft_strcpy(name,"zork");
	// ft_bzero(name + 4, (PROG_NAME_LENGTH + 1) - 4);
	// print_memory(name,PROG_NAME_LENGTH + 1);
	// while (get_next_line(a->fd_champ,&line))
	// {
	// 	ft_printf("{8}%s\n",line);
	// }
}
