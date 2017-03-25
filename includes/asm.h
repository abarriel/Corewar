/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:07:00 by abarriel          #+#    #+#             */
/*   Updated: 2017/03/24 10:18:28 by abarriel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "op.h"
# include "locale.h"
# define SP " \t"
# define ENDLINE "ENDLINE"
# define INSTRUCTION "INSTRUCTION"
# define SEP_CHAR "SEPERATOR CHAR"
# define RID T_REG | T_IND | T_DIR
# define RDI T_REG | T_DIR | T_IND
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
	char 			**label;
	int 			nb_label;
	char			*champ_name;
	int				fd_champ;
	int 			len_line;
	int 			line_;
	int 			line;
	int 			count_line;
	int				fd_cor;
	char			*cor;
}					t_asm;

typedef struct 		s_cmd
{
	char 			*op;
	char 			*args;
	int 			reg;
	int 			nb_struct;
	int 			line;
	int 			colon;
	t_arg_type		*type[MAX_ARGS_NUMBER];
	// struct s_op		*op;
	struct s_cmd 	*next;
}					t_cmd;

typedef struct		s_lab
{
	char 			*label;
	int 			count_line;
	int 			colon;
	int 			line;
	t_cmd 			*cmd;
	struct s_lab	*next;
}					t_lab;
t_op				*get_op(void);
int		skip_space_len(char **s);
void		no_label_error(char *arg, char *str, int line, int character);
void				syntax_error(char *str, int line, int character);
int					check_label_name(char *s);
void				invalid_error(char *str, int nb);
void 				check_operation(t_asm *a, t_lab *l);
void 				print_label(t_lab *lab);
t_lab				*get_label(t_asm *a);
void 				add_back_lab(t_lab **l_t, char *label, t_asm *a);
int 				check_full_space_line(char *str);
void				header_verif_name_comment(char *line, t_asm *a);
void 				length_error(int i);
void 				token_error(char *str, int line, int character);
t_asm				*init_asm(void);
t_header			*init_header(void);
int 				skip_space(char **s);
void 				header_champ(t_asm *a, t_header *h);
void 				lexical_error(int line, int character);

#endif
