/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <lcharvol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 03:31:31 by lcharvol          #+#    #+#             */
/*   Updated: 2017/03/26 00:05:33 by abarriel         ###   ########.fr       */
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

typedef struct			s_process
{
	char				       pc;
	int					       cycle_left;
	char				       reg[REG_NUMBER][REG_SIZE];
	char				       carry;
	struct s_process   *next;
}						t_process;

typedef struct			s_player
{
  unsigned int      magic;
  char				      *name;
  size_t		      	weight;
  char					    *comment;
  char					    *prog;
  unsigned char		  id[REG_SIZE];
  int					      last_live;
  int					      nb_live;
  struct s_player		*next;
}						t_player;

typedef struct			s_core
{
  t_process   *process;
  t_player    *player;
  int         visu;
  int	        nb_player;
  char        mem[MEM_SIZE];
  char        mem_c[MEM_SIZE];
  int					cycle;
  int					cycle_sec;
  int					dump;
  char        run;
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

size_t              swap_st(size_t val);
unsigned short int  swap_usint(unsigned short int val) ;
short int           swap_sint(short int val);
unsigned int        swap_uint(unsigned int val);
int                 swap_int(int val);
size_t              ft_endian(size_t n);
unsigned long int   chatoli(char **str);
void           init_player(t_player *p);
void					error_executable(void);
t_core					*parcing(int argc, char **argv, t_core *c);
t_core					*new_core();
void					init_core(t_core *core);
t_core					*parcing(int argc, char **argv, t_core *c);

//visu

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
