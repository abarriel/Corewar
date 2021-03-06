/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarriel <abarriel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/19 06:07:00 by abarriel          #+#    #+#             */
/*   Updated: 2017/04/18 17:58:31 by abarriel         ###   ########.fr       */
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
	char			*mnemonique;
	char			nbr_args;
	char			type[MAX_ARGS_NUMBER];
	char			code;
	int				nbr_cycles;
	char			*comment;
	int				idk;
	int				idk1;
}					t_op;
extern t_op g_op[17];
typedef struct		s_asm
{
	int				header_passage;
	unsigned int	total_bytes;
	char			**label;
	int				nb_label;
	char			*champ_name;
	int				fd_champ;
	int				len_line;
	int				line_;
	int				line;
	int				count_line;
	int				fd_cor;
	char			*cor;
}					t_asm;

typedef struct		s_cmd
{
	char				*op;
	short				bytes;
	short				t_bytes;
	char				*args;
	int					reg;
	int					nb_struct;
	int					line;
	int					colon;
	unsigned char		code;
	unsigned char		r[MAX_ARGS_NUMBER];
	unsigned short int	ind[MAX_ARGS_NUMBER];
	unsigned short int	d2[MAX_ARGS_NUMBER];
	unsigned int		d4[MAX_ARGS_NUMBER];
	char				typs[MAX_ARGS_NUMBER];
	unsigned char		barg;
	t_arg_type			*type[MAX_ARGS_NUMBER];
	struct s_cmd		*next;
}					t_cmd;

typedef struct		s_lab
{
	char			*label;
	short			bytes;
	int				count_line;
	int				colon;
	int				line;
	t_cmd			*cmd;
	struct s_lab	*next;
}					t_lab;
t_op				*get_op(void);
char				*skip_space_ok(char *s);
int					check_first(char c);
void				header_comment(char *line, t_header *h, t_asm *a);
void				header_name(char *line, t_header *h, t_asm *a);
int					header_parser(char *line, t_header *h, t_asm *a);
void				header_magic_code(t_header *h);
void				handles_space(char **s, t_cmd *c);
void				bonus(t_asm *a, t_lab *l, t_header *h);
void				write_op(t_asm *a, t_lab *l);
void				remove_first_label(t_asm *a, t_lab **begin);
char				**add_label(t_lab **l, t_asm *a);
void				get_cmd(t_lab *b, char *s);
int					handles_dir(t_asm *a, char *arg, t_cmd *c);
int					handles_ind(t_asm *a, char *arg, t_cmd *c);
void				check_instructions(t_asm *a, t_cmd *c);
int					skip_space_len(char **s);
void				no_label_error(char *arg, char *str, int line, int cha);
void				syntax_error(char *str, int line, int character);
int					check_label_name(char *s);
void				invalid_error(char *str, int nb);
void				check_operation(t_asm *a, t_lab *l);
void				print_label(t_lab *lab);
t_lab				*get_label(t_asm *a);
void				add_back_lab(t_lab **l_t, char *label, t_asm *a);
int					check_full_space_line(char *str);
void				header_verif_name_comment(char *line, t_asm *a);
void				length_error(int i);
void				token_error(char *str, int line, int character);
t_asm				*init_asm(void);
t_header			*init_header(void);
int					skip_space(char **s);
void				header_champ(t_asm *a, t_header *h);
void				lexical_error(int line, int character);
void				write_label(t_lab *l);
void				final_write(t_asm *a, t_header *h, t_lab *l, char *name);
#endif
