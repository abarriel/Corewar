/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:31:31 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/28 04:54:56 by cseccia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H
# include "libft.h"
# include "op.h"
# include "mlx/mlx.h"
# define WIDTH 2000
# define HEIGHT 1250
# define ECHAP  53
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

typedef struct			s_player
{
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
	t_op				*op;
}						t_core;

typedef struct    s_env
{
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
int exec_lld(void *core, void *pro);
void print_map(t_core *core);
int checker_arg(t_core *core, t_process *pro);
int  exec_live(void *core, void *pro);
int exec_add(void *core, void *pro);
void  print_usage(void);
void exec_op(t_core *core, t_process *pro);
size_t              swap_st(size_t val);
unsigned short int  swap_usint(unsigned short int val) ;
short int           swap_sint(short int val);
unsigned int        swap_uint(unsigned int val);
int                 swap_int(int val);
size_t              ft_endian(size_t n);
unsigned long int   chatoli(char **str);
void           init_player(t_player *p, t_core *c);
void					error_executable(void);
t_core					*parcing(int argc, char **argv, t_core *c);
t_core					*new_core();
void					init_core(t_core *core);
t_core					*parcing(int argc, char **argv, t_core *c);

//visu

void run(t_core *core);
static int  ft_loop_key_hook(t_env *p);
int     visu(t_core *c);
void    ft_start_struct(t_env *p, t_but *but);
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
