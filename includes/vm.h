/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:31:31 by lcharvol          #+#    #+#             */
/*   Updated: 2017/04/19 05:09:16 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"
# include "op.h"
#include <sys/time.h>
#include <time.h>
# include "mlx/mlx.h"
# define WIDTH 2000
# define HEIGHT 1250
# define ECHAP  53
# define SPACE 49
# define LEFT 123
# define RIGHT 124
# define MAP_SIZE_X 64
# define MAP_SIZE_Y 64
# define CYC_SEC_ST 50

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
	int				cde_oct;
	int				l_size;
	int				(*f)(void*, void*);
}					t_op;
extern t_op g_op[17];

typedef struct			s_player
{
	int								color;
  unsigned int      magic;
  char				      *name;
  size_t		      	weight;
  char					    *comment;
  unsigned char			*prog;
  unsigned char		  id[REG_SIZE];
  int					      last_live;
  int					      nb_live;
	int								nb;
  struct s_player		*next;
}						t_player;

typedef struct			s_process
{
	int				       	pc;
	int								life_flag;
	int					       cycle_left;
	t_op							 *op;
	unsigned char			 **reg;
	char				       carry;
	t_player					 *player;
	struct s_process   *next;
}						t_process;

typedef struct			s_core
{
  t_process   *process;
  t_player    *player;
	int         tmp_id;
  int         visu;
  int	        nb_player;
  unsigned char        mem[MEM_SIZE];
  char        mem_c[MEM_SIZE];
  int					cycle;
	int					die_cycle;
	int					last_check;
  int					cycle_sec;
  int					dump;
  char        run;
	int					debug;
	t_op				*op;
}						t_core;

typedef struct    s_env
{
  t_core    *core;
  int       speed;
  int       pause;
  int       cycle_count;
  struct s_but  *but;
  int       h;
  int       l;
  int       r;
  int       v;
  int       b;
  int       map_size_x;
  int       map_size_y;
  char      *ret;
  void      *ret2;
  void      *win;
  void      *mlx;
  void      *img;
  void      *img2;
  int       bits_per_pixel;
  int       size_line;
  int       endian;
}         t_env;

typedef struct    s_but
{
  int       btn1_s;
  int       btn2_s;
  int       btn3_s;
  int       btn4_s;
  int       btn5_s;
  int       btn1_px;
  int       btn2_px;
  int       btn3_px;
  int       btn4_px;
  int       btn5_px;
  int       btn1_py;
  int       btn2_py;
  int       btn3_py;
  int       btn4_py;
  int       btn5_py;
}         t_but;

int size_args(unsigned char oc_cde, int d_size);
unsigned char apply_mask(unsigned char cde, int arg);
unsigned int get_n_arg(t_core *core, t_process *process, int arg, int mod);
void print_map(t_core *core);
int checker_arg(t_core *core, t_process *pro);
int exec_lld(void *core, void *pro);
int  exec_live(void *core, void *pro);
int exec_add(void *core, void *pro);
int exec_sub(void *core, void *pro);
int exec_aff(void *core, void *pro);
int  exec_zjmp(void *core, void *pro);
int  exec_fork(void *core, void *pro);
int  exec_st(void *core, void *pro);
int  exec_sti(void *core, void *pro);
int  exec_and(void *core, void *pro);
int  exec_or(void *core, void *pro);
int  exec_xor(void *core, void *pro);
int  exec_lldi(void *core, void *pro);
int  exec_ld(void *core, void *pro);
int  exec_ldi(void *core, void *pro);
int  exec_lfork(void *core, void *pro);
void  print_usage(void);
void exec_op(t_core *core, t_process *pro);
size_t              ft_endian(size_t n);
unsigned long int   chatoli(char **str);
void           init_player(t_player *p, t_core *c);
void					error_executable(void);
t_core					*parcing(int argc, char **argv, t_core *c);
t_core					*new_core();
void					init_core(t_core *core);
t_core					*parcing(int argc, char **argv, t_core *c);
void        print_player(t_core *core);
void        print_color(t_core *core);
int real_int(unsigned int nb);
int uns_int(int nb);
void        print_winner(t_player *p);
//visu
void        print_nb_live(t_env *p);
void        check_button_hit2(int button, int x, int y, t_env *p);
void        ft_draw_rectangle(int start_x, int start_y, t_env *p);
void        ft_draw_square(int start_x, int start_y, int size, t_env *p);
void        ft_draw_score(t_env *p);
void        ft_draw_map(t_env *p);
void        modif_color_for_player(t_env *p, int i);
void        chose_color_case(t_env *p, int i3);
int         go_visu(t_core *core);
void        print_nb_live(t_env *p);
void        print_player_name(t_env *p);
void        run(t_core *core);
void        run_visu(t_core *core, t_env *p);
static int  ft_loop_key_hook(t_env *p);
int         visu(t_env *p, t_but *but, t_core *c);
void        ft_start_struct(t_env *p, t_but *but);
void        init_but(t_env *p);
void        ft_draw_rectangle(int start_x, int start_y, t_env *p);
void        ft_draw_score(t_env *p);
void        ft_draw_menu(t_env *p);
void        ft_draw_arena(t_env *p);
void        print_text(t_env *p);
void        ft_modif_color(int r, int v, int b, t_env *p);
void        ft_draw(t_env *p);
void        ft_modif_color(int r, int v, int b, t_env *p);
void        ft_draw_square(int start_x, int start_y,
  int size, t_env *p);
void        ft_draw_background(t_env *p);
void        ft_draw_map(t_env *p);

#endif
