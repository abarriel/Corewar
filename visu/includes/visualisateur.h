/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisateur.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcharvol <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 10:13:57 by lcharvol          #+#    #+#             */
/*   Updated: 2017/02/04 10:13:59 by lcharvol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISATEUR_H
# define VISUALISATEUR_H

// # include "../../includes/asm.h"
# include "../../libft/includes/libft.h"
# include "mlx/mlx.h"
# define WIDTH 2000
# define HEIGHT 1250
# define ECHAP	53
# define MAP_SIZE_X	64
# define MAP_SIZE_Y	64

typedef struct		s_env
{
	int 			speed;
	int				pause;
	int				cycle_count;
	struct s_but	*but;
	int				h;
	int				l;
	int				r;
	int				v;
	int				b;
	int				map_size_x;
	int				map_size_y;
	char			*ret;
	void			*ret2;
	void			*win;
	void			*mlx;
	void			*img;
	void			*img2;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_env;

typedef struct		s_but
{
	int				btn1_s;
	int				btn2_s;
	int				btn3_s;
	int				btn4_s;
	int				btn5_s;
	int				btn1_px;
	int				btn2_px;
	int				btn3_px;
	int				btn4_px;
	int				btn5_px;
	int				btn1_py;
	int				btn2_py;
	int				btn3_py;
	int				btn4_py;
	int				btn5_py;
}					t_but;

void				ft_draw_rectangle(int start_x, int start_y, t_env *p);
void				ft_draw_score(t_env *p);
void				ft_draw_menu(t_env *p);
void 				ft_draw_arena(t_env *p);
void				print_text(t_env *p);
void				ft_modif_color(int r, int v, int b, t_env *p);
void				ft_draw(t_env *p);
void				ft_modif_color(int r, int v, int b, t_env *p);
void				ft_draw_square(int start_x, int start_y,
	int size, t_env *p);
void				ft_draw_background(t_env *p);
void				ft_draw_map(t_env *p);

#endif
