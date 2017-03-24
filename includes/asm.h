/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:07:00 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 03:00:35 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include "locale.h"

typedef struct		s_op
{
   char         	*mnemonique;
   char         	nbr_args;
   char 			type[MAX_ARGS_NUMBER];
   char         	code;
   int          	nbr_cycles;
   char         	*comment;
   int 				idk;
   int 				idk1;
}					t_op;

typedef struct 		s_asm
{
	int 			header_passage;
	char			*champ_name;
	int				fd_champ;
	int 			len_line;
	int 			count_line;
	int				fd_cor;
	char			*cor;
}					t_asm;

typedef struct 		s_cmd
{
	char 			*op;
	char 			*args;
	char 			*type[MAX_ARGS_NUMBER];
	// struct s_op		*op;
	struct s_cmd 	*next;
}					t_cmd;

typedef struct		s_lab
{
	char 			*label;
	int 			count_line;
	t_cmd 			*cmd;
	struct s_lab	*next;
}					t_lab;
t_op				*get_op(void);
void 				print_label(t_lab *lab);
void				get_label(t_asm *a);
void 				add_back_lab(t_lab **l_t, char *label, t_asm *a);
int 				check_full_space_line(char *str);
void				header_verif_name_comment(char *line, t_asm *a);
void 				length_error(int i);
void 				syntax_error(char *str, int line, int character);
t_asm				*init_asm(void);
t_header			*init_header(void);
int 				skip_space(char **s);
void 				header_champ(t_asm *a, t_header *h);
void 				lexical_error(int line, int character);

#endif
