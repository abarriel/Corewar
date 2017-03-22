/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:07:00 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/21 08:11:47 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include "locale.h"

typedef struct	s_asm
{
	int 		header_passage;
	char		*champ_name;
	int			fd_champ;
	int 		len_line;
	int 		count_line;
	int			fd_cor;
	char		*cor;
}				t_asm;

int 			check_full_space_line(char *str);
void			header_verif_name_comment(char *line, t_asm *a);
void 			length_error(int i);
void 			syntax_error(char *str, int line, int character);
t_asm			*init_asm(void);
t_header		*init_header(void);
int 			skip_space(char **s);
void 			header_champ(t_asm *a, t_header *h);
void 			lexical_error(int line, int character);

#endif
